(define (hash a r m)
  (define (char->code c)
    (+ 1
       (- (char->integer c)
          (char->integer #\a))))
  (define (iter a i sum)
    (if (null? a)
        sum
        (iter (cdr a)
              (+ i 1)
              (remainder
                (+ sum
                   (* (char->code (car a))
                      (expt r i)))
                m))))
  (iter a 0 0))

(read)
(display
  (hash (string->list (symbol->string (read))) 31 1234567891))
(newline)
