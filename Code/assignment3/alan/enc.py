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

# def encryptX(cleartext , key):
# 	counter =0;
# 	to_return = bytearray(len(cleartext))
# 	for i in xrange(len(cleartext)):
# 	    prereturn = ord(cleartext[i]) ^ ord(key[i % len(key)]) # gives an int
# 	    if chr(prereturn) not in alphaNumerSet:
# 	    	to_return[i] = 0
# 	    	counter+=1
# 	    	print(counter)
# 	    	#print("Failing char is "+chr(prereturn))
# 	    	if(counter >3): # allow 10 errors
# 	    		print("I failed")
# 	    		return None # stop in tracks
# 	    else:
# 	   		to_return[i] = prereturn
# 	return str(to_return)

def encryptXSmoll(cleartext , key , size):
	counter =0;
	to_return = bytearray(size)
	for i in xrange(size):
	    prereturn = ord(cleartext[i]) ^ ord(key[i % len(key)]) # gives an int
	    if chr(prereturn) not in alphaNumerSet:
	    	to_return[i] = 0
	    	counter+=1
	    	if(counter >3): # allow 10 errors
	    		return None # stop in tracks
	    else:
	   		to_return[i] = prereturn
	return str(to_return)
# def printSolution(keyx):
# 	out = encrypt(decodedAlanTxt , keyx)
# 	if (out == None):
# 		return
# 	else:
# 		print("Key => "+keyx + "  "+out)
# 		#print(out)



def printXSolutionSmoll(keyx):
	out = encryptXSmoll(decodedAlanTxt , keyx , 50)
	if (out == None):
		return
	else:
		print("Key => "+keyx +"   "+out)
		#print(out)


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


# teststr = encode(encrypt("this is a test", "12"))
# print(teststr);
# dectestsr = decode(teststr)
# print(dectestsr)
# print(encrypt(dectestsr , "12"))

# for x in alphaNumerSet:
# 	key = x
# 	printXSolution(key , dectestsr)
# 	for y in alphaNumerSet:
# 		key = x+y
# 		printXSolution(key , dectestsr)

# print(alphaNumerSet)

for x in alphaNumerSet:
	key = x
	printXSolutionSmoll(key)
	for y in alphaNumerSet:
		key = x+y
		printXSolutionSmoll(key)
		for z in alphaNumerSet:
			key =x+y+z
			printXSolutionSmoll(key)
			for p in alphaNumerSet:
				key = x+y+z+p
				printXSolutionSmoll(key)


# for x in alphaNumerSet:
# 	key = x
# 	printSolution(key)
# 	for y in alphaNumerSet:
# 		key = x+y
# 		printSolution(key)
# 		for z in alphaNumerSet:
# 			key =x+y+z
# 			printSolution(key)
		# 	for q in alphaNumerSet:
		# 		key =x+y+z+q
		# 		printSolution(key)
# 				for p in alphaNumerSet:
# 					key = x+y+z+q+p
# 					printSolution(key)






