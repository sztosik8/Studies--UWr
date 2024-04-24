#lang racket

( define ( foldr-reverse xs )
( foldr ( lambda ( y ys ) ( append ys ( list y ) ) ) null xs ) )



#|
(define (my-foldl f x xs)
  (define (it xs acc)
    (if (null? xs)
        acc
        (it (cdr xs) (f (car xs) acc))))
  (it xs x))
|#

#|
(define (my-foldr f x xs)
  (if (null? xs)
      x
      (f (car xs) (my-foldr f x (cdr xs)))))
|#