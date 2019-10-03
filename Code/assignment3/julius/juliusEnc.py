import base64
def encode(text):
    return base64.encodestring(text)

def decode(text):
    return base64.decodestring(text)

def encrypt(cleartext, key):
    to_return = bytearray(len(cleartext))
    for i in xrange(len(cleartext)):
        to_return[i] = ord(cleartext[i]) ^ key
    return to_return


#### PURE STRINGS INTO ENCRYPT ########
def main():

	julius=open("julius.txt" , "r")
	jtext = julius.read(); # get text


	# for x in range(0x100): #### This is the function I used to find the key (Brute Force)
	# 	print(hex(x))
	# 	print("-----------------")
	# 	print(encrypt(decode(jtext) , x) )

	decodedText = decode(jtext) # This is me verifying the key I found from brute force
	goodKey = encrypt(decodedText , 0xc6)
	print(goodKey)
	print(encrypt(decode("9OXz9A=="), 0x80))

main() # this is me running the program!


