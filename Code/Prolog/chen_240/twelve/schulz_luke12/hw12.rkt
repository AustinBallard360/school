 
;CSE 240 Spring 2019 HW12
; Name: Luke Schulz !

; For testing a procedure, you may comment out other procedures.

;Q1: (8 points) creates a list with alternative values from the 3 given lists

(define (alternate lst1 lst2 lst3) ; N SIZE PROBLEM
  (if (or (null? lst1) (null? lst2) (null? lst3) ) ; STOPPING CONDITION
      '(); RETURN VALUE
      (append ;start false
       (list (car lst1) (car lst2) (car lst3) ) ; N-SIZE SOLUTION (solve once)
       (alternate (cdr lst1) (cdr lst2) (cdr lst3) ) ;M-SIZE SOLUTION (recursive call)
      );end false
   ) ; end if
)
;Test case:
(alternate '(1 2 3 4) '(a b c d) '(m n o p))
; Test output:
;'(1 a m 2 b n 3 c o 4 d p).


;Q2: (8 points) shuffle lists one and two in pairs

(define (pairs lst1 lst2)
  (if
    (or (null? lst1) (null? lst2) ) ; STOPING CONDiTION
      '() ; RETURN VALUE (empty list)
      (append ;N  SOLUTION?
        (cons ;N  SOLUTION?
        (cons (car lst1) (car lst2) ) ;N  SOLUTION?
        (pairs (cdr lst1) (cdr lst2)) ; M SIZE SOLUTION (RECURSION) REVERSE ORDER?
        )
      )
  )
)
;Test case:
(pairs '(1 2 3 4) '(a b c d))
;Test output
;'((1 . a) (2 . b) (3 . c) (4 . d))

  
;Q3: (9 points)
; encryption
(define encrypt (lambda (str) ;top function, set key, hold other function defs
                  (define key (read)) ; set our key first thing
                  ;;INNER FUNCTION #1;;;;;;;;;;;;;;;;
                  (define string-encryption ;this function takes string, calls the mapping
                    (lambda (str) 
                      (list->string ;3-THIRD-> make result of map a string
                       (map character-encryption ;2-SECOND-> map encrypt function to each char now in list
                            (string->list str) ;1-FIR;;INNER FUNCTION #1;;;;;;;;;;;;;;;;ST-> turn string to list so mappable (also converts to chars)
                                         ) ;close map
                                    ) ;close back to string
                      ) ; close string-encrypt lambda
                    ) ; close strin-encrypt define
                  
                  ;;INNER FUNCTION #2;;;;;;;;;;;;;;;;
                  (define character-encryption ; handles one char checks input, calls char-rotation (to add key value)
                    (lambda (ch)
                      (if	(or (char-alphabetic? ch) (char-numeric? ch) ) ; check input, if a single char number or letter (wont work 4 decrypt)
                                (character-rotation ch) ;true branch, good input? do char-rotation function
                                ch	    ; non-letter will not be encrypted. (any bad input, return as is)
                                ) ;close if
                      ) ; close char-encr lambda
                    ) ; close char-encr define
                  
                  ;;INNER FUNCTION #3;;;;;;;;;;;;;;;;
                  (define character-rotation ;handles only good chars, adds key value
                    (lambda (ch) ; input cleaned by character-encryption function, only clean chars allowed
                      (integer->char (+ (char->integer ch) key ) )  ;convert2Int -> +key -> convertBack2Char
                      ) ; close char-rot lambda
                    ) ; close char-rot def
                  ;;;so far we only had 4 defines, key->strig-encr->char-encr->char-rotate
                  (string-encryption str) ; actual procedure call of encrypt (do the whole thing)
                  ) ; end lambda encrypt (close top function)
  ) ; close top define encrypt

;decryption
(define decrypt ;;;;;start w/ copy paste from encrypt
  (lambda (str)
     (define key (read)) ; set our key first thing
                  ;;INNER FUNCTION #1;;;;;;;;;;;;;;;;
                  (define string-decryption ;this function takes string, calls the mapping
                    (lambda (str) 
                      (list->string ;3-THIRD-> make result of map a string
                       (map character-decryption ;2-SECOND-> map decrypt function to each char now in list
                            (string->list str) ;1-FIR;;INNER FUNCTION #1;;;;;;;;;;;;;;;;ST-> turn string to list so mappable (also converts to chars)
                                         ) ;close map
                                    ) ;close back to string
                      ) ; close string-dcrypt lambda
                    ) ; close strin-dcrypt define
                  
                  ;;INNER FUNCTION #2;;;;;;;;;;;;;;;;
                  (define character-decryption ; handles one char checks input, calls char-rotation (to add key value)
                    (lambda (ch)
                     ; (if (not (equal? ch #\space) )	;
                      (if (or (char-alphabetic? (character-rotation ch)) (char-numeric? (character-rotation ch)) ) ; check if when rotated, is a apha/numeric char.
                                (character-rotation ch) ;true branch, good input? do char-rotation function
                                ch	    ; non-letter/num will not be decrypted. (any bad input, return as is)
                                ) ;close if
                      ) ; close char-decr lambda
                    ) ; close char-decr define
                  
                  ;;INNER FUNCTION #3;;;;;;;;;;;;;;;;
                  (define character-rotation ;handles only good chars, adds key value
                    (lambda (ch) ; input cleaned by character-encryption function, only clean chars allowed
                      (integer->char (- (char->integer ch) key ) )  ;convert2Int -> -key -> convertBack2Char
                      ) ; close char-rot lambda
                    ) ; close char-rot def
                  ;;;so far we only had 4 defines, key->strig-encr->char-encr->char-rotate
                  (string-decryption str) ; actual procedure call of encrypt (do the whole thing)
                  ) ; end lambda decrypt (close top function)
  ) ; close top define decrypt



    

; Test cases:
(encrypt "Hello CSE240!")
(decrypt "Lipps GWI684!")
(encrypt "Hello CSE598?")
(decrypt "Lipps GWI9=<?")

; Test outputs:
;4
;"Lipps GWI684!"
;4
;"Hello CSE240!"
;4
;"Lipps GWI9=<?"
;4
;"Hello CSE598?"


