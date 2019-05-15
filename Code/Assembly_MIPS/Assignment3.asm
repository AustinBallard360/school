.data
num1: .word 0
num2: .word 0
answer: .asciiz "The product is "
prompt: .asciiz "Enter a positive number " # prompt
newline: .asciiz "\n" # newline for newline 
# add other strings at this point as needed
.text
.globl main
main:
	jal getpos # get a positive number for the loop
	addi $s0, $v0, 0 # save input value
	
	repeat:
	beq $s0, $0, end # while there are more repeats
	lui $a0, 0x1001 # get address of first word
	addiu $a1, $a0, 4 # get address of second word
	jal getinput # call function to get input, store into addresses
	lui $t0, 0x1001 # get address of first word
	lw $a0, 0($t0) # get the first value from memory
	lw $a1, 4($t0) # get the second value from memory
	jal multiply # multiply the values, result in $v0
	addi $a0, $v0, 0 # get value to print from $v0
	lui $a1, 0x1001 # get start of data section
	addi $a1, $a1, 8 # get start of the product output string
	jal print # print results
	addi $s0, $s0, -1 # decrement counter
	j repeat # do it again
	
	print: # function 1 goes here # PRINT STRING , THEN INT , THEN NEWLINE 
		#$a0 = int # $a1 = string
		add $t0 , $a0 , $0 # set $t0 to hold our int
		add $a0 , $a1 , $0 # set a0 to string address
		#the order is bad... we need $a1 first then $a0...
		ori $v0 , $0 , 4  #set to print string
			syscall #print the string 
		add $a0 , $t0 , $0 # set a0 to the integer
		ori $v0 , $0 , 1 # set to print int
			syscall #print the integer
		la $a0 , newline
		add $v0 , $0 , 4 # set to print string again
			syscall #print newline
		
	jr $ra
	
	multiply: # function 2 goes here !
	#t0 is control
		ori $t0 , $0 , 0 # set t0 = 0
		ori $v0 , $0 , 0 # set $v0 = 0

	multloop: # goes with multiplication.
	addi $t0 , $t0 , 1 # increment counter
		slt $t1 , $t0 , $a0 # set t1 = 1 if t1 < a0

		add $v0 , $v0 , $a1 # add the a1 a0 times (should mimic multiplication)
		#addi $t0 , $t0 , 1 # increment counter
		beq $t1 , 1 , multloop # if we have more loops to do, repeat
	
	jr $ra # if we are done, return. $v0 is our mult value
	
	getpos: # function 3 here
		la $a0, prompt #get prompt asci
		ori $v0 , $0 , 4 #print string syscall
			syscall # print prompt
		ori $v0 , $0 , 5 #read int
			syscall # get user int into v0
		slt $t0 , $0 , $v0 # 0 < X ? { 1 : 0 } 
		bne $t0 , 1 , getpos #if our number is negative, keep looping
	jr $ra # else return with our new $v0
	
	getinput: # function 4 go here ! 
	#$a0 address to store first val
	#$a1 address to store second val
		addi $sp , $sp ,  -12
		sw $ra , 0($sp) #save $ra to stack
		sw $a0 , 4($sp) # save first argument (address of word #1)
		sw $a1 , 8($sp) # save 2nd arg ( address of word #2
	
		jal getpos # get positive integer into $v0
		#sw $v0 , 0($a0) # store returned value into word 1
		add $s6 , $v0 , $0 # get our returned val into s6
		jal getpos # get 2nd pos integer into $v0
		#sw $v0 , 0($a1) # store returned value into word 2
		add $s7 , $v0 , $0 # get our 2nd return value into s7
	
		lw $ra , 0($sp) # get return address register val from stack
		lw $a0 , 4($sp) # load first argument of calling function ( address of word #1 )
		lw $a1 , 8($sp) # load 2nd arg of calling func (address of word # 2 )
		addi $sp , $sp , 12 # rest stack
		
		sw $s6 , 0($a0) # store returned value into word 1
		sw $s7 , 0($a1) # store returned value into word 2
	jr $ra
	
	end:
		ori $v0, $0, 10 # set command to stop program,
			syscall # end program