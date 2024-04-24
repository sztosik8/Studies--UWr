#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

#| z wykladu

(define (insert-bst x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond [(= x (node-elem t)) t]       usunac warunek
                [(< x (node-elem t))         
                 (node (insert-bst x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [else
                 (node (node-l t)
                       (node-elem t)
                       (insert-bst x (node-r t)))])]))
|#

; insert
(define (insert-bst x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond
                [(< x (node-elem t))
                 (node (insert-bst x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [else
                 (node (node-l t)
                       (node-elem t)
                       (insert-bst x (node-r t)))])]))
;; fold-tree
(define (fold-tree f x t)
  (cond [(leaf? t) x]
        [(node? t) (f (fold-tree f x (node-l t))
                      (node-elem t)
                      (fold-tree f x (node-r t)))]))
;; flatten
(define (flatten t)
  ( fold-tree ( lambda (left elem right) (append left (list elem) right )) '() t))

;; treesort
(define (treesort xs)
  (define (it xs bst)
    (if (null? xs)
        bst
        (it (cdr xs) (insert-bst (car xs) bst))))
  (flatten (it xs (leaf))))



;; TESTY

(define t2
   (node (node (leaf) 2 (leaf)) 5 (node (node (node (leaf) 6 (leaf)) 7 (leaf)) 8  (node (leaf) 9 (leaf)))))

(require rackunit)

( check-equal? (insert-bst 5 t2) (node (node (leaf) 2 (node (leaf) 5 (leaf))) 5 (node (node (node (leaf) 6 (leaf)) 7 (leaf)) 8 (node (leaf) 9 (leaf)))))

(define xs1 '( 1 10 2 6))
(define xs2 '( 1 3 56 6 3 3))
(define xs3 '( 1 ))
(define xs4 '())



( check-equal? (treesort xs1) '(1 2 6 10))
( check-equal? (treesort xs2) '(1 3 3 3 6 56))
( check-equal? (treesort xs3) '(1))
( check-equal? (treesort xs4) '())


