#lang racket

;; 1


(( lambda ( x y ) (+ x (* x y ))) 1 2)

; funkcja przyjmuje x i y i zwraca ich iloczyn powiekszony o x
; dodatkowo jest wywolana z argumentami 1 i 2 czyli x=1 y=2
; a jej wynik to 3



;; 2

  (( lambda ( x ) x ) ( lambda ( x ) x ) )

; x
     


;; 3

(( lambda ( x ) ( x x ) ) ( lambda ( x ) x ) )


;; 4
(( lambda ( x ) ( x x ) ) ( lambda ( x ) ( x x ) ) )












