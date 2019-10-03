import base64
import string



counter=0
def encode(text):
    return base64.encodestring(text)

def decode(text):
    return base64.decodestring(text)

def encrypt(cleartext, key):
    to_return = bytearray(len(cleartext))
    for i in xrange(len(cleartext)):
        to_return[i] = ord(cleartext[i]) ^ ord(key[i % len(key)])
    return str(to_return)


def encryptXSmoll(cleartext , key , size):
	counter =0;
	to_return = bytearray(size)
	for i in xrange(size):
	    prereturn = ord(cleartext[i]) ^ ord(key[i % len(key)]) # gives an int
	    if chr(prereturn) not in alphaNumerSet:
	    	to_return[i] = 0
	    	counter+=1
	    	if(counter >0): # allow 10 errors
	    		return None # stop in tracks
	    else:
	   		to_return[i] = prereturn
	return str(to_return)



def printXSolutionSmoll(keyx):
	out = encryptXSmoll(decodedAlanTxt , keyx , 10)
	if (out == None):
		return
	else:
		print("Key => "+keyx+"  VAL=> "+out)

		#print(out)
# def saveKeys(idx , char):
# 	if (idx==10):
# 		set10.add(char)
# 	elif (idx==9):
# 		set9.add(char)
# 	elif(idx==8):
# 		set8.add(char)
# 	elif(idx==7):
# 		set7.add(char)
# 	elif(idx==6):
# 		set6.add(char)
# 	elif(idx==5):
# 		set5.add(char)
# 	elif(idx==4):
# 		set4.add(char)
# 	elif(idx==3):
# 		set3.add(char)
# 	elif(idx==2):
# 		set2.add(char)
# 	elif(idx==1):
# 		set1.add(char)


# set1=set("")
# set2=set("")
# set3=set("")
# set4=set("")
# set5=set("")
# set6=set("")
# set7=set("")
# set8=set("")
# set9=set("")
# set10=set("")
txtSize = 100;
alanFile = open("alan.txt" , "r")
alanTxt = alanFile.read()
decodedAlanTxt = decode(alanTxt)
alphaNumerSet = set(string.ascii_letters); # all the relevant characters for building a key
for digit in string.digits:
	alphaNumerSet.add(digit);
alphaNumerSet.add(" ")
for charx in string.punctuation:
	alphaNumerSet.add(charx)


progress=0
for x in alphaNumerSet:
	progress+=1
	print("progress is "+str(progress) +" / "+str(len(alphaNumerSet)))
	#key = x
	#printXSolutionSmoll(key , 1)
	for y in alphaNumerSet:
		#key = x+y
		#printXSolutionSmoll(key , 2)
		for z in alphaNumerSet:
			#key =x+y+z
			#printXSolutionSmoll(key , 3)
			for p in alphaNumerSet:
				#key = x+y+z+p
				#printXSolutionSmoll(key)
				for q in alphaNumerSet:
					key = x+y+z+p+q
					printXSolutionSmoll(key)

# for x in alphaNumerSet:
# 	key = x
# 	printXSolutionSmoll(key , 1)
# 	#makes set1

# for x in set1:
# 	for y in alphaNumerSet:
# 		key = x+y
# 		printXSolutionSmoll(key , 2)
# 		# makes set2

# for x in set1:
# 	for y in set2:
# 		for z in alphaNumerSet:
# 			key = x+y+z
# 			printXSolutionSmoll(key , 3)



# print("SET 1  " +str(set1))
# print(" SPACER ------------"+str(len(set1)))
# print("SET 2  " +str(set2))
# print(" SPACER ------------"+str(len(set2)))
# print("SET 3  " +str(set3))
# print(" SPACER ------------"+str(len(set3)))




