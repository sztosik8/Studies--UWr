#lang racket

;; delay and force

(define-syntax-rule
  (stream-cons v s)
  (cons v (delay s)))

(define stream-car car)

(define (stream-cdr s)
  (force (cdr s)))

(define stream-null null)
(define stream-null? null?)

(define ones (stream-cons 1 ones)) ; Strumień zawierający same jedynki

(define (map2 f xs ys)
  (stream-cons
   (f (stream-car xs)
      (stream-car ys))
   (map2 f (stream-cdr xs) (stream-cdr ys))))

(define nats
  (stream-cons 1 (map2 + nats ones))); Strumień zawierający liczby naturalne


(define fac
  (stream-cons 1 (map2 * fac (stream-cdr nats))))

(define (print s n)
  (if (= n 0)
      (void)
      (stream-car s))
      (print (stream-cdr s) (- n 1)))

(print fac 5)

;(define)
 
