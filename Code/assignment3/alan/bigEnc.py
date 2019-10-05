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
	    	if(counter >10): # allow 10 errors
	    		return None # stop in tracks
	    else:
	   		to_return[i] = prereturn
	return str(to_return)



def printXSolutionSmoll(keyx , size):
	out = encryptXSmoll(decodedAlanTxt , keyx , size)
	if (out == None):
		return None
	else:
		print("Key => "+keyx+"  VAL=> "+out)
		return 1
def checkXSolutionSmoll(keyx , size):
	out = encryptXSmoll(decodedAlanTxt , keyx , size)
	if (out == None):
		return None
	else:
		return 1




alanFile = open("alan.txt" , "r")
alanTxt = alanFile.read()
decodedAlanTxt = decode(alanTxt)
txtSize = len(decodedAlanTxt);
alphaNumerSet = set(string.printable); # all the relevant characters for building a key
# for digit in string.digits:
# 	alphaNumerSet.add(digit);
# alphaNumerSet.add(" ")
# for charx in string.punctuation:
# 	alphaNumerSet.add(charx)

fullLength = len(decodedAlanTxt)
progress=0
for x in alphaNumerSet:
	progress+=1
	print("progress is "+str(progress) +" / "+str(len(alphaNumerSet)))

	for y in alphaNumerSet:
		for z in alphaNumerSet:	
			for p in alphaNumerSet:
				for q in alphaNumerSet:
					key = x+y+z+p+q
					printXSolutionSmoll(key , fullLength)





