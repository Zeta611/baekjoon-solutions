(define (display-pair l r) (map display (list l " " r "\n")))

(define (hanoi n source dest)
  (if (= n 1) (display-pair source dest)
    (begin (hanoi (- n 1) source (- 6 (+ source dest)))
      (hanoi 1 source dest)
      (hanoi (- n 1) (- 6 (+ source dest)) dest))))

(define input (read))
(display (- (expt 2 input) 1))
(display "\n")
(hanoi input 1 3)
