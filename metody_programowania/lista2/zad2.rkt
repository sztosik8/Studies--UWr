#lang racket

(define (fib x)
  (cond [(= x 0) 0]
        [(= x 1) 1]
        [else(+ (fib(- x 1)) (fib(- x 2)))]))

(define (fib-iter n)
  (define (it x y n)
    (if (= n 1) y
        (it y (+ y x) (- n 1) )))
  (it 0 1 n))
        
                 
#| |# -- komentowanie kodu

; testy

"testy (fib x)"
(fib 1) ;-> 1
(fib 2) ;-> 1
(fib 3) ;-> 2
(fib 4) ;-> 3
(fib 5) ;-> 5
(fib 6) ;-> 8
(fib 7) ;-> 13
(fib 8) ;-> 21
(fib 9) ;-> 34

"testy (fib_iter x)"
(fib-iter 1) ;-> 1
(fib-iter 2) ;-> 1
(fib-iter 3) ;-> 2
(fib-iter 4) ;-> 3
(fib-iter 5) ;-> 5
(fib-iter 6) ;-> 8
(fib-iter 7) ;-> 13
(fib-iter 8) ;-> 21
(fib-iter 9) ;-> 34
