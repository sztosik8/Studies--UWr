#lang racket


( parametric->/c [ a b ] (-> a b a ) )
; (-> a - neg  b - neg  a - pos)
( parametric->/c [ a b c ] (-> (-> a b c ) (-> a b ) a c ) )
; (-> (-> a - pos  b - pos  c - neg) (-> a - pos  b - neg) a - neg  c - pos)
( parametric->/c [ a b c ] (-> (-> b c ) (-> a b ) (-> a c ) ) )
; (-> (-> b - pos  c - neg) (-> a - pos  b - neg) (-> a - neg  c - pos))
( parametric->/c [ a ] (-> (-> (-> a a ) a ) a ) )
; (-> (-> (-> a - neg a - pos) a - neg) a - pos)


(define/contract (f1 x y)
  (parametric->/c [ a b ] (-> a b a ) )
   x)

(define/contract (f2 f g x)
  (parametric->/c [a b c] (-> (-> a b c ) (-> a b ) a c ))
  (f x (g x)))

(define/contract (f3 f g )
  ( parametric->/c [a b c] (-> (-> b c ) (-> a b ) (-> a c )))
  (lambda (x) (g (f x))))

(define/contract (f4 f)
  ( parametric->/c [a] (-> (-> (-> a a ) a ) a ))
  (f identity))


(define (f x)
  (* 2 x))
(define (g x)
  (* x x))

(define (h x)
 x)


(f1 '(l, o) 3)
(f2 + g 5) ;(5 + (5 * 5))= 30
(f3 f g) ; x -> (2x)^2
(f4 h)
