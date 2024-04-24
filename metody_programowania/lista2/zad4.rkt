#lang racket

(define-struct matrix (a b c d) #:transparent)


; mnozenie macierzy 2x2
(define (matrix-mult m1 m2)
  (define a1 (matrix-a m1))
  (define b1 (matrix-b m1))
  (define c1 (matrix-c m1))
  (define d1 (matrix-d m1))

  (define a2 (matrix-a m2))
  (define b2 (matrix-b m2))
  (define c2 (matrix-c m2))
  (define d2 (matrix-d m2))

  (make-matrix (+ (* a1 a2 ) (* b1 c2)) (+ (* a1 b2) (* b1 d2)) (+ (* c1 a2) (* d1 c2)) (+ (* c1 b2) (* d1 d2))))

  
; Szybkie potęgowanie macierzy 2x2
(define (matrix-expt-fast m k)
  (define ans (make-matrix 1 0 0 1))
  (define (fast m k ans)
    (if (= k 0) ans
        (if (= 1 (modulo k 2))
            (fast (matrix-mult m m) (floor (/ k 2)) (matrix-mult ans m))
            (fast (matrix-mult m m) (floor (/ k 2)) ans))))
  (fast m k ans))
  



; szuaknie liczb fibonacciego przy pomocy macierzy
(define (matrix-fib k) 
  (define m (make-matrix 1 1 1 0))
  (define m3 (matrix-expt-fast m k))
  (define ans (matrix-b m3))
  ans) 



(define m1 (make-matrix 1 2 3 4))

; TESTY ;
" do potegi 0" ; (1 0 0 1)
(matrix-expt-fast m1 0)
" do potegi 1" ; (1 2 3 4) 
(matrix-expt-fast m1 1)
" do potegi 2" ; (7 10 15 22)
(matrix-expt-fast m1 2)
" do potegi 3" ; (37 54 81 118)
(matrix-expt-fast m1 3)
" do potegi 4" ; (199290 435 634)
(matrix-expt-fast m1 4)

"fibonacci"
(matrix-fib 1) ;-> 1
(matrix-fib 2) ;-> 1
(matrix-fib 3) ;-> 2
(matrix-fib 4) ;-> 3
(matrix-fib 5) ;-> 5
(matrix-fib 6) ;-> 8
(matrix-fib 7) ;-> 13
(matrix-fib 8) ;-> 21
(matrix-fib 9) ;-> 34



  