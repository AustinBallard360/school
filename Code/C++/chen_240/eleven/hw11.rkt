; CSE240 HW11 Spring 2019
; NOTE : make sure to select R5RS in the bottom left corner before running code
;; LUKE SCHULZ!
;; 4/6/19

; Q1 (5 points)
;;(#1.1)
(+ (- 9 2) 5 ) ; quik mafs

;;(#1.2)
(- (* 5 (+ 6 12 5)) 25)

;;(#1.3)
(* 7 (+ (- 5 (* 1 3)) (* 2 4)))

;;(#1.4)
(* 3 (+ 4 (/ (+ (* 6 6) (* 6 6)) (+ 10 2))))

;;(#1.5)

(+(/  (- (/ (/ (* (+ 4 6 ) (+ 6 4 ))  2 ) 2) 5 ) 2 )  (+ (/ (+ ( * 4 5 )  (* 5 4) )2) (* 4 5)))

; Q2 (5 points)
(define add (lambda (x y) ; take input x , y ;;form (add x y)
                   (+ x y) ; sum them
                   )
  )
; Q3 (10 points)
;;make function (square x) ;; use add function; handle negatives;
(define square (lambda (x) ;; The code for size-n problem is:
                 (if (< x 0)
                     (square (abs x)) ; if we are negative, call the function using the absolute value
                     (if (= x 0 ) ;; The code for stopping condition and its return value are:
                         0 ; :return value of stop cond
                         (add (add (- x 1) (square (- x 1))) ; The code for size-m problem is:(n-1 + sqaure(n-1) )
                              x ) ; The code for constructing size-n problem is: + n
                         )
                     )
                 )
  )
                     
; Q4 (5 points)
;; ReadForSquare , takes no params, prompts user, calls square()
(define ReadForSquare ; name our procedure
  (lambda () ; anon func, no params
    (square (read)) ; do the square of user input
    )
  )
; Q5 (10 points)
 ;; take difference of two squares, using input from ReadSquare, account for negative results
(define DiffSquares ; name of procedure
  (lambda() ; anon procedure no params
    (abs ( - (ReadForSquare) (ReadForSquare))) ; return the absolute value of the difference of two user input squares
    )
  )

; Q6 (5 points)
;; AddLet (x y z) ;; return the sum of three inputs, use let to bind them along the way
(define AddLet
  (lambda (x y z) ; proceedure 3 params
    (let ( ; open let scope
        (letX x) ; Assign values
        (letY y)
        (letZ z)
        ) ; close let param
      ;body section
      (+ letX letY letZ)
      ) ; end let scope
    ) ; end lambda
  ) ; end define
      
; Q7 (5 points)
;; anon proceedure adds 3 params. just skip the define?
;; (startForm (function(x y z) (implement x+y+z) endfunc) form-args xIn yIn zIn endForm)  i been thru the desert on a horse with no naaaame
((lambda (x y z ) ; open form, open lambda(params)
  (+ x y z)) ; implementation , close lambda
  60 40 5) ;; passed args, close form

;Q8: (10 points)
;PART 1, NAMED DEFINE FUNC
(define SumOdds ; N SIZE PROBLEM
  (lambda (LST) ; proceedure (param)
    (if (not (= (length LST) 0 )) ; if list not empty ; STOPPING CONDITION
        
        (if ( = (modulo (car LST) 2) 0) ;outer-true branch => 2nd if ( if even (%2 == 0)
            (SumOdds (cdr LST));inner-true branch. NUM IS EVEN RECURSE WITHOUT ACTION
            (+ (car LST) (SumOdds (cdr LST) ) );inner-false brnch ; M-size solution + n solution
        ) ; end inner-if even / outer-true branch
        
        0 ; outer-false branch, list is empty ; STOP CONDITION RETURN VALUE
    ) ;end outer-if
  ) ; end lambda
) ; end define

;;8.2
;; PART TWO, ANNON PROCEEDURE
(((lambda (recursable) (recursable recursable)) ; ( x ) ( x calls x)
  (lambda (doRecurse)
    (lambda (lst)
      (if (= 0 (length lst))
          
           0 ; TRUE, EMPTY LIST STOP
          (if (odd? (car lst)) ;FALSE, REAL LIST
              (+ (car lst) ((doRecurse doRecurse) (cdr lst)));true
              ((doRecurse doRecurse) (cdr lst));false

              ); end false/real list
          ) ; end if
      ) ;end lamba(lst)
    ) ; end lambda (doRecurse)
  ) ; end lambda (recursable)
  '(1 3 4 5 6 -7); form params
 ) ; close form
