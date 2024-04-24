#lang racket

(define (square x)
  (* x x))

(define (divides? a b)
  (= (remainder b a) 0))

(define-syntax-rule
  (stream-cons v s)
  (cons v (delay s)))

(define stream-car car)

(define (stream-cdr s)
  (force (cdr s)))

(define stream-null null)
(define stream-null? null?)


;; infinite streams

(define ones (stream-cons 1 ones))

(define (integers-from n)
  (stream-cons n (integers-from (+ n 1))))

(define (stream-filter p s)
  (if (stream-null? s)
      stream-null
      (if (p (stream-car s))
          (stream-cons (stream-car s)
                       (stream-filter p (stream-cdr s)))
          (stream-filter p (stream-cdr s)))))


; zad2
(define (check-if-prime n)
  (define (check-if-prime-helper n s)
    (cond
      [(> (square (stream-car s)) n) #t]
      [(divides? (stream-car s) n) #f]
      [else (check-if-prime-helper n (stream-cdr s))]))
  (check-if-prime-helper n primes))

(define primes
  (stream-cons
   2
   (stream-filter check-if-prime (integers-from 3))))



;; combining (infinite) streams 

(define (map2 f xs ys)
  (stream-cons
   (f (stream-car xs)
      (stream-car ys))
   (map2 f (stream-cdr xs) (stream-cdr ys))))

(define nats2 (stream-cons 0 (map2 + nats2 ones)))

#|
nats2    0 1 2 ...
ones     1 1 1 ...
---------------------------------------
nats2  0 1 2 3 ...
|#

(define fibs
  (stream-cons 0 (stream-cons 1 (map2 + fibs (stream-cdr fibs)))))

; zad3
(define fact
  (stream-cons 1 (map2 * (integers-from 1) fact)))
; nat.     1   2   3   4   5   
; fact.    1 . 1   2   6   24 ...

; zad4
(define (partial-sums s)
  (stream-cons
   (stream-car s)
   (map2 + (stream-cdr s) (partial-sums s))))

#|
S             a  b    c      d  ...  
part-sum      a a+b a+b+c a+b+c+d  ...
-----------------------------------------


|#

; zad5

(define (merge s1 s2)
  (cond
    [(= (stream-car s1) (stream-car s2))
     (stream-cons
      (stream-car s1)
      (merge
       (stream-cdr s1)
       (stream-cdr s2)))]
    [(< (stream-car s1) (stream-car s2))
     (stream-cons  
      (stream-car s1)
      (merge
       (stream-cdr s1)
       s2))]
    [else
     (stream-cons
      (stream-car s2)
      (merge
       s1
       (stream-cdr s2)))]))

(define (scale s t)
  (stream-cons
   (* (stream-car s) t)
   (scale (stream-cdr s) t)))

(define _hamming
  (stream-cons
   1
   (merge
    (scale _hamming 2)
    (merge
     (scale _hamming 3)
     (scale _hamming 5)))))

; scale 2  1 2  4  8  16
; scale 3  3 6 12 24  48
;           9 18 27 36
; scale 5  5 10 20 40
;         15 30 60
;          25 50

(define hamming
  (stream-cdr _hamming))

; generate
(define (stream-gen s n)
  (if (= n 0)
      stream-null
      (cons (stream-car s)
            (stream-gen (stream-cdr s) (- n 1)))))

(stream-gen fact 10)
(stream-gen hamming 20)
;(stream-gen primes 20)