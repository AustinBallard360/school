#LUKE SCHULZ , 3/10/19 CSE 230 # ASSIGNMENT # $
#CLASS # 151

.data
numarray: .word 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 # 10 slot number array
numaddress: .word 0
newline: .asciiz "\n" # newline
name: .asciiz "Luke Schulz " # my name
numprompt: .asciiz "Enter a number "
count: .word 0 # our counter

## end data
.text
.globl main

#function #1
main: 
	#print name
	ori $v0 , $0 , 4 # set to print string
	la $a0 , name # get "Luke Schulz"
		syscall #print
	jal printNewLine
	
	# call readvals
	la $a0 , numarray # load parameter for readval arugement
	sw $a0 , numaddress # save our address pointer
	jal readvals # go to readvals(&numarray)
	#at this point, $s1 == COUNT && $s0 == &numarray
	add $a0 , $0 , $s0 # // $a0 == &numarray
	add $a1 , $0 , $s1 # $a1 == COUNT
	jal print # call print function print(a0= &array , $a1=COUNT)	
	
	j quit # or else it will hit the jump return infinitely on the printNewLine funciton lol!!


#function #2
readvals: #int readvals(&numarray = $a0)
	add $s0 , $0 , $a0  # s0 = &numarray (free up $a0)
	lw $s1 , count # s1 = count (GET)
	
	getInt:
		la $a0 , numprompt # load "Enter a number " prompt
		ori $v0 , $0 , 4 # set syscall print string
			syscall #print prompt
		ori $v0 , $0 , 5 # set syscall for read int
			syscall # $v0 = INT input
		j checkInput # now that we have gotten an int, check it.

	
	storeInt: # assume int in $v0
		add $t0 , $0 , $s0 # get the address of our array
		add $t1 , $0 , $s1 #t1 = count
		add $t1 , $t1 , $t1 # t1= double our count
		add $t1 , $t1 , $t1 # t1= (4x count). (each count is 4 bytes)
		add $t0 , $t0 , $t1 # $t0 is address of array[count]
		sw $v0 ,0($t0) # save user input into numarray[count]
		
		j incrementCount # increment the count now that we have stored to array
		
	incrementCount:
		addi $s1 , $s1 , 1 #increment count by 1
		sw $s1 , count #SET count = $s1
		j getInt # get int again, now that we have finished a cycle
		
	checkInput: #assume user input still in $v0
		slti $t0 , $v0,  0 # ($v0 < 0) ? { 1 : 0} // check if negative input
		bne $t0 , $0 , stopCase # negative input case 
		#else , user input is postive and OK!
		slti $t0 , $s1 , 10 # ($s1 < 10 ) ? { 1 : 0 } #check if count is below ten
		beq $t0 , $0 , stopCase # array @ 10 / full 
		#now is positive input, with array room available.
		
		j storeInt # store the int now that we have checked it
		
		
	stopCase: # we either got a negative number, or our array is full
		add $v0 , $0 , $s1 # set $v0 to COUNT, return COUNT
		jr $ra # end readvals()
		
	
#function #3
average: #float average(&array , count)
### REMEMBER, $S0 == $a0 == &arrray ///////// $s1 == $a1 == COUNT
	addi $t0 , $0 , 0 # t0 = loop counter == 0
	add $t1 , $0 , $a0 # t1 equals &array
	ori $t4 , $0 , 0 #$t4 is TOTAL 
	addNums:
		slt $t3 , $t0 , $a1 # (loopCount < totalCount) ? { 1 : 0}
		#IS THIS WHERE TO ADD TOTAL ??? IDK
		lw $t5 , 0($t1) # get the VALUE from numarray[loopcount]
		add $t4 , $t4 , $t5 # add the running total AND the current value 
		beq $t3 , $0 division # CASE WE ARE DONE ADDING
		addi $t1 , $t1 , 4 # increment to the next address in array
		addi $t0 , $t0 , 1 # increment our loop counter
		j addNums # go again
	division: # $t5 = TOTAL // $f4 = COUNT
	#need $f0 =  TOTAL / COUNT
		mtc1 $t4 , $f6 # get TOTAL into float mode 
		mtc1  $s1 , $f4 # get COUNT into float mode
		cvt.s.w $f6 , $f6 # $65 = TOTAL
		cvt.s.w $f4 , $f4 # $f4 = COUNT
		div.s $f0 , $f6 , $f4 # f0 = TOTAl/COUNT 
		#return $f0 is our average
	jr $ra # back to caller (print)
	

#function #4
print: #void print(&array , count)
### REMEMBER, $S0 == $a0 == &arrray ///////// $s1 == $a1 == COUNT
	addi $sp , $sp , -4 # only store $ra for now ?
	sw $ra , 0($sp) # save $ra to stack
	
	addi $t0 , $0 , 0 # t0 = print loop counter
	add $t1 , $0 , $a0 # t1 equals &array
	printOneNum:
		slt $t3 , $t0 , $s1 # (loopCount < totalCount) ? { 1 : 0}
		beq $t3 , $0 doAverage
		addi $v0 $0 , 1 #set syscall to print int
		lw $a0 , 0($t1) #set print argument to numarray[loopcount]
			syscall #print the int
		addi $t1 , $t1,  4 #increment to the next integer
		addi $t0 , $t0 ,  1 #icrement the loop counter
		jal printNewLine # print a newline also (custom function w/ stack, preserves everything)
		j printOneNum # go again
	
	doAverage:# set up and then call our average function once we are done printing the array
		add $a0 , $0 , $s0 # // $a0 == &numarray // # get the registers input as the instructions require
		add $a1 , $0 , $s1 # $a1 == COUNT
		jal average #do the average calculation	
	printAvg:
		ori $v0 , $0 , 2 # syscall argument for printing single.float
		mov.s $f12 , $f0 # copy our average (f0) to our print location (f12)
			syscall
		
	printStop:

		lw $ra , 0($sp) # load RA from stack
		addi $sp , $sp , 4 #clean up stack pointer
		jr $ra # back to main


#my own newline function
printNewLine:
	addi $sp, $sp, -8 # get space for $a0 , $v0 (the two registers we will use to print newline only)
	sw $a0 , 0($sp) # save the incoming $a0
	sw $v0 , 4($sp) # save incoming $v0 
	
	la $a0 , newline
	add $v0 , $0 , 4 # set to print string again
		syscall #print newline
		
	lw $a0 , 0($sp) # restore values
	lw $v0 , 4($sp) # restore val
	addi $sp , $sp , 8 # clean up stack pointer
	
	jr $ra
	
quit: # ending function
	addi $v0 , $0 , 10 # set to syscall quit
		syscall # quit program clean
		
		
		
		
		
		
