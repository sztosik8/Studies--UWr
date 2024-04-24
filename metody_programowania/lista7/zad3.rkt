#lang racket

(define/contract (suffixes-con xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? xs)
      (list null)
      (cons xs (suffixes (cdr xs)))))

(define (suffixes xs)
   (if (null? xs)
      (list null)
      (cons xs (suffixes (cdr xs)))))



(define lis (range 20))


(time (suffixes-con lis)) ; Z kontraktem
; cpu time: 12 real time: 13 gc time: 1 - (range 500)

(time (suffixes lis)) ; bez kontraktu
; cpu time: 0 real time: 0 gc time: 0  - (range 500)
