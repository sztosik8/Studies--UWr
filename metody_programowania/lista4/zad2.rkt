#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)



(define (fold-tree f x t)
  (cond [(leaf? t) x]
        [(node? t) (f (fold-tree f x (node-l t))
                      (node-elem t)
                      (fold-tree f x (node-r t)))]))

;; sum
(define (tree-sum t)
  (fold-tree + 0 t ))

;; flip
(define (tree-flip t)
  (fold-tree (lambda (left elem right) (node right elem left)) (leaf) t))

;; height
(define (tree-height t)
    (fold-tree (lambda (left elem right) (+ 1 (max left right))) 0 t))

;;span
(define (tree-span t)
  (cons (fold-tree (lambda (left elem right) (min left elem )) +inf.0 t)
        (fold-tree (lambda (left elem right) (max elem right)) -inf.0 t)))


;; flatten
(define (flatten t)
  ( fold-tree ( lambda (left elem right) (append left (cons elem right ))) '() t))
        


;; TESTY
(define t1
   (node (node (leaf) 2 (leaf)) 5 (node (node (leaf) 6 (leaf)) 8 (node (leaf) 9 (leaf)))))
(define t2
   (node (node (leaf) 2 (leaf)) 5 (node (node (node (leaf) 6 (leaf)) 7 (leaf)) 8 (node (leaf) 9 (leaf)))))
(define t3
  (node (leaf) 4 (leaf)))
(define t4
  (leaf))

 
(require rackunit)

;sum
  (check-equal? (tree-sum t1) 30 )
  (check-equal? (tree-sum t2) 37 )
  (check-equal? (tree-sum t3) 4 )
  (check-equal? (tree-sum t4) 0 )

;flip
 (check-equal? (tree-flip t1) (node (node (node (leaf) 9 (leaf)) 8 (node (leaf) 6 (leaf))) 5 (node (leaf) 2 (leaf))))
 (check-equal? (tree-flip t2) (node (node (node (leaf) 9 (leaf)) 8 (node (leaf) 7 (node (leaf) 6 (leaf)))) 5 (node (leaf) 2 (leaf))))
 (check-equal? (tree-flip t3) (node (leaf) 4 (leaf)))
 (check-equal? (tree-flip t4) (leaf))

;height

 (check-equal? (tree-height t1) 3)
 (check-equal? (tree-height t2) 4)
 (check-equal? (tree-height t3) 1)
 (check-equal? (tree-height t4) 0)

;span

(check-equal? (tree-span t1) '(2.0 . 9.0))
(check-equal? (tree-span t2) '(2.0 . 9.0))
(check-equal? (tree-span t3) '(4.0 . 4.0))
(check-equal? (tree-span t4) '(+inf.0 . -inf.0))

;flatten
(check-equal? (flatten t1) '(2 5 6 8 9))
(check-equal? (flatten t2) '(2 5 6 7 8 9))
(check-equal? (flatten t3) '(4))
(check-equal? (flatten t4) '())
