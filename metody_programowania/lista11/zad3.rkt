#lang plait

;Zadnaie 3

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
  (letE [bindings : (Listof (Listof S-Exp))] [body : Exp]) ;lista wyrazen
  (letE* [bindings : (Listof (Listof S-Exp))] [body : Exp])) ;lista wyrazen

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    
    [(s-exp-match? `{let ({SYMBOL ANY} ...) ANY} s) ;<----
     (letE (convert-to-list (s-exp->list (second (s-exp->list s))))
           (parse (third (s-exp->list s))))]
    
    [(s-exp-match? `{let* ({SYMBOL ANY} ...) ANY} s) ;<----
     (letE* (convert-to-list (s-exp->list (second (s-exp->list s))))
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
    [else (error 'parse "invalid input")]))

(define (convert-to-list [lst : (Listof S-Exp)]) : (Listof (Listof S-Exp)) ;<----
  (map (lambda (bind) (s-exp->list bind)) lst))
#|
> (s-exp->list (second (s-exp->list `{let ({x 1} {y 2}) {+ x y}})))
- (Listof S-Exp)
(list `(x 1) `(y 2))

> (convert-to-list  (s-exp->list (second (s-exp->list `{let ({x 1} {y 2}) {+ x y}}))))
- (Listof (Listof S-Exp))
(list (list `x `1) (list `y `2))
|#



(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [(eq? op '=) (eql)]
    [(eq? op '<=) (leq)]
    [else (error 'parse "unknown operator")]))

;; eval --------------------------------------

;; values

(define-type Value
  (numV [n : Number])
  (boolV [b : Boolean]))

;; primitive operations

(define (op-num-num->proc [f : (Number Number -> Number)]) : (Value Value -> Value)
  (λ (v1 v2)
    (type-case Value v1
      [(numV n1)
       (type-case Value v2
         [(numV n2)
          (numV (f n1 n2))]
         [else
          (error 'eval "type error")])]
      [else
       (error 'eval "type error")])))

(define (op-num-bool->proc [f : (Number Number -> Boolean)]) : (Value Value -> Value)
  (λ (v1 v2)
    (type-case Value v1
      [(numV n1)
       (type-case Value v2
         [(numV n2)
          (boolV (f n1 n2))]
         [else
          (error 'eval "type error")])]
      [else
       (error 'eval "type error")])))

(define (op->proc [op : Op]) : (Value Value -> Value)
  (type-case Op op
    [(add) (op-num-num->proc +)]
    [(sub) (op-num-num->proc -)]
    [(mul) (op-num-num->proc *)]
    [(div) (op-num-num->proc /)]
    [(eql) (op-num-bool->proc =)]
    [(leq) (op-num-bool->proc <=)]))

;; environments

(define-type Binding  ;pary np (x 4)
  (bind [name : Symbol]
        [val : Value]))

(define-type-alias Env (Listof Binding))

(define mt-env empty)  ;puste srodowisko

(define (extend-env [env : Env] [x : Symbol] [v : Value]) : Env
  (cons (bind x v) env)) ; dodanie zmiennej do srodowiska

(define (lookup-env [n : Symbol] [env : Env]) : Value ; szukanie czy zmienna jest w srodowisku
  (type-case (Listof Binding) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind-name b))
                         (bind-val b)]
                        [else (lookup-env n rst-env)])]))

;; evaluation function

(define (eval [e : Exp] [env : Env]) : Value
  (type-case Exp e
    [(numE n) (numV n)]
    [(opE o l r) ((op->proc o) (eval l env) (eval r env))]
    [(ifE b l r)
     (type-case Value (eval b env)
       [(boolV v)
        (if v (eval l env) (eval r env))]
       [else
        (error 'eval "type error")])]
    [(varE x)
     (lookup-env x env)]
    ;<----
    [(letE bindings body)
     (let ([env (eval-bindings bindings env)])
       (eval body env))]
    [(letE* bindings body)
     (let* ([env (eval-let* bindings env)])
       (eval body env))]
    ))

(define (eval-let* bindings env) ;<----
  (cond
    [(empty? bindings) env]
    [(cons? bindings)
     (let ([var (s-exp->symbol (first (first bindings)))]
           [exp (second (first bindings))])
       (let ([val (eval (parse exp) env)])
         (eval-let* (rest bindings) (extend-env env var val))))]))

(define (eval-bindings bindings env)  ;<----
  (cond
    [(empty? bindings) env]
    [(cons? bindings)
     (let ([var (s-exp->symbol (first (first bindings)))]
           [exp (second (first bindings))])
       (let ([val (eval (parse exp) env)])
         (extend-env (eval-bindings (rest bindings) env) var val)))]))


;; printer ———————————————————————————————————-

(define (value->string [v : Value]) : String
  (type-case Value v
    [(numV n) (to-string n)]
    [(boolV b) (if b "true" "false")]))

(define (print-value [v : Value]) : Void
  (display (value->string v)))

(define (run [e : S-Exp]) : Value
  (eval (parse e) mt-env))

;; testy

(module+ test
  (test (run `{let ({x 1}) {let ({y {+ x 2}}) {+ x y}}})
        (numV 4))
  (test (run `{let* ({x 1} {x {+ x 2}}) {+ x x}})
        (numV 6))
  (test (run `{let* ({x 1} {y (+ x 2)}) {+ x y}})
        (numV 4))
  (test (run `{let* ({x 1} {y (+ x 2)} {z (* x y)}) {+ x (+ y z)}})
        (numV 7)))




