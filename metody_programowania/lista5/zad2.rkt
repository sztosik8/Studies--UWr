#lang plait

( define ( apply f x ) ( f x ) )
; (('a -> 'b) a' -> 'b)

( define ( compose f g ) ( lambda ( x ) ( f ( g x ) ) ) )
;((('a -> 'b) ('c -> 'a)) -> ('c -> 'b )

( define ( flip f ) ( lambda ( x y ) ( f y x ) ) )
; (('a 'b) -> ('c)) -> (('b 'a)-> ('c))

( define ( curry f ) ( lambda ( x ) ( lambda ( y ) ( f x y ) ) ) )
; (('a 'b) -> 'c) -> ('a -> ('b -> 'c)))

; plait ----
(define-type (Alist)
  (Anull)
  (Acons [x : 'a][xs : Alist])
  (Aappend [xs : Alist ] [ys : Alist ]))



