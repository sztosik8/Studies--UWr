#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

; drzewo to:
; - albo (leaf)
; - albo (node l elem r), gdzie l i r to drzewa



(define (bst? t)
  (define (bst t min max)
    (cond [(leaf? t) #t]
          [(and (node? t) ( < (node-elem t ) max ) (> (node-elem t) min))
           (and (bst (node-l t) min (node-elem t))
                (bst (node-r t) (node-elem t) max))]
          [else #f]))   
  (bst t -inf.0 +inf.0))


(define (sum-paths t)
  (define (it t sum)
    (cond [(leaf? t) t ]
          [ else (node ( it (node-l t) (+ sum (node-elem t)))
                       (+ sum (node-elem t) )
                       (it (node-r t) (+ sum (node-elem t))))]))
  (it t 0))


(define t1
   (node
     (node (leaf) 2 (leaf))
     5
     (node (node
             (node (leaf) 6 (leaf))
             7
             (leaf))
           8
            (node (leaf) 9 (leaf)))))


#|
             5
          /     \
       2          8
     /   \      /   \
     L   L     7       9
              / \     / \
             6   L   L   L
            / \
           L   L
|#


(define t2
   (node
     (node (leaf) 9 (leaf))
     5
     (node (node (leaf) 6 (leaf))
            8
            (node (leaf) 2 (leaf)))))
#|
             5
          /     \
       9           8
     /   \       /   \
     L   L     6       2
              / \     / \
             L   L   L   L
|#



(define t3
  (node (leaf) 4 (leaf)))

#|
       4
      / \
     L   L
|#


(define t4
 (leaf))

#|
      L
|#


(require rackunit)


(check-equal? (sum-paths t1) (node (node (leaf) 7 (leaf)) 5 (node (node (node (leaf) 26 (leaf)) 20 (leaf)) 13 (node (leaf) 22 (leaf)))) )
#|
              5
           /     \
        7         13
      /   \     /    \
      L   L    20     22 
              / \     / \
             26  L   L   L
            / \
           L   L
|#


(check-equal? (sum-paths t2) (node (node (leaf) 14 (leaf)) 5 (node (node (leaf) 19 (leaf)) 13 (node (leaf) 15 (leaf)))))
#|
             5
          /     \
       9           8
     /   \       /   \
     L   L     6       2
              / \     / \
             L   L   L   L
|#
 
(check-equal? (sum-paths t3) (node (leaf) 4 (leaf)))
#|
       4
      / \
     L   L
|#


(check-equal? (sum-paths t4) (leaf))
#|
      L
|#



(check-equal? (bst? t1) #t )
(check-equal? (bst? t2) #f )
(check-equal? (bst? t3) #t )
(check-equal? (bst? t4) #t )

