.data
word1: .word 0x10 # go to s1
word2: .word 0x01
word3: .word 0x0a
str1: .asciiz  "your number is \n"

.globl main
.text
main:
	lw $s1 , word1
	lw $s2 , word2
	lw $s3 , word3
	
	add $t1 , $s1 , $s2
	add $t2 , $s3 , $s2
	sub $t3, $s1 , $s2
	
	addi $v0 , $0 , 4
	la $a0 , str1
		syscall
		
	addi $v0 , $0 , 1
	add $a0 , $0 , $t1
		syscall
	add $a0 , $0 , $t2
		syscall
	add $a0 , $0 , $t3
		syscall