(import (chicken sort))

(define (factor n)
  (define (try m q)
    (cond ((> q m) '())
          ((= (remainder m q) 0)
           (cons q
                 (try (quotient m q) q)))
          (else (try m (+ q 1)))))
  (try n 2))

(for-each (lambda (x)
            (display x)
            (newline))
          (sort (factor (read)) <))
