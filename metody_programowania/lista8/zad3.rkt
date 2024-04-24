#lang racket

(provide
 mqueue?
 nonempty-mqueue?
 (contract-out
  [mqueue-empty?       (-> mqueue? boolean?)]
  [make-mqueue         (-> mqueue?)]
  [mqueue-push-front   (-> mqueue? any/c void?)] ; dodanie na poczatek
  [mqueue-push-back    (-> mqueue? any/c void?)] ; dodanie na koniec
  [mqueue-pop-front    (-> mqueue? any/c)]  ; zabranie z poczatku
  [mqueue-pop-back     (-> mqueue? any/c)]  ; zabranie z konca
  [mqueue-join         (-> nonempty-mqueue? nonempty-mqueue? void?)]))

; Kolejka dwukierunkowa
(struct mqueue
  ([front #:mutable]
   [back  #:mutable]))

; node listy dwukierunkowej
(struct node
  ([prev   #:mutable]  
   [val    #:mutable]      
   [next   #:mutable]))

; Predykat sprawdzający, czy lista jest pusta
(define (mqueue-empty? q)
  (and (null? (mqueue-front q))
       (null? (mqueue-back  q))))

; Predykat sprawdzając, czy lista jest niepusta (czy ma pierwszy element)
(define (nonempty-mqueue? q)
  (and (mqueue? q) (node? (mqueue-front q))))

; Utworzenie pustej kolejki
(define (make-mqueue)
  (mqueue null null))

; Dodanie nowego elementu na początek kolejki
(define (mqueue-push-front mq val) 
  (define new (node null val null))
  (cond 
    [(mqueue-empty? mq) ; kolejka jest pusta
     (set-mqueue-front! mq new) ; Ustawienie nowego elementu na pierwsze i ostatnie miejsce
     (set-mqueue-back! mq new)]
    [else ; kolejnka nie jest pusta
     (set-node-next! new (mqueue-front mq)) ; Ustawienie nowego elementu na koniec początek kolejki
     (set-node-prev! (mqueue-front mq) new)
     (set-mqueue-front! mq new)]))

; Dodanie nowego elementu na koniec kolejki
(define (mqueue-push-back mq val)
  (define new (node null val null))
  (cond 
    [(mqueue-empty? mq) ; kolejka jest pusta
     (set-mqueue-front! new) ; Ustawienie nowego elementu na pierwsze i ostatnie miejsce
     (set-mqueue-back! new)]
    [else ; kolejnka nie jest pusta
     (set-node-prev! new (mqueue-back mq)) ; Ustawienie nowego elementu na koniec początek kolejki
     (set-node-next! (mqueue-back mq) new ) ; Ustawienie nowego elementu na koniec początek kolejki
     (set-mqueue-back! mq new)]))

; Pobranie wartości z początku kolejki
(define/contract (mqueue-pop-front mq)
  (-> nonempty-mqueue? any/c)
  (define val (node-val (mqueue-front mq)))
  (set-mqueue-front! mq (node-next (mqueue-front mq))) ; ustawienie początku kolejki na następny element
  (if (null? (mqueue-front mq)) ; jeżeli usuwamy ostatni element kolejki
      (begin
        (set-mqueue-back! mq null) ; ustawiamy koniec kolejki na null
        val) 
      val)) ; w przeciwnym przypadku zwracamy wartość
        
; Pobranie wartości z końca kolejki
(define/contract (mqueue-pop-back mq)
  (-> nonempty-mqueue? any/c)
  (define val (node-val (mqueue-back mq))) ; zapisanie wartości
  (set-mqueue-back! mq (node-prev (mqueue-back mq))) ; ustawienie końca kolejki na poprzedni element
  (if (null?  (mqueue-back mq)) ; jeżeli usuwamy ostatni element kolejki
      (begin
        (set-mqueue-front! mq null) ; ustawiamy początek koleki na null i zwracamy wartość
        val) 
      val)) ; w przeciwnym przypadku zwracamy wartość
        
; Złączenie dwóch kolejek
(define (mqueue-join mq1 mq2)
  ; połączenie ostatniego elementu mq1 z mq2
  (set-node-next! (mqueue-back mq1) (mqueue-front mq2))
  (set-node-prev! (mqueue-front mq2) (mqueue-back mq1))
  ; Ustawienie końca mq1 na koniec mq2
  (set-mqueue-back! mq1 (mqueue-back mq2))
    
  ; Wyzerowanie wskaźników z mq2
  (set-mqueue-front! mq2 null)  
  (set-mqueue-back! mq2 null))


(define mq1 (make-mqueue))
(define mq2 (make-mqueue))


(mqueue-push-front mq1 3)
(mqueue-push-front mq1 2)
(mqueue-push-front mq1 1)
(mqueue-push-back mq1 4)
(mqueue-push-back mq1 5)
(mqueue-push-back mq1 6)

(mqueue-push-front mq2 3)
(mqueue-push-front mq2 2)
(mqueue-push-front mq2 1)
(mqueue-push-back mq2 4)
(mqueue-push-back mq2 5)
(mqueue-push-back mq2 6)

(mqueue-join mq1 mq2)
