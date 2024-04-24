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

; symulacja
(struct sim ([time #:mutable] [queue #:mutable]))

; konstruktor symulacji
(define (make-sim)
  (sim 0 (make-heap (lambda (x y) (< (car x) (car y)))))) ; kolejka trzyma pary (czas, akcja)

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


;wartosc logiczna sygnalow
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
  (check-equal? (logical-and #f #t) #f)
  (check-equal? (logical-and #f #f) #f)

  ; Testy dla funkcji logical-nand
  (check-equal? (logical-nand #t #t) #f)
  (check-equal? (logical-nand #t #f) #t)
  (check-equal? (logical-nand #f #t) #t)
  (check-equal? (logical-nand #f #f) #t)

  ; Testy dla funkcji logical-or
  (check-equal? (logical-or #t #t) #t)
  (check-equal? (logical-or #t #f) #t)
  (check-equal? (logical-or #f #t) #t)
  (check-equal? (logical-or #f #f) #f)

  ; Testy dla funkcji logical-nor
  (check-equal? (logical-nor #t #t) #f)
  (check-equal? (logical-nor #t #f) #f)
  (check-equal? (logical-nor #f #t) #f)
  (check-equal? (logical-nor #f #f) #t)

  ; Testy dla funkcji logical-xor
  (check-equal? (logical-xor #t #t) #f)
  (check-equal? (logical-xor #t #f) #t)
  (check-equal? (logical-xor #f #t) #t)
  (check-equal? (logical-xor #f #f) #f)
)


;--------------------------

(define (after-delay delay sim action)
  (sim-add-action! sim delay action))

;-----------------------------

(define (gate-not a out)
  (define (not-action-procedure)
    (let ((new-value
           (logical-not (wire-value a))))
      (after-delay not-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a not-action-procedure))


(define (gate-and a1 a2 out)
  (define (and-action-procedure)
    (let ((new-value
           (logical-and (wire-value a1)(wire-value a2))))
      (after-delay and-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a1 and-action-procedure)
  (wire-on-change! a2 and-action-procedure))

(define (gate-nand a1 a2 out)
  (define (nand-action-procedure)
    (let ((new-value
           (logical-nand ( wire-value a1)(wire-value a2))))
      (after-delay nand-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a1 nand-action-procedure)
  (wire-on-change! a2 nand-action-procedure))

(define (gate-or a1 a2 out)
  (define (or-action-procedure)
    (let ((new-value
           (logical-or ( wire-value a1)(wire-value a2))))
      (after-delay or-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a1 or-action-procedure)
  (wire-on-change! a2 or-action-procedure))

(define (gate-nor a1 a2 out)
  (define (nor-action-procedure)
    (let ((new-value
           (logical-nor ( wire-value a1)(wire-value a2))))
      (after-delay nor-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a1 nor-action-procedure)
  (wire-on-change! a2 nor-action-procedure))

(define (gate-xor a1 a2 out)
  (define (xor-action-procedure)
    (let ((new-value
           (logical-xor ( wire-value a1)(wire-value a2))))
      (after-delay xor-delay
                   (wire-sim out)
                   (lambda ()
                     (wire-set! out new-value)))))
  (wire-on-change! a1 xor-action-procedure)
  (wire-on-change! a2 xor-action-procedure))

;-------------------------------------

;;;;
(define (wire-not a1)
  (define out (make-wire (wire-sim a1)))
  (gate-not a1 out)
  out)

(define (wire-and a1 a2)
  (define out (make-wire (wire-sim a1)))
  (gate-and a1 a2 out)
  out)

(define (wire-nand a1 a2)
  (define out (make-wire (wire-sim a1)))
  (gate-nand a1 a2 out)
  out)

(define (wire-or a1 a2)
  (define out (make-wire (wire-sim a1)))
  (gate-or a1 a2 out)
  out)

(define (wire-nor a1 a2)
  (define out (make-wire (wire-sim a1)))
  (gate-nor a1 a2 out)
  out)

(define (wire-xor a1 a2)
  (define out (make-wire (wire-sim a1)))
  (gate-xor a1 a2 out)
  out)

;;;;
;----------------------------
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