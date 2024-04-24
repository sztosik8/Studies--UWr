#lang racket

(define (my-compose f g)
  (lambda (x)
    (f (g x))))

(define (square x)
  (* x x))

(define (inc x)
  (+ 1 x))


(require rackunit)

  (check-equal? (( my-compose square inc ) 5 ) 36)
;(5 + 1)^2

  (check-equal? (( my-compose inc square ) 5 ) 26)
;(5^2)+1
  
