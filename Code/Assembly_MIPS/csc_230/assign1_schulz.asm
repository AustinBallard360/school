#LUKE SCHULZ
#CLASS ID == 155
#ASSIGNMENT 1


.data
.word 0 # @ 0x10010000
.word 0 # @ 0x10010004
.word 0 # @ 0x10010008
.globl main #idk why this does not take a memory address?
.asciiz "Luke" #5 chars 0x1001000c 
.asciiz "Enter a number " # 16 chars # @ 0x10010011
.asciiz "\n" # 2 chars @ 0x10010021

.text
main: # begin programm
	addi $s0, $0, 35 # set $s0 = 35 (decimal i think?)
	lui  $a0, 0x1001 # set $a0 to 0x10010000 for memory addressing
	addi $a0, $a0, 0x11 #move to memorry address 0x10010011
	
	addi $v0, $0, 4 # set $v0 to 4 for syscall print string function
		syscall # print "Enter a number "
		
	addi $v0, $0, 5 #set $v0 to 5 for "read int" syscall
		syscall #read int from user #int is now $v0
		add $s1, $v0, $0 # set $s1 to users input ($v0)
		
	addi $v0, $0 , 4 #reset $v0 to 5 for "print string" syscall
		syscall #print "enter number (same mem address as b4)
		
	addi $v0, $0, 5 #set $v0 = 5 for "read int" syscall
		syscall #read int from user
		add $s2, $v0, $0 # $s2 = user's 2nd int input
		
	lui $a0, 0x1001 #set memory address @ 0x10010000 (first word = 0)
		sw $s1, ($a0) # save the first user input into word at $a0 (0x10010000) ??
	
	addi $a0, $a0, 4 #set $a0 to 0x10010004 (second word)
		sw $s2, ($a0) # save the 2nd user input into 2nd word data @ $a0 (0x10010004)
		
	sub $t0, $s0 , $s1 # set temp $t0 = 35 - (user 1st input)
	add $t0, $t0 , $s2 # temp $t0 = 35 - (first inp) + (2nd input)
	
	addi $a0 , $a0, 4 #move the memory address forward 4 (now @ 0x10010008) aka 3rd .word
		sw $t0, 0($a0) # save the product of our math operations into our 3rd .word
		
	#Print each of follow on new line
	
	#a. Your name
	addi $v0, $0, 4 # set syscall print string
	addi $a0 , $a0 , 4 # reset memory pointed @ 10010000
		syscall
		
	#now we need to print a newline. 
	#NEW LINE COPY-PASTA
	addi $v0, $0, 4 # set syscall print string
	lui $a0 , 0x1001# set $a0 back to 1001
	addi $a0 , $a0 , 0x21 #point a0 back to newline asciiz
		syscall
		addi $v0 , $0 , 1 # reset syscall to print int at the end of each newline
	
	#b. First word @ 0x10010000
	lui $t1 , 0x1001 # set $t1 as 0x10010000 for use with loading the .word's
		lw $a0 0($t1) # load the word at 0x10010000 into $t2
			syscall 
	#NEW LINE COPY-PASTA
	addi $v0, $0, 4 # set syscall print string
	lui $a0 , 0x1001# set $a0 back to 1001
	addi $a0 , $a0 , 0x21 #point a0 back to newline asciiz
		syscall
		addi $v0 , $0 , 1 # reset syscall to print int at the end of each newline
		
	#c. 2nd word @ 0x10010004
		lw $a0, 4($t1)
			syscall
			
	#NEW LINE COPY-PASTA
	addi $v0, $0, 4 # set syscall print string
	lui $a0 , 0x1001# set $a0 back to 1001
	addi $a0 , $a0 , 0x21 #point a0 back to newline asciiz
		syscall
		addi $v0 , $0 , 1 # reset syscall to print int at the end of each newline
			
	#d. 3rd word @ 0x10010008
		lw $a0 8($t1)
			syscall
			
	#NEW LINE COPY-PASTA
	addi $v0, $0, 4 # set syscall print string
	lui $a0 , 0x1001# set $a0 back to 1001
	addi $a0 , $a0 , 0x21 #point a0 back to newline asciiz
		syscall
		addi $v0 , $0 , 1 # reset syscall to print int at the end of each newline
			
	#next, Exchange values in $s1 & $s2
	add $t1, $s1 , $0 # set t1 = s1
	add $t2, $s2 , $0 # set t2 = s2
	
	add $s2 , $t1 , $0 # set $s2 = old $s1
	add $s1 , $t2 , $0 # set $s1 = old $s2
	#finally set value $s0 = -($s0)
	
	sub $s0 , $0 , $s0 # idk if this works s0=(0-$s0)
		
		
		
		
		#**#*#*#*#*#* THIS IS ENDING  BLOCK #**#*#*#*#*#*
	addi $v0, $0, 10 #set syscall 10 = exit
		syscall # exit the program
		
		
	
	
	
	
	
