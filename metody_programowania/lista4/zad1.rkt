#lang racket
(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

(define t1
   (node
     (node (leaf) 2 (leaf))
     5
     (node (node (leaf) 6 (leaf))
            8
            (node (leaf) 9 (leaf)))))

#|
             5
          /     \
        2         8
      /   \     /   \
      L   L    6      9
              / \    / \
             L   L  L   L
|#



(define t2
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
        2         8
      /   \     /   \
      L   L   6       9
             / \     / \
            L   7   L   L
               / \
              L   L
|#