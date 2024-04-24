#lang racket
;(require "circuitism.rkt")
(require "solution.rkt")
;(require "nie.rkt")

#|
(define sim (make-sim))

(define (make-counter n clk en)
  (if (= n 0)
      '()
      (let [(out (make-wire sim))]
        (flip-flop out clk (wire-xor en out))
        (cons out (make-counter (- n 1) clk (wire-and en out))))))

(define clk (make-wire sim))
(define en  (make-wire sim))
(define counter (make-counter 4 clk en))

(wire-set! en #t)

; Kolejne wywołania funkcji tick zwracają wartość licznika
; w kolejnych cyklach zegara. Licznik nie jest resetowany,
; więc początkowa wartość licznika jest trudna do określenia
(define (tick)
  (wire-set! clk #t)
  (sim-wait! sim 20)
  (wire-set! clk #f)
  (sim-wait! sim 20)
  (bus-value counter))|#

; Tworzenie symulacji


; Tworzenie przewodów



; Testowanie flip-flop
(define sim (make-sim))
(define w8 (make-wire sim))
(define w10 (make-wire sim))
(define w9 (make-wire sim))

(flip-flop w10 w8 w9)

(wire-set! w8 #t)
(sim-wait! sim 1)
(wire-set! w8 #f)
(sim-wait! sim 1)

(displayln (wire-value w9)) ; #f


