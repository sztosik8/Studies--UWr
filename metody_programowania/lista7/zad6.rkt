#lang racket

( parametric- >/ c [ a b ] (- > (- > a b b ) b ( listof a ) b ) )
(('a 'b - > 'b ) 'b ( Listof 'a ) - > 'b )

( parametric- >/ c [ a ] (- > (- > a a a ) a ( listof a ) a ) )
(('a 'a - > 'a ) 'a ( Listof 'a ) - > 'a )