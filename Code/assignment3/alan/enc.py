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
	    	if(counter >5): # allow 10 errors
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
	uncheckedY = True
	uncheckedZ = True
	uncheckedP = True
	uncheckedQ = True

	key = x;
	progress+=1
	print("progress is "+str(progress) +" / "+str(len(alphaNumerSet)))

	if(checkXSolutionSmoll(key , 1) == None ):
		print("continue 1" + key + str(len(key)))
		continue

	for y in alphaNumerSet:
		key = x+y
		if uncheckedY == True:
			uncheckedY = False;
			uncheckedZ = True
			if(checkXSolutionSmoll(key , 1) == None):
				print("fail 2" + key + str(len(key)))
				break
			
		for z in alphaNumerSet:
			key = x+y+z
			if(uncheckedZ == True):
				uncheckedZ = False
				uncheckedP = True
				uncheckedY = True
				if(checkXSolutionSmoll(key , 2) == None):
					break
				
			for p in alphaNumerSet:
				key = x+y+z+p 
				if(uncheckedP == True):
					uncheckedP = False
					uncheckedQ = True
					uncheckedZ = True
					if(checkXSolutionSmoll(key , 3) == None):
						#print("fail 4" + key + str(len(key)))
						break
					
				for q in alphaNumerSet:
					key = x+y+z+p+q
					if(uncheckedQ == True):
						uncheckedQ = False
						uncheckedP = True
						if(checkXSolutionSmoll(key , 4) == None):
							break
						
					printXSolutionSmoll(key , 100)





