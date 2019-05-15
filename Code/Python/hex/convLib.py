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
	print("\t q => Quit the program")


	choice = input(">> ")
	#choice = str(choice)
	return choice

def handleMenu(choice):
	if(choice == "1"):
		hexToBinary() # do conversion function
	elif(choice == "2"):
		binaryToHex()
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

def binaryToHex():
	quitFlag = 0
	#print("Srry but i dont do anythin yet")
	#usrBin = input("Please give a Binary Number to convert to Hex ! \n>>")
	while True: # loop get input untill proper input
		try:
			usrBin = input("Please give a Binary Number to convert to Hex ! \n>>") # get user binary input
			if(usrBin == "q"): # QUIT MID INPUT BLOCK
				quitFlag = 1
				break # quit input loop on quit

			usrBinList = list(usrBin) # convert to list like [1 , 0 , 1 , ...]
			print(usrBinList, "THIS IS UR INPUT PEPE HANDS")
			for x in usrBinList: # go thru each input check for == 1 || 0 only
				print(type(x), "thats x type foooo")
				if(x != "1" | "0"):
					print(x , type(x) , "WHAT THE HECKERS ?!")
					raise Exception("NotBinary") # throw error for bad input
			break # if for loop completes without any NotBinary exception, break out of While True loop

		except Exception as errr:
			print(errr , "Input was not proper binary, please use only 1 OR 0\n\n") # print error, ==> retake input again

	if (quitFlag == 1): # check flag to quit program
		quit() 
	print(usrBinList)








