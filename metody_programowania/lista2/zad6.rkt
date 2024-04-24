#lang racket


(define (maximum xs)
  (define ans -inf.0)
  (define (max ans xs)
    (cond [(and (null? xs) (= ans -inf.0)) -inf.0]
          [(null? xs) ans]
          [(> (car xs) ans) (max (car xs) (cdr xs))]
          [else (max ans (cdr xs))]))
    (max ans xs))



; TESTY ;
(define lista (list 1 2 4 5 6 7 8 9 10))
(maximum lista) ; -> 10

( maximum ( list 1 5 0 7 1 4 1 0) ) ; -> 7

( maximum ( list ) ) ; -> -inf.0
