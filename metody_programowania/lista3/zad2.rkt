#lang racket

#|  z wykladu
(define (my-foldl f x xs)
  (define (it xs acc)
    (if (null? xs)
        acc
        (it (cdr xs) (f (car xs) acc))))
  (it xs x))

(define (my-sum2 xs)
  (my-foldl + 0 xs))
|#



;; rekursja ogonowa

(define (my-foldl f x xs)
  (define (it xs acc)
    (if (null? xs)
        acc
        (it (cdr xs) (f (car xs) acc))))
  (it xs x))

(define (product xs )
  (my-foldl * 1 xs))


(define xs '(1 2 3 4))


(product xs)
(product '())
; lista pusta zwraca wartosc akumulatora czyli 1










