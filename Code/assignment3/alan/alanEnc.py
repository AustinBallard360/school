#LUKE SCHULZ
import base64
import string

def encode(text):
    return base64.encodestring(text)

def decode(text):
    return base64.decodestring(text)

# def encrypt(cleartext, key):
#     to_return = bytearray(len(cleartext))
#     for i in xrange(len(cleartext)):
#         to_return[i] = ord(cleartext[i]) ^ ord(key[i % len(key)]) # EXPECTS KEY AS STRING of INTS for math yo
#     return str(to_return)
def encryptX(cleartext, key):
    to_return = bytearray(len(cleartext))
    for i in xrange(len(cleartext)):
        #to_return[i] = ord(cleartext[i]) ^ ord(key[i % len(key)]) # EXPECTS KEY AS STRING of INTS for math yo
        pre_return = ord(cleartext[i]) ^ ord(key[i % len(key)]) # EXPECTS KEY AS STRING of INTS for math yo
        if(sanitize(chr(pre_return)) == None):
        	return
        else:
        	to_return[i] = ord(cleartext[i]) ^ ord(key[i % len(key)]) # EXPECTS KEY AS STRING of INTS for math yo
        #print(chr(to_return[i]));
    return str(to_return)


def encryptSmoll(cleartext , key, sizeChunk):
	return None

# def encryptSmoll(cleartext, key , sizeChunk):
#     to_return = bytearray(sizeChunk)
#     for i in xrange(sizeChunk):
#     	pre_return = ord(cleartext[i]) ^ ord(key[i % len(key)])
#     	#print(str(pre_return))
#     	if sanitize(chr(pre_return)) != None:
#     		to_return[i] = pre_return
#     	else:
#     		#print(" LOOK WHAT I DID -->" +str(to_return));
#     		return "NA";
#         #to_return[i] = ord(cleartext[i]) ^ ord(key[i % len(key)]) # EXPECTS KEY AS STRING of INTS for math yo
#     print(str(to_return))
#     return str(to_return)

def sanitize(char):
	if char in alphaNumerSet:
		return char
	else:
		return None

# END GIVEN
#Phase Zero, the text
txtSize = 100;
alanFile = open("alan.txt" , "r")
alanTxt = alanFile.read()
decodedAlanTxt = decode(alanTxt)
alphaNumerSet = set(string.printable); # all the relevant characters for building a key


def twoDigitKeys(): #phase 4.8976 guess and check to the extreme begins.
	count = 0;

	for x in alphaNumerSet:
		key = x
		#encryptSmoll(decodedAlanTxt , key , txtSize)
		#printSolution(key)
		for y in alphaNumerSet:
			key = x+y
			print(encryptX(decodedAlanTxt , key))
			#printSolution(key)
			
			for z in alphaNumerSet:
				key =x+y+z
				print(encryptX(decodedAlanTxt , key))
				printSolution(key)

				for q in alphaNumerSet:
					key =x+y+z+q
					print(encryptX(decodedAlanTxt, key))
				


def printSolution(keyx):
	potentialOutput = encryptSmoll(decodedAlanTxt , keyx , txtSize);
	if potentialOutput == "NA":
		print("Key = keyx");
		print(potentialOutput);

#twoDigitKeys();
#encryptX(decodedAlanTxt , "12")
print(decodedAlanTxt)

