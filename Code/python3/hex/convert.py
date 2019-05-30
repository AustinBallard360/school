#!/usr/bin/env python3
# this is to convert hex files
# THIS WORKS ON PYTHON 3 ONLY. THE input() type casting is different on PYTHON 2 :( 

import convLib # THIS HOLDS ALL THE FUNCTIONS. I AM WRITING AS MUCH AS I CAN FuncTIONALLY !!!!!!

################ BEGIN MAIN ####################################
control = 1 #flag for program loop
count = 0 # count program iterations
while control == 1: # loop for keeping program running
	# make the program go
	
	choice = convLib.menu(count)
	convLib.handleMenu(choice)
	count=1 # could do +=1 to actually keep count, figured this more efficient ?


