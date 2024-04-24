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



; tworzenie macierzy identycznosciowej 
(define (matrix-id m)
  (define a (matrix-a m))
  (define b (matrix-b m))
  (define c (matrix-c m))
  (define d (matrix-d m))
  (define s (/ 1 (- (* a d) (* b c))))

  (make-matrix (* s d) (* s -1 b) (* s -1 c) (* s a)))


; potegowanie macierzy iteracyjnie
(define (matrix-expt-iter m k)
  (define (iter m k ans)
    (if (= k 0) ans (iter m (- k 1) (matrix-mult m ans))))
  (iter m k (matrix 1 0 0 1)))



; potegowanie macierzy rekurencyjnie
(define (matrix-expt-rek m k)
  (cond [(= k 0) (matrix 1 0 0 1)]
        [else (matrix-mult m (matrix-expt-rek m (- k 1)))]))



; szuaknie liczb fibonacciego przy pomocy macierzy
(define (matrix-fib k) 
  (define m (make-matrix 1 1 1 0))
  (define m3 (matrix-expt-iter m k))
  (define ans (matrix-b m3))
  ans) 



;; TESTY ;;

#|

(define m1 (make-matrix 1 2 3 4))
(define m2 (make-matrix 5 6 7 8))

"mnozenie m1 i m2"
(matrix-mult m1 m2) ; -> (19 22 43 50)

"macierz identycznosciowa do m1"
(define m3 (matrix-id m1))
m1
"sprawdzenie czy identycznosciowa"
(matrix-mult m3 m1)


" do potegi 0" ; (1 0 0 1)
(matrix-expt-iter m1 0)
" do potegi 1" ; (1 2 3 4)
(matrix-expt-iter m1 1)
" do potegi 2" ; (7 10 15 22)
(matrix-expt-iter m1 2)
" do potegi 3" ; (37 54 81 118)
(matrix-expt-iter m1 3)

" "

" do potegi 0" ; (1 0 0 1)
(matrix-expt-rek m1 0)
" do potegi 1" ; (1 2 3 4)
(matrix-expt-rek m1 1)
" do potegi 2" ; (7 10 15 22)
(matrix-expt-rek m1 2)
" do potegi 3" ; (37 54 81 118)
(matrix-expt-rek m1 3)

"fibonacci"
(matrix-fib 1) ;-> 1
(matrix-fib 2) ;-> 1
(matrix-fib 3) ;-> 2
(matrix-fib 4) ;-> 3
(matrix-fib 5) ;-> 5
(matrix-fib 6) ;-> 8
(matrix-fib 7) ;-> 13
(matrix-fib 8) ;-> 21
(matrix-fib 9) ;-> 34|#




  
