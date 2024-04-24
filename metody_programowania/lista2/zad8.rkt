#lang racket

(define (sorted? xs)
  (cond [(null? xs) true]
        [(and (not(null? (cdr xs))) (>(car xs)(car (cdr xs)))) false]
        [else (sorted? (cdr xs))]))


(sorted? (list 2 6 7 )) ; -> #t
(sorted? (list 7 7 7 )) ; -> #t
(sorted? (list 2))  ;  --> #t

(sorted? (list 2 6 4 7 )) ; -> #f
(sorted? (list 1 3 3 2 3 )) ; -> #f