import base64
import string


set1 = set()
set2 = set()
set3 = set()
set4 = set()
set5 = set()
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
alphaNumerSet = set(string.printable); # all the relevant characters for building a key
set1= set(['\t', '\x0b', '\n', '\r', '\x0c', '!', ' ', '#', '"', '%', '$', "'", '&', ')', '(', '+', '*', '-', ',', '/', '.', '1', '0', '3', '2', '4', '7', '6', '9', '8', ';', ':', '=', '<', '?', '>', 'A', '@', 'C', 'G', 'F', 'a', '`', 'c', 'b', 'e', 'd', 'g', 'f', 'i', 'h', 'k', 'j', 'm', 'l', 'o', 'n', 'q', 'p', 's', 'r', 'u', 't', 'w', 'v', 'y', 'x', '{', 'z', '}', '|', '~'])
set2= set(['\t', '\x0b', '\n', '\r', '\x0c', ';', ':', '=', '<', '?', 'A', '@', 'C', 'B', 'E', 'D', 'G', 'F', 'H', 'K', 'J', 'M', 'L', 'O', 'N', 'Q', 'P', 'S', 'R', 'U', 'T', 'W', 'V', 'Y', 'X', '[', 'Z', ']', '\\', '_', '^', 'a', '`', 'c', 'b', 'e', 'd', 'g', 'f', 'i', 'h', 'k', 'j', 'm', 'l', 'o', 'n', 'q', 'p', 's', 'r', 'u', 't', 'w', 'v', 'y', 'x', '{', 'z', '}', '|', '~'])
set3= set([' ', '$', '(', ',', '0', '4', '8', '<', '@', 'D', 'H', 'L', 'P', 'T', 'X', '\\', '`', 'd', 'h', 'l', 'p', 'x', '|', '#', "'", '+', '/', '3', '7', ';', '?', 'C', 'G', 'K', 'O', 'S', 'W', '[', '_', 'c', 'g', 'k', 'o', 's', 'w', '{', '"', '&', '*', '.', '2', '6', ':', '>', 'B', 'F', 'J', 'N', 'R', 'V', 'Z', '^', 'b', 'f', 'j', 'n', 'r', 'v', 'z', '~', '!', '%', ')', '-', '1', '5', '9', '=', 'A', 'E', 'I', 'M', 'Q', 'U', 'Y', ']', 'a', 'e', 'i', 'm', 'q', 'u', 'y', '}'])
set4 = set([' ', '$', '(', ',', '0', '4', '8', '<', '@', 'D', 'H', 'L', 'P', 'T', 'X', '\\', '`', 'd', 'h', 'p', 't', 'x', '|', '#', "'", '+', '/', '3', '7', ';', '?', 'C', 'G', 'K', 'O', 'S', 'W', '[', '_', 'c', 'g', 'k', 'o', 's', 'w', '{', '"', '&', '*', '.', '2', '6', ':', '>', 'B', 'F', 'J', 'N', 'R', 'V', 'Z', '^', 'b', 'f', 'j', 'n', 'r', 'v', 'z', '~', '!', '%', ')', '-', '1', '5', '9', '=', 'A', 'E', 'I', 'M', 'Q', 'U', 'Y', ']', 'a', 'e', 'i', 'm', 'q', 'u', 'y', '}'])
progress=0

for x in set1:
	# key = x;
	# progress+=1
	# print("progress is "+str(progress) +" / "+str(len(alphaNumerSet)))

	# if(checkXSolutionSmoll(key , 1) != None ):
	# 	set1.add(x)

	for y in set2:
		# key = x+y
		#if(checkXSolutionSmoll(key , 2) != None):
			#set2.add(y)

		for z in set3:
			# key = x+y+z
			#if(checkXSolutionSmoll(key , 3) != None):
				#set3.add(z)
			for p in set4:
			 	# key = x+y+z+p 
			 	# if(checkXSolutionSmoll(key , 4) != None):
			 	# 	set4.add(p)
			 for q in alphaNumerSet:
			 	key = x+y+z+p+q
			 	if(checkXSolutionSmoll(key , 5) != None):
			 		set5.add(q)

print("set 1")
print(set1)
print("size = " +str(len(set1)) )
print("set 2")
print(set2)
print("size = " +str(len(set2)) )
print("set 3")
print(set3)
print("size = " +str(len(set3)) )
print("set 4")
print(set4)
print("size = " +str(len(set4)) )
print("big charset => "+str(alphaNumerSet) + "length => " +str(len(alphaNumerSet)))



