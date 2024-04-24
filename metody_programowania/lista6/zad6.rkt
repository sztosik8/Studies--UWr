#lang plait

( define-type ( Formula 'v )
( var [ var : 'v ])
( neg [ f : ( Formula 'v ) ])
( conj [ l : ( Formula 'v ) ] [ r : ( Formula 'v ) ])
( disj [ l : ( Formula 'v ) ] [ r : ( Formula 'v ) ]) )

(define (ne f)
  (cond
    [( var? f ) (neg f)]
    [( neg? f ) (to-nnf (neg-f f))]
    [( conj? f ) ( disj ( to-nnf ( conj-l f ))( to-nnf ( conj-r f )))]
    [( disj?  f )( conj ( to-nnf ( disj-l f ))( to-nnf ( disj-r f )))]))

(define (to-nnf f)
  (cond
    [( var? f ) f]
    [( neg? f ) (ne (neg-f f))]
    [( conj? f ) (conj (to-nnf (conj-l f)) (to-nnf (conj-r f)))]
    [( disj? f ) (disj (to-nnf (disj-l f)) (to-nnf (disj-r f)))]))

(define f1 (conj (var 'p) (neg (disj (neg (var 'q)) (var 'r)))))

; ( p ∧ ¬( ¬q ∨ r ))
;      |
;      |
;      V
; ( p ∧ ( q ∧ ¬r ))
(to-nnf f1)

(define f2 (neg (neg (neg (neg (var 'r))))))
; (¬ (¬ (¬ (¬ r))))
(to-nnf f2)

(define f3 (neg (neg (neg (var 'r)))))
;(¬ (¬ (¬ r)))
(to-nnf f3)

