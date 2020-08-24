(define (digit-sum n)
  (if (= n 0)
      0
      (+ (remainder n 10)
         (digit-sum (quotient n 10)))))

(define (decompose-sum n)
  (+ n (digit-sum n)))

(define (generator n)
  (define (iter m)
    (cond ((= m n) 0)
          ((= (decompose-sum m) n) m)
          (else (iter (+ m 1)))))
  (iter 1))

(display
  (generator (read)))
