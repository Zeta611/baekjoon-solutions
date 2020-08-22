(define (reverse n)
  (define (iter acc m)
    (if (= m 0)
        acc
        (iter (+ (remainder m 10)
                 (* acc 10))
              (quotient m 10))))
  (iter 0 n))

(define (palindrome? n)
  (= n (reverse n)))

(define (main)
  (let ((num (read)))
    (cond ((= num 0) #f)
          ((palindrome? num)
           (display "yes\n")
           (main))
          (else
            (display "no\n")
            (main)))))

(main)
