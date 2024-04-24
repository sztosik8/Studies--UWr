#lang racket


(define (elem x xs)
  (cond
    ((null? xs) #f)
    ((equal? x (car xs)) #t)
    (else (elem x (cdr xs)))))


( elem 4 ( list 1 2 3) ) ; #t
( elem 2 ( list 1 2 3) ) ; #f

(define lista (list 1 2 4 5 6 7 8 9 10))

(elem 3 lista) ; #f
(elem 7 lista) ; #t