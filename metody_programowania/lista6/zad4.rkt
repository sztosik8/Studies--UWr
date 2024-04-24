#lang plait

( define-type ( NNF 'v )
( nnf-lit [ polarity : Boolean ] [ var : 'v ])
( nnf-conj [ l : ( NNF 'v ) ] [ r : ( NNF 'v ) ])
( nnf-disj [ l : ( NNF 'v ) ] [ r : ( NNF 'v ) ]) )

( define (neg-nnf f )
   (cond
     [ (nnf-lit? f)
       (nnf-lit (not (nnf-lit-polarity f))(nnf-lit-var f))]
     [ (nnf-conj? f)
       (nnf-disj (neg-nnf (nnf-conj-l f)) ( neg-nnf (nnf-conj-r f)))]
     [ (nnf-disj? f)
       (nnf-conj (neg-nnf (nnf-disj-l f)) ( neg-nnf (nnf-disj-r f)))]))


(define v1 (nnf-lit #t 'p))
(neg-nnf v1)
; ( p )
;   |
;   |
;   V
; ( ¬p )

(define v2 (nnf-lit #f 'p))
(neg-nnf v2)
; ( ¬p )
;   |
;   |
;   V
; ( p )

(define v3 (nnf-disj (nnf-conj (nnf-lit #t 'p)(nnf-lit #f 'q))
                     (nnf-lit #f 'r)))
(neg-nnf v3)
; (( p ∧ ¬q ) v ( ¬r ))
;        |
;        | 
;        V
; (( ¬p v q ) ∧ ( r ))




