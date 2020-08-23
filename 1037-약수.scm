(define (read-n n)
  (if (= n 0)
      '()
      (cons (read) (read-n (- n 1)))))

(define input (read-n (read)))

(display
  (* (apply min input)
     (apply max input)))
