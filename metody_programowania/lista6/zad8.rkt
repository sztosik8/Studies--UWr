#lang plait

(define (<=? x xs)
  (if (empty? xs) #t
      (<= x (first xs))))

(define (sorted? xs)
    (if (empty? xs)
        #t
        (and (<=?(first xs) (rest xs))
             (sorted? (rest xs)))))

(define (insert x xs)
  (cond [(empty? xs) (cons x empty)]
        [(<= x (first xs)) (cons x xs)]
        [else (cons (first xs) (insert x (rest xs)))]))
      



(define xs '(1 2 3 4 5 5 7 8))
(sorted? xs)


(insert 6 xs)
(sorted? xs)




