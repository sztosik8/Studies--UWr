#lang plait

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type Op
  (add) (sub) (mul) (div) (eql) (leq))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op] [l : Exp] [r : Exp])
  (ifE [b : Exp] [l : Exp] [r : Exp])
  (varE [x : Symbol])
  (letE [x : Symbol] [e1 : Exp] [e2 : Exp])
  (lamE [x : Symbol] [e : Exp])
  (appE [e1 : Exp] [e2 : Exp]))

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{lambda {SYMBOL} ANY} s)
     (lamE (s-exp->symbol
            (first (s-exp->list 
                    (second (s-exp->list s)))))
           (parse (third (s-exp->list s))))]
    [(s-exp-match? `{SYMBOL ANY ANY} s)
     (opE (parse-op (s-exp->symbol (first (s-exp->list s))))
          (parse (second (s-exp->list s)))
          (parse (third (s-exp->list s))))]
    [(s-exp-match? `{if ANY ANY ANY} s)
     (ifE (parse (second (s-exp->list s)))
          (parse (third (s-exp->list s)))
          (parse (fourth (s-exp->list s))))]
    [(s-exp-match? `SYMBOL s)
     (varE (s-exp->symbol s))]
    [(s-exp-match? `{let SYMBOL ANY ANY} s)
     (letE (s-exp->symbol (second (s-exp->list s)))
           (parse (third (s-exp->list s)))
           (parse (fourth (s-exp->list s))))]
    [(s-exp-match? `{ANY ANY} s)
     (appE (parse (first (s-exp->list s)))
           (parse (second (s-exp->list s))))]
    [else (error 'parse "invalid input")]))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [(eq? op '=) (eql)]
    [(eq? op '<=) (leq)]
    [else (error 'parse "unknown operator")]))



;; binding

(define-type-alias (Setof 'a) (Listof 'a))

(define (emptyS) : (Setof 'a)
  empty)

(define (singletonS [x : 'a]) : (Setof 'a)
  (list x)) 

(define (inS [x : 'a] [s : (Setof 'a)]) : Boolean
  (member x s))

(define (unionS [s1 : (Setof 'a)] [s2 : (Setof 'a)]) : (Setof 'a)
  (append (filter (λ (x) (not (member x s2))) s1) s2)) 

(define (removeS [x : 'a] [s : (Setof 'a)]): (Setof 'a)
  (filter (λ (y) (not (eq? x y))) s))

(define (subsetS [s1 : (Setof 'a)] [s2 : (Setof 'a)]) : Boolean
  (empty? (filter (λ (x) (not (member x s2))) s1)))

(define (equalS [s1 : (Setof 'a)] [s2 : (Setof 'a)]) : Boolean
  (and (subsetS s1 s2) (subsetS s2 s1)))
  
(define (fromList [xs : (Listof 'a)]) : (Setof 'a)
  (foldr (λ (x s) (unionS (singletonS x) s))
         (emptyS)
         xs))

;; -------------------- free variables --------------------------

    (define (fv [e : Exp]) : (Setof Symbol)
  (type-case Exp e
    [(numE n) (emptyS)]
    [(opE o l r) (unionS (fv l) (fv r))]
    [(ifE b l r)
     (unionS (fv b) (unionS (fv l) (fv r)))]
    [(varE x)
     (singletonS x)]
    [(letE x e1 e2)
     (unionS (fv e1)
             (removeS x (fv e2)))]
    [(lamE x e)  ;FV(λx.M) = FV(M) - {x}
     (removeS x (fv e))]
    [(appE e1 e2)
     (unionS (fv e1) (fv e2))]))

; TESTY

(module+ test
  (test (equalS (fv (parse `2))
                (emptyS))
        #t)
  (test (equalS (fv (parse `{* x {+ y x}}))
                (fromList '(x y)))
        #t)
  (test (equalS (fv (parse `{* x {+ y x}}))
                (fromList '(x y)))
        #t)
  (test (equalS (fv (parse `{(if (= x 3) double 4) 9}))
                (fromList  '(x double)))
        #t)
    (test (equalS (fv (parse `{lambda {x} (+ x y)}))
                (singletonS 'y))
        #t)
  
  )

;; -----------------------------------------------
                
(module+ test
  (test (parse `2)
        (numE 2))
  (test (parse `{+ 2 1})
        (opE (add) (numE 2) (numE 1)))
  (test (parse `{* 3 4})
        (opE (mul) (numE 3) (numE 4)))
  (test (parse `{+ {* 3 4} 8})
        (opE (add)
             (opE (mul) (numE 3) (numE 4))
             (numE 8)))
  (test (parse `{if {= 0 1} {* 3 4} 8})
        (ifE (opE (eql) (numE 0) (numE 1))
             (opE (mul) (numE 3) (numE 4))
             (numE 8)))
  (test/exn (parse `{{+ 1 2}})
            "invalid input")
  (test (parse `{+ 1})
        (appE (varE '+) (numE 1)))
  (test/exn (parse `{^ 1 2})
            "unknown operator")
  (test (parse `{let x 1 {+ x 1}})
        (letE 'x (numE 1) (opE (add) (varE 'x) (numE 1))))
  (test (parse `{lambda {x} 9})
        (lamE 'x (numE 9)))
  (test (parse `{double 9})
        (appE (varE 'double) (numE 9))))


