(define (square x) (* x x))

(define (verify numbers)
  (if (null? numbers)
      0
      (remainder
        (+ (square (car numbers))
           (verify (cdr numbers)))
        10)))

(display
  (verify
    (list (read) (read) (read) (read) (read))))
