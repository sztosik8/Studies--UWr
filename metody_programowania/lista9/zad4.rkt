#lang racket

(define morse-dict
  '((#\A . "._") (#\B . "_... ") (#\C . "_._. ") (#\D . "_.. ") (#\E . ". ")
                 (#\F . ".._. ") (#\G . "_ _. ") (#\H . ".... ") (#\I . ".. ")
                 (#\J . "._ _ _ ") (#\K . "_._ ") (#\L . "._.. ") (#\M . "__ ")
                 (#\N . "_. ") (#\O . "___ ") (#\P . ".__. ") (#\Q . "__._ ")
                 (#\R . "._. ") (#\S . "... ") (#\T . "_ ") (#\U . ".._ ")
                 (#\V . "..._ ") (#\W . ".__ ") (#\X . "_.._ ") (#\Y . "_.__ ")
                 (#\Z . "__.. ") (#\0 . "_____ ") (#\1 . ".____ ") (#\2 . "..___ ")
                 (#\3 . "...__ ") (#\4 . "...._ ") (#\5 . "..... ") (#\6 . "_.... ")
                 (#\7 . "__... ") (#\8 . "___.. ") (#\9 . "____. ") (#\space . "  ")))

(define (get-morse-char ch)
  (cdr (assoc ch morse-dict)))

(define (print-morse new-string xs)
  (cond
    [(null? xs) new-string]
    [(and (char-whitespace? (car xs)) (not (null? (cdr xs))) (char-whitespace? (car(cdr xs))))
     (print-morse new-string (cdr xs))]
    [else
     (print-morse (string-append new-string (get-morse-char (car xs))) (cdr xs))]))

(define (morse-code text) 
  (print-morse "" (string->list (string-upcase text))))

(morse-code " Metody    Program                owania     ")