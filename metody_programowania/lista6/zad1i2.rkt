#lang plait

; ZAD 1

(define (my-map f xs)
  (if (empty? xs)
      empty
      (cons (f (first xs))
            (my-map f (rest xs)))))

; ZAD 2

( define ( append xs ys )
   (if ( empty? xs )
       ys
       ( cons ( first xs ) ( append ( rest xs ) ys ) ) ) )