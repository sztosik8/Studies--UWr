#lang plait

; ('a 'b -> 'a)
(define (f1 a b)
  a)

;(('a 'b -> 'c) ('a -> 'b) 'a -> 'c)
(define (f2 f g a)
  (f a (g a)))

;((('a -> 'a) -> 'a) -> 'a)
(define (f3 [f : (('a -> 'a)->'a)])
  (f (lambda (a) a)))

;(('a -> 'b) ('a -> 'c) -> ('a -> ('b * 'c)))
(define (f4 f g )
  (lambda (a)
    (pair (f a) (g a))))


;(('a -> (Optionof ('a * 'b))) 'a -> (Listof 'b))
(define (f5 [f : ('a -> (Optionof ('a * 'b)))] a)
  (list (snd ( some-v (f a)))))

(define (f6 f a)
  (list (snd (some-v (f (fst (some-v (f a))))))))

; pair - ('a 'b -> ('a * 'b))
; fst - (('a * 'b) -> 'a)
; snd - (('a * 'b) -> 'b)
; list - (Listof '_a)
; some-v - ((Optionof 'a) -> 'a)