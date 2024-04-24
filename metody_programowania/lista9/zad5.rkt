#lang racket

(define morse-dict
  '(("._" . "A" ) ("_...". "B" ) ( "_._." . "C" ) ( "_.." . "D" ) ( "." . "E" )
                 (".._." . "F" ) ("_ _." . "G"  ) ("...." . "H" ) ("..". "I" )
                 ("._ _ _". "J" )("_._" . "K" ) ("._.." . "L" ) ("__" . "M" )
                 ("_." . "N" ) ("___" . "O" ) (".__." . "P" ) ("__._" . "Q" )
                 ("._." . "R" ) ("..." . "S") ("_" . "T" ) (".._" . "U" )
                 ("..._" . "V" ) (".__" . "W" ) ("_.._" . "X" ) ("_.__" . "Y" )
                 ( "__.." . "Z" ) ("_____" . "0" ) (".____" . "1" ) ("..___" . "2" )
                 ("...__" . "3" )("...._" . "4" ) ("....." . "5" ) ("_...." . "6" )
                 ("__..." . "7" )("___.." . "8" ) ("____." . "9" )))


(define (morse->string ans xs)
  (cond
    [ (null? xs) ans]
    [ else (morse->string (string-append ans (cdr (assoc (car xs) morse-dict))) (cdr xs))]))


(define (morse-decode morse)
  (morse->string "" (string-split morse)))


(define morse "__ .__. ..___ _____        ..___ ..___")
( morse-decode morse)

