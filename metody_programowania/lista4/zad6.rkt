#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)



(define (delete x t)
  (define (help w t)
    (cond [(leaf? t) w]
          [(node? t) (node (help w (node-l t))
                           (node-elem t)
                           (node-r t))]))
  (cond [(leaf? t) (leaf)]
        [(node? t)
         (cond [(= x (node-elem t))
                (help (node-l t) (node-r t))]
               [(< x (node-elem t))
                (node (delete x (node-l t))
                      (node-elem t)
                      (node-r t))]
               [else (node (node-l t)
                           (node-elem t)
                           (delete x (node-r t)))])]))