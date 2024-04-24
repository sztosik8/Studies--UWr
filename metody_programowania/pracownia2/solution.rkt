#lang racket

(require data/heap)
(provide sim? wire?
         (contract-out
          [make-sim        (-> sim?)]
          [sim-wait!       (-> sim? positive? void?)]
          [sim-time        (-> sim? real?)]
          [sim-add-action! (-> sim? positive? (-> any/c) void?)]

          [make-wire       (-> sim? wire?)]
          [wire-on-change! (-> wire? (-> any/c) void?)]
          [wire-value      (-> wire? boolean?)]
          [wire-set!       (-> wire? boolean? void?)]

          [bus-value (-> (listof wire?) natural?)]
          [bus-set!  (-> (listof wire?) natural? void?)]

          [gate-not  (-> wire? wire? void?)]
          [gate-and  (-> wire? wire? wire? void?)]
          [gate-nand (-> wire? wire? wire? void?)]
          [gate-or   (-> wire? wire? wire? void?)]
          [gate-nor  (-> wire? wire? wire? void?)]
          [gate-xor  (-> wire? wire? wire? void?)]

          [wire-not  (-> wire? wire?)]
          [wire-and  (-> wire? wire? wire?)]
          [wire-nand (-> wire? wire? wire?)]
          [wire-or   (-> wire? wire? wire?)]
          [wire-nor  (-> wire? wire? wire?)]
          [wire-xor  (-> wire? wire? wire?)]

          [flip-flop (-> wire? wire? wire? void?)]))

; ---- SIMULATION---

; symulacja
(struct sim ([time #:mutable] [queue #:mutable]))

; konstruktor symulacji
(define (make-sim)
  (sim 0
       (make-heap (lambda (x y)
                    (< (car x) (car y)))))) ; kolejka(czas, akcja)

; uruchomienie symulacji
(define (sim-wait! sim time)
  (define end-time (+ (sim-time sim) time))
  (define (it)
    (cond [(= (heap-count (sim-queue sim)) 0) (void)] ;; brak akcji
          [(> (car (heap-min (sim-queue sim))) end-time) (void)] ; nastepna akcja po danym czasie
          [else
           (let [(next-event (heap-min (sim-queue sim)))]
             (begin
               (heap-remove-min! (sim-queue sim))   ; usuwamy akcję
               (set-sim-time! sim (car next-event)) ; przesuwamy czas
               ((cdr next-event))                   ; wywołanie akcji
               (it)))]))
  (it)
  (set-sim-time! sim end-time))

; dodanie akcji
(define (sim-add-action! sim time action)
  (heap-add! (sim-queue sim)
             (cons (+ (sim-time sim) time) action)))


;------  WIRE  ------

; przewody
(struct wire ([value #:mutable] [actions #:mutable] sim ))

; konstruktor przewodu
(define (make-wire sim)
  (wire #f null sim))

; dodanie akcji (wykonywanej przy zmianie stanu)
(define (wire-on-change! wire action)
  (set-wire-actions! wire (cons action (wire-actions wire)))
  (action))

; ustawienie wartosci
(define (wire-set! wire value)
  (if (equal? (wire-value wire) value)
      (void) ; bez zmian
      (begin
        (set-wire-value! wire value)
        (call-wire-actions wire))))

; wywolanie akcji
(define (call-wire-actions wire)
  (define (it actions)
    (if (null? actions)
        (void)
        (begin
          ((car actions))
          (it (cdr actions)))))
  (it (wire-actions wire)))


; opoznienie bramek logicznych
(define not-delay  1)
(define and-delay  1)
(define nand-delay 1)
(define or-delay   1)
(define nor-delay  1)
(define xor-delay  2)


;  wartosc logiczna sygnalow
(define (logical-not s)
  (not s))

(define (logical-and s1 s2)
  (and s1 s2))

(define (logical-nand s1 s2)
  (logical-not (logical-and s1 s2)))

(define (logical-or s1 s2)
  (or s1 s2))

(define (logical-nor s1 s2)
  (logical-not (logical-or s1 s2)))

(define (logical-xor s1 s2)
  (cond
    [(and (eq? #t s1) (eq? #f s2)) #t]
    [(and (eq? #f s1) (eq? #t s2)) #t]
    [else #f]))

(module+ test
  (require rackunit)

  ; Testy dla funkcji logical-not
  (check-equal? (logical-not #t) #f)
  (check-equal? (logical-not #f) #t)

  ; Testy dla funkcji logical-and
  (check-equal? (logical-and #t #t) #t)
  (check-equal? (logical-and #t #f) #f)

  ; Testy dla funkcji logical-nand
  (check-equal? (logical-nand #t #t) #f)
  (check-equal? (logical-nand #t #f) #t)

  ; Testy dla funkcji logical-or
  (check-equal? (logical-or #f #t) #t)
  (check-equal? (logical-or #f #f) #f)

  ; Testy dla funkcji logical-nor
  (check-equal? (logical-nor #t #t) #f)
  (check-equal? (logical-nor #t #f) #f)
  (check-equal? (logical-nor #f #t) #f)

  ; Testy dla funkcji logical-xor
  (check-equal? (logical-xor #t #t) #f)
  (check-equal? (logical-xor #t #f) #t)
  )

;-------------------   GATES

(define (gate-not a output)
  (define (not-action)
    (after-delay 
     (wire-sim output)
     not-delay
     (lambda ()
       (wire-set! output (logical-not (wire-value a))))))
  (wire-on-change! a not-action)
  (not-action))

(define (gate-and output a1 a2)
  (define (and-action)
    (after-delay 
     (wire-sim output)
     and-delay
     (lambda ()
       (wire-set! output (logical-and (wire-value a1) (wire-value a2))))))
  (wire-on-change! a1 and-action)
  (wire-on-change! a2 and-action)
  (and-action))

(define (gate-nand output a1 a2)
  (define (nand-action)
    (after-delay 
     (wire-sim output)
     nand-delay
     (lambda ()
       (wire-set! output (logical-nand (wire-value a1) (wire-value a2))))))
  (wire-on-change! a1 nand-action)
  (wire-on-change! a2 nand-action)
  (nand-action))

(define (gate-or output a1 a2)
  (define (or-action)
    (after-delay 
     (wire-sim output)
     or-delay
     (lambda ()
       (wire-set! output (logical-or (wire-value a1) (wire-value a2))))))
  (wire-on-change! a1 or-action)
  (wire-on-change! a2 or-action)
  (or-action))

(define (gate-nor output a1 a2) 
  (define (nor-action)
    (after-delay 
     (wire-sim output)
     nor-delay
     (lambda ()
       (wire-set! output (logical-nor (wire-value a1) (wire-value a2))))))
  (wire-on-change! a1 nor-action)
  (wire-on-change! a2 nor-action)
  (nor-action))

(define (gate-xor output a1 a2)
  (define (xor-action)
    (after-delay 
     (wire-sim output)
     xor-delay
     (lambda ()
       (wire-set! output (logical-xor (wire-value a1) (wire-value a2))))))
  (wire-on-change! a1 xor-action)
  (wire-on-change! a2 xor-action)
  (xor-action))

(define (after-delay sim delay action)
  (sim-add-action! sim delay action))
;-------------------------------------

;;;;

(define (wire-not a) 
  (let ((output (make-wire (wire-sim a))))
    (gate-not output a)
    output))

(define (wire-and a1 a2)
  (let ((output (make-wire (wire-sim a1))))
    (gate-and output a1 a2)
    output))

(define (wire-nand a1 a2)
  (let ((output (make-wire (wire-sim a1))))
    (gate-nand output a1 a2)
    output))

(define (wire-or a1 a2)
  (let ((output (make-wire (wire-sim a1))))
    (gate-or output a1 a2)
    output))

(define (wire-nor a1 a2)
  (let ((output (make-wire (wire-sim a1))))
    (gate-nor output a1 a2)
    output))

(define (wire-xor a1 a2)
  (let ((output (make-wire (wire-sim a1))))
    (gate-xor output a1 a2)
    output))

;;;;
;-------   BUS  ------
(define (bus-set! wires value)
  (match wires
    ['() (void)]
    [(cons w wires)
     (begin
       (wire-set! w (= (modulo value 2) 1))
       (bus-set! wires (quotient value 2)))]))

(define (bus-value ws)
  (foldr (lambda (w value) (+ (if (wire-value w) 1 0) (* 2 value)))
         0
         ws))

(define (flip-flop out clk data)
  (define sim (wire-sim data))
  (define w1  (make-wire sim))
  (define w2  (make-wire sim))
  (define w3  (wire-nand (wire-and w1 clk) w2))
  (gate-nand w1 clk (wire-nand w2 w1))
  (gate-nand w2 w3 data)
  (gate-nand out w1 (wire-nand out w3)))

;---------------------------
; Testowanie flip-flop

(define sim1 (make-sim))
(define w4 (make-wire sim1))
(define w5 (make-wire sim1))
(define w6 (make-wire sim1))

(flip-flop w5 w4 w6)

(wire-set! w4 #t)
(sim-wait! sim1 1)
(wire-set! w4 #f)
(sim-wait! sim1 1)

(module+ test
  (require rackunit)
  
  (check-equal? (wire-value w6)  #f))

