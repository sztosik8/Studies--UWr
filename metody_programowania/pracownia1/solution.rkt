#lang racket

(provide (struct-out column-info)
         (struct-out table)
         (struct-out and-f)
         (struct-out or-f)
         (struct-out not-f)
         (struct-out eq-f)
         (struct-out eq2-f)
         (struct-out lt-f)
         table-insert
         table-project
         table-sort
         table-select
         table-rename
         table-cross-join
         table-natural-join)
         

(define-struct column-info (name type) #:transparent)

(define-struct table (schema rows) #:transparent)

(define cities
  (table
   (list (column-info 'city    'string)
         (column-info 'country 'string)
         (column-info 'area    'number)
         (column-info 'capital 'boolean))
   (list (list "Wrocław" "Poland"  293 #f)
         (list "Warsaw"  "Poland"  517 #t)
         (list "Poznań"  "Poland"  262 #f)
         (list "Berlin"  "Germany" 892 #t)
         (list "Munich"  "Germany" 310 #f)
         (list "Paris"   "France"  105 #t)
         (list "Rennes"  "France"   50 #f))))

(define countries
  (table
   (list (column-info 'country 'string)
         (column-info 'population 'number))
   (list (list "Poland" 38)
         (list "Germany" 83)
         (list "France" 67)
         (list "Spain" 47))))

(define (empty-table columns) (table columns '()))

; Wstawianie
 
(define (table-insert row tab)
  (define (prop? row col) ; proper?
    (cond
      [(null? row) (null? col)] ; sprawdza czy ten sam rozmiar
      [(null? col) (null? row)]
      [else (and
             (cond
               [(equal? (column-info-type (car col)) 'string) (string? (car row))]
               [(equal? (column-info-type (car col)) 'number) (number? (car row))]
               [(equal? (column-info-type (car col)) 'symbol) (symbol? (car row))]
               [(equal? (column-info-type (car col)) 'boolean) (boolean? (car row))])
             (prop? (cdr row) (cdr col)))]))  ; sprawdza typy
  (if (prop? row (table-schema tab))
      (table (table-schema tab) (cons row (table-rows tab)))
      (error 'table-insert "invalid row!")))
  

;(table-insert '("Paris" "France" 105 #t) cities)


 
; Projekcja


(define (num_of_col name tab) ; liczy ktora z kolei jest kolumna o nazwie name w tablicy tab
  (define (it col acc)
    (if (equal? (column-info-name (car col)) name )
        acc
        (it  (cdr col) (+ 1 acc))))
  (it (table-schema tab) 0))


(define (list-of-nums-of-cols cols tab ) ; tworzy liste z numerami kolumn ktore beda wypisywane
  (define (it cols)
    ( if (null? cols)
         null 
         (cons (num_of_col (car cols) tab)
               (it (cdr cols)))))
  (it cols))


(define (table-project cols tab)
  
  ( define list (list-of-nums-of-cols cols tab)) ; lista z numerami kolumn ktore beda wypisywane

  (define (take-from-row row lst) ; zwraca wartości z wierszy z odpowiednich kolumn (z lst)
    (if (null? lst)
        null
        (cons (list-ref row (car lst)) (take-from-row row (cdr lst)))))

  (define (take-from-all-rows rows) ; zwraca listę list gdzie kazda podlista zawiera wartości odpowiednich kolumn dla danego wiersza
    (if (null? rows)
        null
        (cons (take-from-row (car rows) list)
              (take-from-all-rows (cdr rows)))))

  (define (make-schema cols lst) ; wyodrebnia kolumny ktore beda wyswietlone i tworzy liste ich nazw 
    (if (null? lst)
        null
        (cons (list-ref cols (car lst)) (make-schema cols (cdr lst)))))
  
  (table (make-schema (table-schema tab) list) (take-from-all-rows (table-rows tab))))
   

;(table-project '( city country ) cities )


; Sortowanie

(define (table-sort cols tab)

  tab
  )

; Selekcja


( define-struct and-f (l r))       ; koniunkcja formuł
( define-struct or-f (l r))        ; dysjunkcja formuł
( define-struct not-f (e))         ; negacja formuły
( define-struct eq-f (name val)  ) ; wartość kolumny name równa val
( define-struct eq2-f (name name2)) ; wartości kolumn name i name2 równe
( define-struct lt-f (name val))   ; wartość kolumny name mniejsza niż val

(define (table-select form tab)
  (define (<? val1 val2 type) ; funkcja sprawsza czy val1 < val2 (uwzglednia typy)
    (cond
      [(equal? type 'number) (< val1 val2)]
      [(equal? type 'string) (string<? val1 val2)]
      [(equal? type 'symbol) (symbol<? val1 val2)]
      [(equal? type 'boolean) (if val1 #f val2)]))
    
  (define (check row f) ; sprawdza poprawnosc formuly dla kazdego wiersza
    (cond
      [(and-f? f) (and (check row (and-f-l f)) (check row (and-f-r f)))]
      [(or-f? f) (or (check row (or-f-l f)) (check row (or-f-r f)))]
      [(not-f? f) (not (check row (not-f-e f)))]
      [(eq-f? f)
       (let [(num (num_of_col (eq-f-name f) tab))]
         (equal? (list-ref row num) (eq-f-val f)))]
      [(eq2-f? f)
       (let [(num1 (num_of_col (eq2-f-name f) tab))
             (num2 (num_of_col (eq2-f-name2 f) tab))]
         (equal? (list-ref row num1) (list-ref row num2)))]
      [(lt-f? f)
       (let [(num (num_of_col (lt-f-name f) tab))]
         (<? (list-ref row num) (lt-f-val f)
             (column-info-type (list-ref (table-schema tab) num))))]))

  (table (table-schema tab)
         (filter (lambda (x) (check x form)) (table-rows tab))))

;( table-rows ( table-select ( and-f ( eq-f 'capital #t )
 ;                                   ( not-f ( lt-f 'area 300) ) ) cities ) )

; Zmiana nazwy

(define (table-rename col ncol tab)
  (define ( help  tabl)
    (if (null? tabl)
        null
        (if (equal? (column-info-name (car tabl)) col )
            (cons (column-info ncol (column-info-type (car tabl))) (help (cdr tabl)))
            (cond (car tabl) (help (cdr tabl))))))
  (table (help (table-schema tab)) (table-rows tab)))

;( table-rename 'city 'name cities )


; Złączenie kartezjańskie

(define (table-cross-join tab1 tab2)
  (define (make-rows rows1 rows2) ; laczy wiersze
    (cond
      [(null? rows1) null]
      [(null? rows2) (make-rows (cdr rows1) (table-rows tab2))]
      [else (cons (append (car rows1) (car rows2)) (make-rows rows1 (cdr rows2)))]))
  
  (table (append (table-schema tab1) (table-schema tab2))
         (make-rows (table-rows tab1) (table-rows tab2))))

; Złączenie

(define (table-natural-join tab1 tab2)
  tab1)
