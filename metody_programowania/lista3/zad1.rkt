#lang racket


"--------A------------"

'((car (a . b)) (* 2))
(list (list 'car (cons 'a 'b)) '(* 2))

;test
(equal? '(car (a . b) (* 2)) (list (list 'car (cons 'a 'b)) '(* 2)))


"--------B------------"
 
`(,(car '(a . b)), (* 2))
(list (car '(a . b)) (* 2))

;test
(equal? (list (car '(a . b)) (* 2)) `(,(car '(a . b)), (* 2)))
 
;‘'`


"---------C-----------"

'((+ 1 2 3) (cons) (cons a b))
(list '(+ 1 2 3) '(cons) (list 'cons 'a 'b))

;test
(equal? '((+ 1 2 3) (cons) (cons a b)) (list '(+ 1 2 3) (quote (cons)) (list 'cons 'a 'b)))

