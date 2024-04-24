#lang plait

(define-type (Queue 'a)
  (empty-queue)
  (queue (h : 'a) (f : (Listof 'a)) (r : (Listof 'a))))


(define-type (2-3-tree 'a)
  (leaf)
  (2-node [elem : 'a] [l : (2-3-tree 'a)] [r : (2-3-tree 'a)])
  (3-node [elem1 : 'a] [elem2 : 'a] [l : (2-3-tree 'a)][m : (2-3-tree 'a)] [r : (2-3-tree 'a)]))


(define (height t)
  (type-case (2-3-tree 'a) t
    [(leaf) 0]
    [(2-node elem l r)
     (let [(hl (height l ))
           (hr (height r ))]
       (if (and (= hl hr) (not (= hl -1)))
           (+ 1 hl)
           -1))] 
    [(3-node elem1 elem2 l m r)
     (let [(hl (height l ))
           (hm (height m ))
           (hr (height r ))]
       (if (and (= hl hr) (= hm hl) (not (= hl -1)))
           (+ 1 hl) 
           -1))]))

(define (placement t)
  (local [(define (it max min t) 
            (type-case (2-3-tree 'a) t
              [(leaf) #t]
              [(2-node elem l r)
               (and (< min elem) (< elem max) (it elem min l) (it max elem r))]
              [(3-node elem1 elem2 l m r)
               (and (> elem1 elem2) (< elem1 max) (> elem2 min) (it max elem1 r) (it elem2 min l) (it elem1 elem2 m))]))]
    (it +inf.0 -inf.0 t)))


(define (2-3tree? t)
  (and (not(= -1 (height t))) (placement t)))




(define (2-3tree-p? t)
  (placement t))
(define (2-3tree-h? t)
   (not(= -1 (height t))))

(define example-tree
  (3-node 20 10
          (2-node 5
                  (2-node 2 (leaf)(leaf))
                  (2-node 8 (leaf)(leaf)))
          (2-node 15
                  (2-node 12 (leaf)(leaf))
                  (2-node 16 (leaf)(leaf)))
          
          (3-node 40 30
                  (2-node 25 (leaf)(leaf))
                  (2-node 31 (leaf)(leaf))
                  (2-node 60 (leaf)(leaf)))))

(define example-tree1
  (3-node 20 10
          (2-node 5
                  (2-node 2 (leaf)(leaf))
                  (2-node 8 (leaf)(leaf)))
          (2-node 15
                  (2-node 12 (leaf)(leaf))
                  (2-node 16 (leaf)(leaf)))
          
          (3-node 40 30
                  (2-node 25 (leaf)(leaf))
                  (2-node 31 (leaf)(leaf))
                  (leaf))))



(define example-tree2
  (3-node 20 10
          (2-node 5
                  (2-node 2 (leaf)(leaf))
                  (2-node 8 (leaf)(leaf)))
          (2-node 15
                  (2-node 12 (leaf)(leaf))
                  (2-node 13 (leaf)(leaf)))
          
          (3-node 40 30
                  (2-node 25 (leaf)(leaf))
                  (2-node 31 (leaf)(leaf))
                  (2-node 60 (leaf)(leaf)))))

;TESTY

; corrert 
(2-3tree? example-tree) ; -->#t
;(2-3tree-h? example-tree); -->#t
;(2-3tree-p? example-tree); -->#t

(2-3tree? example-tree1)  ; -->#f
;(2-3tree-h? example-tree1) ; -->#t
;(2-3tree-p? example-tree1); -->#f

(2-3tree? example-tree2)  ; -->#f
;(2-3tree-h? example-tree2) ; -->#f
;(2-3tree-p? example-tree2)  ; -->#t
