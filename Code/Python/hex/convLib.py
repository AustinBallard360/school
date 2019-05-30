hex2Bin = {	# DEFINE EACH HEX NUMBER TO CORRESPENDING BINARY SEQUENCE
	"0" : "0000" ,
	"1" : "0001" ,
	"2" : "0010" ,
	"3" : "0011" ,
	"4" : "0100" ,
	"5" : "0101" ,
	"6" : "0110" ,
	"7" : "0111" ,
	"8" : "1000" ,
	"9" : "1001" ,
	"a" : "1010" ,
	"b" : "1011" ,
	"c" : "1100" ,
	"d" : "1101" ,
	"e" : "1110" ,
	"f" : "1111"
}
hex2Dec = {	# DEFINE EACH HEX NUMBER TO CORRESPENDING BINARY SEQUENCE
	"0" : "0" ,
	"1" : "1" ,
	"2" : "2" ,
	"3" : "3" ,
	"4" : "4" ,
	"5" : "5" ,
	"6" : "6" ,
	"7" : "7" ,
	"8" : "8" ,
	"9" : "9" ,
	"a" : "10" ,
	"b" : "11" ,
	"c" : "12" ,
	"d" : "13" ,
	"e" : "14" ,
	"f" : "15"
}
bin2Hex = { # GIVE 4 binary string get hex
	"0000" : "0",
	"0001" : "1",
	"0010" : "2",
	"0011" : "3",
	"0100" : "4",
	"0101" : "5",
	"0110" : "6",
	"0111" : "7",
	"1000" : "8",
	"1001" : "9",
	"1010" : "a",
	"1011" : "b",
	"1100" : "c",
	"1101" : "d",
	"1110" : "e",
	"1111" : "f"
}
bin2Dec = { # GIVE 4 binary string get hex
	"0000" : "0",
	"0001" : "1",
	"0010" : "2",
	"0011" : "3",
	"0100" : "4",
	"0101" : "5",
	"0110" : "6",
	"0111" : "7",
	"1000" : "8",
	"1001" : "9",
	"1010" : "10",
	"1011" : "11",
	"1100" : "12",
	"1101" : "13",
	"1110" : "14",
	"1111" : "15"
}
dec2Hex = { # GIVE 4 binary string get hex
	"0" : "0",
	"1" : "1",
	"2" : "2",
	"3" : "3",
	"4" : "4",
	"5" : "5",
	"6" : "6",
	"7" : "7",
	"8" : "8",
	"9" : "9",
	"10" : "a",
	"11" : "b",
	"12" : "c",
	"13" : "d",
	"14" : "e",
	"15" : "f"
}
Dec2Bin = {	# DEFINE EACH HEX NUMBER TO CORRESPENDING BINARY SEQUENCE
	"0" : "0000" ,
	"1" : "0001" ,
	"2" : "0010" ,
	"3" : "0011" ,
	"4" : "0100" ,
	"5" : "0101" ,
	"6" : "0110" ,
	"7" : "0111" ,
	"8" : "1000" ,
	"9" : "1001" ,
	"10" : "1010" ,
	"11" : "1011" ,
	"12" : "1100" ,
	"13" : "1101" ,
	"14" : "1110" ,
	"15" : "1111"
}

def menu(count):
	if ( count < 1):
		print("\n\nWelcome to Hex Converter!")
	print("\n\nPlease enter a menu option!")
	print("\t 1 => Hex to Binary")
	print("\t 2 => Binary to Hex")
	print("\t 3 => Binary to Decimal")
	print("\t 4 => Decimal to Binary")
	print("\t 5 => Decimal to Hex")
	print("\t q => Quit the program")


	choice = input(">> ")
	#choice = str(choice)
	return choice

def handleMenu(choice):
	if(choice == "1"):
		hexToBinary() # do conversion function
	elif(choice == "2"):
		binaryToHex()
	elif(choice == "3"):
		binaryToDec()
	elif(choice == "4"):
		decimalToBinary()
	elif(choice == "5"):
		decimalToHex()
	elif(choice == "q"):
		quit()		# quit python


def hexToBinary(): # take integer input and convert it to hex
	quitFlag = 0
	while True: # infinite loop for checking input arguments
		try:
			userHex = input("Please give a Hex Number to convert to Binary !\n>>") # GET USER INT ( as a string tho)
			if(userHex == "q"):
				quitFlag = 1
				break
			#print("Your Hex Numer ==> : ", userHex) # check for input	
			userHexList = list(userHex.lower()) 
			for x in range(len(userHexList)): # SANITIZE ?
				if userHexList[x] in ['g', 'h' , 'i' , 'j', 'k' , 'l' , 'm', 'n' , 'o' , 'p', 'q', 'r','s','t','u','v','w','y','z',' ','!','@','#','$','%','^','&','*','(',')','{','}']:
						raise Exception("notHex")
			break
		except:
			print("Input was not proper Hex Format, Hex Values include 0-9 and A-F\n\n")
	if(quitFlag == 1):
		quit()

	print("Your Hex Number ==>: ", userHexList)

	usrBinList = [] # empty list for storing converted binary value
	cnt = len(userHexList) # should be size of hex List

	for x in userHexList: # for each hex value in our List
		usrBinList.append(hex2Bin[x]) # add its corresponding binary value to our new binaryList

	print("Binary Conversion ==>: ", usrBinList)# show results

def hexToDecimal():
	x = 4

def binaryToHex():
	quitFlag = 0
	posCount = 0
	usrHexLst = [] # to be filled
	fourNums = "" # our dictionary of binary to hex is in four digit increments, so we will "decode" four digits at a time
	fourCount = 0; # counter to keep us on track for four nums at once

	while True: # loop get input untill proper input
		try:
			usrBin = input("Please give a Binary Number to convert to Hex ! \n>>") # get user binary input
			if(usrBin == "q"): # QUIT MID INPUT BLOCK
				quitFlag = 1
				break # quit input loop on quit

			usrBinList = list(usrBin) # convert to list like [1 , 0 , 1 , ...]
			lstSize = len(usrBinList) # get size of users input as list
			lstRemainder = lstSize % 4 # check if neatly breaks into increments of four
			if (lstRemainder != 0): # if not increments of four
				while posCount < 4-lstRemainder: # do until is four
					usrBinList.insert(0 , "0") # add zeroes on the front 1 ---> 0001 ## for dictionary conversion of bin2Hex
					posCount += 1 # count

			for x in usrBinList: # go thru each input check for == 1 || 0 only
				
				fourCount+=1 # count
				fourNums = fourNums + x # string concat list items
				if(fourCount == 4): # if four in block
					usrHexLst.append(bin2Hex[fourNums]) # fill up user output list with dictionary conversion of 4 digits
					fourCount = 0 # reset 4 count
					fourNums = "" # reset fourString

				if(x != '1' and x != '0'): # check for bad input
					raise Exception("NotBinary") # throw error for bad input

			break # if for loop completes without any NotBinary exception, break out of While True loop

		except Exception as errr: #any errors, catch them
			print(errr , " Error, Input was not proper binary, please use only 1 OR 0\n\n") # print error, ==> retake input again

		

	if (quitFlag == 1): # check flag to quit program
		quit() 
	print("Given Binary Number ==> " , usrBinList) # show them their input
	print("Conversion to Hex ==> ", usrHexLst) # show them their output

def binaryToDec():
	binCount = 1
	decTotal = 0
	errorFlag = 0
	usrBinList = []

	while True: # loop get input untill proper input
		try:
			usrBin = input("Please give a Binary Number to convert to Decimal ! \n>>") # get user binary input
			if(usrBin == "q"): # QUIT MID INPUT BLOCK
				quitFlag = 1
				errorFlag = 1
				break # quit input loop on quit

			usrBinList = list(usrBin) # convert to list like [1 , 0 , 1 , ...]
			for x in usrBinList:
				if(x != '1' and x != '0'): # check for bad input
					raise Exception("NotBinary, use 1 and 0 please") # throw error for bad input
					break
				decTotal += int(x) * (2 ** (len(usrBinList) - binCount )) # math to get decimal from binary
				binCount += 1
			break

		except Exception as error:
			print("You recieved an error, its this ------> " , error)
			errorFlag = 1
			break

	if(errorFlag != 1):
		print("Given Binary Number ==> " , usrBinList) # show them their input
		print("Conversion to Decimal ==> ", decTotal) # show them their output

def decimalToBinary():
	errorFlag = 0
	usrDec = 0
	usrBinLst = []
	usrOriginal = 0
	while True: # loop get input untill proper input
		try:
			usrDec = int(input("Please give a Integer to convert to Binary! \n>>")) # get user binary input
			usrOriginal = usrDec
			if(usrDec == "q"): # QUIT MID INPUT BLOCK
				quitFlag = 1
				errorFlag = 1
				break # quit input loop on quit
			print("usrDec is ==> ", usrDec)
			if(usrDec == 0): # zero case
				usrBinLst.append(0) # return zero
			while(usrDec != 0 ): # divide by two until users number is 0
				decModTwo = usrDec % 2 # result to be stored
				usrDec =  usrDec // 2  # next to be operated
				usrBinLst.insert(0 , decModTwo) # insert result as most significant bit 
			print("Given Decimal ==>  " , usrOriginal) # display original input
			print("Conversion to Binary ==> ", usrBinLst) # display binary results
			break

		except Exception as error:
			print("You recieved an error, its this ------> " , error)
			errorFlag = 1
			break

def decimalToHex():
	errorFlag = 0
	usrDec = 0
	usrOriginal = 0
	usrHexLst = []
	while True: # loop get input untill proper input
		try:
			usrDec = int(input("Please give a Integer to convert to Binary! \n>>")) # get user binary input
			usrOriginal = usrDec
			if(usrDec == "q"): # QUIT MID INPUT BLOCK
				quitFlag = 1
				errorFlag = 1
				break # quit input loop on quit
			if(usrDec == 0): # zero case
				usrHexLst.append(0) # return zero
			while(usrDec != 0 ): # divide by two until users number is 0
				decModTwo = usrDec % 16 # result to be stored
				hexOut = dec2Hex[str(decModTwo)]
				usrDec =  usrDec // 16  # next to be operated
				usrHexLst.insert(0 , hexOut) # insert result as most significant bit 
			print("Given Decimal ==>  " , usrOriginal) # display original input
			print("Conversion to Hex ==> ", usrHexLst) # display hex results
			break

		except Exception as error:
			print("You recieved an error, its this ------> " , error)
			errorFlag = 1
			break



