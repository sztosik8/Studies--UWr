#lang racket

(define x 3)
(define y 3)
(define z 3)


( let ([ x 3])  ; x zwiazana
   (+ x y ) )   ; y wolna


( let ([ x 1]  ; x zwiazana
       [ y (+ x 2) ]) ; y zwiazana
   (+ x y ) )


( let ([ x 1])   ; x zwiazana
   ( let ([ y (+ x 2) ])  ; y zwiazana
      (* x y ) ) )


( define ( f x y ) ; x zwiazana   y zwiazana
   (* x y z ) )    ; z wolna


#;( define ( f x )  ; f zwiazana
   ( define ( g y z )  ; y zwiazana  z zwiazana
      (* x y z ) )
   ( f x x x ) )




(define/contract (positive f num)
  (parametric->/c [a b] (-> (-> a b ) a b))
  (f num))
(positive number->string 3)

(positive (lambda (x) (if (> x 0)
                          "positive"
                          "not positive")) 0)







(define/contract (my-map1 fs xs)
  (parametric->/c [a b] (-> (listof (-> a b)) (listof a) ( listof b)))
  (append (map (car fs) xs)(map (car (cdr fs )) xs)))


(define/contract (my-map2 fs xs)
  (parametric->/c [a b] (-> (listof (-> a b)) (listof a) ( listof b)))
  (map (car fs) xs))


(define (fu x)
  (if (> x 3)
      #t
      #f))

(define (g x)
  (if (< x 10)
      #t
      #f))

(my-map1 (list fu g) '(1 3 4 15))
(my-map2 (list fu g) '(1 3 4 15))



(define (f4 f x)
  (parametric->/c [a b] (-> (-> b ( or/c false/c ( cons/c a b))) b (listof a)))
  (if(f x)
     (cons (car (f x)) (f4 (cdr (f x))))
     null))

(define (f5 f xs)
  (parametric->/c [a] (-> (-> a boolean?) ( listof a) ( cons/c ( listof a) ( listof a))))
  (define (help)
    (if (f xs)
        null
        (cons (car xs) (f5 f (cdr xs)))))
  (cons (help) (help)))




