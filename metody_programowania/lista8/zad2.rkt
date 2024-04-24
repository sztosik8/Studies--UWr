#lang racket

(define (lst-to-mut xs)
  ( cond [(null? xs) null ]
         [ else  (mcons (first xs) (lst-to-mut (cdr xs)))]))


(define (mreverse! xs)
  (cond
    [(or (null? xs) (null? (mcdr xs))) xs]
    [else
     (let ([res (mreverse! (mcdr xs))] )
       (set-mcdr! (mcdr xs) xs)
       (set-mcdr! xs '())
       ; res
       )]))



(define xs '(1 2 3 4 5 6 7))
(define xs-mut (lst-to-mut xs))

xs-mut
(mreverse! xs-mut)
