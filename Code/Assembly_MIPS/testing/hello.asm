.data
.word 43 #stored @ 0x10010000
.asciiz "Hi Erick, How long can my strings be?? I really dont know\n" #each of these strings is 3 characters plus 0 terminator = 4 bytes #@0x10010004
.asciiz "My\n" # i did that on purpose so that the +4 to $a0 moves the memory address forward between them.
.asciiz "Dog" # you can change the length of these strings and observe the behavior to understand how the memory works

.text
main:
	lui $a0, 0x1001 # initialize my data blox to 0x10010000
	addi $a0, $a0 , 4 # skip first word and go to  mem addr 0x10010004
	addi $v0 , $0, 4 #set syscall v0 to option #4 print string
		syscall # run the system call and print string
	addi $a0, $a0 , 4 # add four more and go to next asciiz \n @ 0x10010008
		syscall
	addi $a0 , $a0 , 4 # now at 0x1001000c
		syscall
	addi $v0 , $0 , 10 # set system call to close program
		syscall
	
