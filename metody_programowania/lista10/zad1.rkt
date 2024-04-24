#lang plait

(require (typed-in racket
                   (apply : (('a 'a -> 'a) (Listof 'a) -> 'a))))

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type Op
  (add)
  (sub)
  (mul)
  (div))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op]
       [args : (Listof Exp)]))  ;; przyjmuje liste argumentow

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{SYMBOL ANY ...} s)
     (opE (parse-op (s-exp->symbol (first (s-exp->list s)))) ; parsujemy operator
          (map parse (rest (s-exp->list s))))]           ; i liste argumentow
    [else (error 'parse "invalid input")]))


(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [else (error 'parse "unknown operator")]))
                 
(module+ test
  (test (parse `2)
        (numE 2))
  (test (parse `{+ 2 1})
        (opE (add) (list (numE 2) (numE 1))))
  (test (parse `{* 3 4})
        (opE (mul) (list (numE 3) (numE 4))))
  (test (parse `{+ {* 3 4} 8})
        (opE (add)
             (list (opE (mul) (list (numE 3) (numE 4)))
             (numE 8)))))

;; eval --------------------------------------

(define-type-alias Value Number)

(define (op->proc [op : Op]) : ((Listof Value) -> Value) ; funkcje dla list
  (type-case Op op
    [(add) (lambda (xs) (apply + xs))]
    [(sub) (lambda (xs) (apply - xs))]
    [(mul) (lambda (xs) (apply * xs))]
    [(div) (lambda (xs) (apply / xs))]))

(define (eval [e : Exp]) : Value
  (type-case Exp e
    [(numE n) n]
    [(opE o xs) ((op->proc o) (map eval xs))])) ; ewalujemy kazdy element  listy 


(define (run [e : S-Exp]) : Value
  (eval (parse e)))

(module+ test
  (test (run `2)
        2)
  (test (run `{+ 2 1})
        3)
  (test (run `{* 2 1})
        2)
  (test (run `{+ {* 2 3} {+ 5 8}})
        19))

;; printer ———————————————————————————————————-

(define (print-value [v : Value]) : Void
  (display v))

(define (main [e : S-Exp]) : Void
  (print-value (eval (parse e))))