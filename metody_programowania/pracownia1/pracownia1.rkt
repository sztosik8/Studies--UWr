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
         ;table-project
         ;table-sort
         ;table-select
         ;table-rename
         ;table-cross-join
         ;table-natural-join)
         )

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
    (cond [(null? row) (null? col)] ; sprawdza czy ten sam rozmiar
          [(null? col) (null? row)]
          [else (and
                 (cond [(equal? (column-info-type (car col)) 'string) (string? (car row))]
                       [(equal? (column-info-type (car col)) 'number) (number? (car row))]
                       [(equal? (column-info-type (car col)) 'symbol) (symbol? (car row))]
                       [(equal? (column-info-type (car col)) 'boolean) (boolean? (car row))])
                 (prop? (cdr row) (cdr col)))]))  ; sprawdza typy
  (if (prop? row (table-schema tab))
      (table (table-schema tab) (cons row (table-rows tab)))
      (error 'table-insert "invalid row!")))
  


#|

(table-insert '("Paris" "France" 105 #t) cities)

(define rrow1 '("Palalalalal" "France" 105 #t))
(define rrow2 '("OPOLE" "FrOLAND" 15 #f))

(table-insert rrow1 cities)
(table-insert rrow2 cities)

|#
 
; Projekcja


(define (num_of_col name tab)
  (define (it col acc)
      (if (equal? (column-info-name (car col)) name )
          acc
          (it  (cdr col) (+ 1 acc))))
  (it (table-schema tab) 0))


(define (list-of-nums-of-cols cols tab )
  (define (it cols)
    ( if (null? cols)
         null 
         (cons (num_of_col (car cols) tab)
               (it (cdr cols)))))
  (it cols))


(define (table-project cols tab)
  
  ( define list (list-of-nums-of-cols cols tab))

  (define (take-row row lst)
    (if (null? lst)
        null
        (cons (list-ref row (car lst)) (take-row row (cdr lst)))))

  (define (take-all-rows rows)
    (if (null? rows)
        null
        (cons (take-row (car rows) list)
              (take-all-rows (cdr rows)))))

  (define (make-schema cols lst)
    (if (null? lst)
        null
        (cons (list-ref cols (car lst)) (make-schema cols (cdr lst)))))
  
  (table (make-schema (table-schema tab) list) (take-all-rows (table-rows tab))))
   

 ;(table-project '( city country ) cities )


; Sortowanie

;'(define (table-sort cols tab)
  ;; uzupełnij
;  )

; Selekcja

(define-struct and-f (l r))
(define-struct or-f (l r))
(define-struct not-f (e))
(define-struct eq-f (name val))
(define-struct eq2-f (name name2))
(define-struct lt-f (name val))

(define cl (column-info 'eqwe 'string))

;(define (table-select form tab)
  ;; uzupełnij
;  )

; Zmiana nazwy

(define (table-rename col ncol tab)
  (define ( help  tabl)
    (if (null? tabl)
        null
        (if (equal? (column-info-name (car tabl)) col )
            (cons (column-info ncol (column-info-type (car tabl))) (help (cdr tabl)))
            (cond (car tabl) (help (cdr tabl))))))
  (table (help (table-schema tab)) (table-rows tab)))

 ( table-rename 'city 'name cities )


; Złączenie kartezjańskie

;(define (table-cross-join tab1 tab2)
  ;; uzupełnij
;  )

; Złączenie

;(define (table-natural-join tab1 tab2)
  ;; uzupełnij
;  )
