; CSE240 HW11 Spring 2019
; NOTE : make sure to select R5RS in the bottom left corner before running code

; Q1 (5 points)
(write "hello world")
(newline)
(write (+ (* 3 8) 10))
(newline)
(- 20 5)
(write (read)) ; input a number from keyboard

; Q2 (5 points)
;(#1);;;;;(3 + (5 + (7 + (9 + (11 + 13)))))
(+ 3 (+ 5 (+ 7 (+ 9 (+ 11 13)))))

;(#2);;;;(((((3 + 5) + 7) + 9) + 11) + 13)+(
(+ (+ (+(+ (+ 3 5) 7 ) 9) 11) 13) ; i put all the parenthesis idk if thats what you want ;; (+ x y z) works just as well

;(#3);;;;((2+4)+(3+5)+(6+8))
(+ (+ 2 4) (+ 3 5) (+ 6 8))

;(#4).;;;; (2 + 4 + 6 + 8 + 10 + 12)
(+ 2 4 6 8 10 12 )

;(#5). ;;;;; (2 + 3 * 5 + 4 * 6 + 7)
(+ (* 3 5) (* 4 6) 7)

;(#6). ;;;; 125187
12587
; Q3 (10 points)

 
; Q4 (5 points)


; Q5 (10 points)


; Q6 (5 points)


; Q7 (5 points)


;Q8: (10 points)

