#lang plait

(define-type Op2
  (op2-add) (op2-mul) (op2-sub) (op2-div) (op2-pow))

;;
(define-type Op1
  (op1-fac)(op1-minus))
;;

(define-type Exp
  (exp-number [n : Number])
  (exp-op1 [op1 : Op1] [e : Exp]) ;; operatory przyjmujace tylko jeden arg
  (exp-op2 [op2 : Op2] [e1 : Exp] [e2 : Exp])) 

(define (parse-Op2 s)
  (let ([sym (s-exp->symbol s)])
    (cond
      [(equal? sym '+) (op2-add)]
      [(equal? sym '-) (op2-sub)]
      [(equal? sym '*) (op2-mul)]
      [(equal? sym '/) (op2-div)]
      [(equal? sym '^) (op2-pow)])))
;;;
(define (parse-Op1 s)
  (let ([sym (s-exp->symbol s)])
    (cond
      [(equal? sym '!) (op1-fac)]
      [(equal? sym '*-) (op1-minus)]))) 
;;;

(define (parse-Exp s)
  (cond
    [(s-exp-number? s) (exp-number (s-exp->number s))] 
    [(s-exp-list? s)
     (let ([xs (s-exp->list s)])
       (if (or (equal? '! (s-exp->symbol (first xs))) (equal? '*- (s-exp->symbol (first xs))))
           (exp-op1 (parse-Op1 (first xs))
                    (parse-Exp (second xs)))
           (exp-op2 (parse-Op2 (first  xs))
                    (parse-Exp (second xs))
                    (parse-Exp (third  xs)))))]))

; ==============================================


(define (^ a n)
  (if (= n 0)
      1
      (* a (^ a (- n 1)))))

(define (! a)
  (if (= a 0)
      0
      (if (= a 1)
          a
          (* a (- a 1)))))

(define (*- n)
  (* -1 n))

(define (eval-op2 op)
  (type-case Op2 op
    [(op2-add) +]
    [(op2-sub) -]
    [(op2-mul) *]
    [(op2-div) /]
    [(op2-pow) ^]))

(define (eval-op1 op)
  (type-case Op1 op
    [(op1-fac) !]
    [(op1-minus) *-]))

(define (eval e)
  (type-case Exp e
    [(exp-number n)    n]
    [(exp-op2 op2 e1 e2)
     ((eval-op2 op2) (eval e1) (eval e2))]
    [(exp-op1 op1 e)
     ((eval-op1 op1) (eval e))])) 



(define exp1 : Exp (exp-op2 (op2-add) (exp-number 2) (exp-number 2))) ;(+ 2 2)
;(eval exp1)

(define exp2 : Exp (exp-op2 (op2-pow) (exp-op1 (op1-fac) (exp-number 2)) (exp-op1 (op1-minus) (exp-number -2)))) ; (^ (!2) (-* -2))
;(eval exp2)


