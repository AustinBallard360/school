#LUKE SCHULZ
#CLASS ID == 155
#Assignment2

.data
userInp: .word 0
#num2: .word 0
#num3: .word 0
timeCount: .word 0
#count2: .word 0
newline: .asciiz  "\n"
inputMsg: .asciiz "Enter a number from 1 to 5:"
inpError: .asciiz "Input is out of range\n"
timeMsg: .asciiz "Time = "
inpFirst: .asciiz "Enter the first number: "
inpSecond: .asciiz "Enter the second number: "
even: .asciiz "Even\n"
less: .asciiz "Less than\n"
greater: .asciiz "Greater than\n"
equal: .asciiz "Equal \n"
odd: .asciiz "Odd\n"
complete: .asciiz "Program complete\n"
name:  .asciiz "Luke Schulz \n"

.text
main:
	initialize:
		lw $s0 , timeCount # initialize $s0 as our count = 0;
		ori $v0 , 4 #print string
		la $a0 , name #load my name into $a0
			syscall #print my name
		jal printnewline # print a new line and return
	promptInput: #get user integer 
		ori $v0 , $0 , 4 # set V0 for print string
		la $a0 , inputMsg # get txt "Enter a numer from 1 to 5:"
			syscall #print the message.
		ori $v0 , $0 , 5 #set syscall to read int
			syscall #read int
		la $t1 , userInp # put the address for num1 in s1
		sw $v0 , 0($t1) # store the users latest input in first word  userInp 0x10010000 
		add $t9 , $v0 , $0 # t9 holds our initial value
		addi $t8 , $0 , 6 # t8 = upper bound
		addi $t7 , $0 , 0 #t7 = lower bound # could have just used $0 but oh well
		
		#GUARUNTEE RANGES 
		slt $t1 , $t9 , $t8 #  INPUT < 6 -- 1:0
		slt $t2 , $t7 , $t9 # 0 < input -- 1:0
		# now compare that both conditions are true
		and $t3 , $t1 , $t2 # only if both true, then go
		beq $t3 , 1 , startloop # if conditions are true, keep going! you won!
		# if you dont jump above, it means you had bad input
		#display "Input is out of range" // inpError
		la $a0 , inpError # load the error message
		ori $v0 , $0 , 4 # set print syscall
			syscall #print "Input out of range\n" 
		bne $t3 , 1 , promptInput # if not true, try again
		
	
	startloop:
		jal printnewline #start each loop with a newline, to match output on assignment
		
		lw $s1 , userInp # get the users input value into S1
		slt $t0 , $s0 , $s1 # check that timeCount < userInp {1 : 0 }
		addi $s0 , $s0,  1 # increment counter AFTER 
		#$t0 = 1 means keep looping. == 0 means done
		bne $t0 , $0 , printTime #go to print time if not equal
		#if you get here, you are done.
		j end
		
	printTime:
		#print "Time = "
		ori $v0 , $0 , 4 # set print string
		la $a0 , timeMsg # get "Time = "
			syscall # print "Time = "
		#print "timeCount"
		or $a0 , $0 , $s0 # SET a0 = timeCount
		ori $v0 , $0 , 1 # SET V0 PRINT INT
			syscall #print timeCount
		jal printnewline # hit the newline and return here.
		j gettwoints 
		
	gettwoints: # STORE TWO USER INTS, FIRST = $S3 // SECOND == $S4
		ori $v0 , $0 , 4 # set to print string
		la $a0, inpFirst # get string "enter first number :
			syscall #print
		ori $v0 , $0 , 5 #get int from user
			syscall # get userinput 1 from usr
		addi $s3 , $v0 , 0 #set s3 to first int
		#jal printnewline # get a newline char
		#now get second in. 
		ori $v0 , $0 , 4 # set to print string
		la $a0, inpSecond # get string "enter second number :
			syscall #print
		ori $v0 , $0 , 5 #get int from user
			syscall # get userinput 2 from usr
		addi $s4 , $v0 , 0 #set s3 to first int
		#jal printnewline # print a newline
		#now we jump to the next one, even/odd
			j evenodd
	evenodd: # check the sum // two nums are $s3 and $s4, sum will be $s5
		add $s5 , $s3 , $s4 # add the ints to get sum in $s5
		 # i need to use my brain to determine this one!
		 #we can use AND 0x00000001 to determine if its odd
		 andi $t0 , $s5 , 0x0001 # will return 1 if odd / 0 if even
		 beq $t0, $0 printeven # if the remainder is 0, print even
		 j printodd # if nto even, must be odd, print off
		 
	printeven:
		ori $v0 , $0 , 4 #set print str
		la $a0 , even # load address for "even" string
			syscall #print
		j comparetwo #next function
		
	printodd:
		ori $v0 , $0 , 4 #set print str
		la $a0 , odd # load address for "odd" string
			syscall #print
		j comparetwo #next function
	
	comparetwo: # $s3 is input 1, $s4 is input 2
		sub $t0 , $s3 , $s4 # do subtraction to check for same number
		beq $t0 , $0 , printequal # if they are the same, print equal statement
		slt $t0 , $s3 , $s4  # check if first number is smaller
		bne $t0 , $0 , printless # print lessthan if not equal to zero (aka SLT evaluated true)
		beq $t0 , $0 , printgreater # print greater if evaluated false 
		
		
	printless:
		ori $v0 , $0 , 4 #set print str
		la $a0 , less # load address for "Less than \n" string
			syscall #print
		j startloop
	
	printgreater:
		ori $v0 , $0 , 4 #set print str
		la $a0 , greater # load address for "Greater than \n" string
			syscall #print
		j startloop
	
	printequal:
		ori $v0 , $0 , 4 #set print str
		la $a0 , equal # load address for "Equal \n" string
			syscall #print
		j startloop
	
	
			
	printnewline:
		#print "\n"
		ori $v0 , $0 , 4 #set print string
		la $a0 , newline  #load newline char
			syscall #print newline
		jr $ra # back to whence you came !!!
			
			
	end:
		ori $v0 , $0 , 4 # set print string
		la $a0 , complete
			syscall #print "Program Complete"
		ori $v0, $0 , 10 # set $v0 10 for quit program
			syscall #quit program
			

