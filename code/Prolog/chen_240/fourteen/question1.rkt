; Luke Schulz
; 4/25/19
; ASU ID# = 1211984746
; 240 Tu-Th 4:30


(define foo ; size N problem
  (lambda (x y)
    (cond ((<= x 0) y ) ;stopping conditions
          ((<= y 0) x ) ;stopping conditions
          ((>= x y) (+ x ; size n solution
                       (foo (- x 1) (- y 2))) ) ;size m problem
          ((< x y) (+ y ; size n solution #2
                      (foo (- x 2) (- y 3))) ) ; size m problem #2
          )
    )
  )

(foo 5 6 ) ; this too easy chen come on