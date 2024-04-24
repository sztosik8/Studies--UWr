#lang racket

(define (lst-to-mut xs)
  ( cond [(null? xs) null ]
         [ else  (mcons (first xs) (lst-to-mut (cdr xs)))]))

(define (last-pair xs)
  (cond
    [(null? xs) #f]
    [(null? (mcdr xs)) xs]
    [else (last-pair (mcdr xs))]))

(define (cycle! xs)
  (if (null? xs)
      (void)
      (set-mcdr! (last-pair  xs) xs)))


(define xs '(1 2 3 4 5 6 7))
(define xs-mut1 (lst-to-mut xs))

xs-mut1 
(cycle! xs-mut1)
xs-mut1
