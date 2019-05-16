//CSE240 Spring 2019 HW4

// LUKE SCHULZ !!!!! 
// GCC !!!!

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers for this homework. 
// **** DO NOT use arrays to store or to index the characters in the string ****

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void encryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void decryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]);
char* reverseOneString(char s[STRING_LENGTH]);
int isPalindrome(char s[STRING_LENGTH]);

// Problem 1: initializeStrings (5 points)
// Use pointer p to traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	// I cant think how to do a set amount loop only using a pointer. Because we need to run a set amount of times and we cant check against value.
	// i will use an integer counter, i hope that is OK.
	int count;
	char *ptr = &strings[0][0]; // ptr is the ADDRESS
	for (count = 0; count < NUM_STRINGS*STRING_LENGTH; count++) { // go 200 times (4*50)
		*ptr = '\0'; // set the value of next string to \0
		ptr++; // point to next space in array.
	}

}// end initializeStrings()

// Problem 2: printStrings (5 points)
// Use pointer p to traverse the 2D character array "strings" and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char *ptr = &strings[0][0];
	int idx; // idk how to do these without at least one counter. 

	for (idx = 0; idx < NUM_STRINGS; idx++) { // once for each row / string
		printf("%s \n", ptr); // print string at result, stops on '\0' ---- ONLY works for initialized strings!!!!
		ptr = ptr + 50; // since strings are initialized, each individual string is 50 memory spaces. increment address pointer by 50
		// I could have printed by character, using a nested loop checking for '\0' instead, but that seemed to defeat the purpose
	} // end for

} // end printStrings()


// Problem 3: reverseOneString (15 points)
// Reverse the string s by using pointer.
// Use pointer p and 'temp' char to swap 1st char with last, then 2nd char with (last-1) and so on..
// Finally return pointer p which points to start of the reversed string.
// You may declare and use more pointers if needed.
// Hint: You might want to check if your logic works with even as well as odd length string.
//       You can write test code to print out the reversed string to check if your function works. (Don't include it in final submission)
char* reverseOneString(char s[STRING_LENGTH])
{
	char temp; 	// hold the of pointer when we overwrite it
	int count = 0; // counter
	char *p = &s[0];// pointer to start of string
	int size = strlen(s); // get the size of string
	char *q = &s[size - 1]; // should be index last non \0 char

	while (count < size / 2) { // should work with even and odd? 
		//begin juggle
		temp = *p; // assign value of *p to temporary variable
		*p = *q; // overwrite *p with current *q (old *p is safe in temp)
		*q = temp; // put original *p in *q
		//end juggle
		q--; // move ending pointer left
		p++; // move beginning pointer right (meet in middle)
		count++; // counter to end our loop
	}


	// FOR PRINTING TO TEST, PROLLY SHOULD DELETE
	p = &s[0]; // point back @ front of string?
	//printf("\n %s -RVERSE BOII \n", p);
	return p;

}

// Problem 4: reverseStrings (5 points)
// Reverse all the strings in 'strings[][]'
// For each string in 'strings', use the reverseOneString() to reverse it.
// You may declare and use more pointers if needed.
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char *ptr = &strings[0][0];
	int count = 0; // loop control
	while (count < NUM_STRINGS) {
		ptr = reverseOneString(ptr); // reverse string @ pointer location
		ptr = ptr + 50; // point to next string / row
		count++; // loop control
	} // end while


}

// Problem 5: encryptStrings (5 points)
// Use pointer ptr to traverse the 2D character array 'strings' and encrypt each string in 2 step as follows- 
// 1) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
// 2) Shift the characters forward by the integer value of 'key'.
// If the string is "hello" and key = 2, reversing will get you "olleh" and adding key to it will result in "qnnfj".
// Once the value of 'key' gets larger, you will extend past alphabetical characters and reach non-alphabetical characters. Thats ok.
// NOTE: DO NOT encrypt the null terminator character. Use the null terminator to find the end string.
//		If you could not implement reverseStrings(), skip using it in this function. You will receive partial credit.
void encryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char *p = &strings[0][0]; // this will be our char counter
	char *r = &strings[0][0]; // this will be our row counter
	int i = 0; // index counter so we dont 
	// enter code here
	reverseStrings(strings);
	while (i < NUM_STRINGS) {
		if (*p != '\0') { // go char by char, is value is not NULL TERMINATOR
			*p =(*p)+key;// +key; // VALUE of p incrimented by key
			p++; // increment pointer address
		} // end if NOT NULL
		else if (*p == '\0') { // if char is null
			r = r + 50; // set our row pointer to the next string. // i could probably just loop thru all 200 elements with only one pointer, but this should theoretically cut out looping thru most of the null chars
			i++; // loop control
			p = r; // reset our char pointer to the start of next string.
		} // end if NULL
	}// end while

} // end encryptStrings()

// Problem 6: decryptStrings (5 points)
// HINT: This should be very similiar to the encryption function defined above in encryptStrings().
// Use pointer p to traverse the 2D character array 'strings' and decrypt each string in 2 step as follows- 
// 1) Shift the characters backward by the integer value of 'key'.
// 2) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
// NOTE: DO NOT decrypt the null characters.
//		If you could not implement reverseStrings(), skip using it in this function. You will receive partial credit.
void decryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	//char *ptr = &strings[0][0]; // not needed

	// we literally just wrote this function, just negate the key so it reverts to original chars.
	// i refuse to re-write the function again.
	encryptStrings(strings, -key); // using ptr instead of strings gave warning in gcc

}

// Problem 7: isPalindrome (10 points)
// Return 1 if string s is palindrome.
// Parse through the string to check if 1st char==last char, 2nd char == (last-1) char, and so on..
// Return 1 if string is palindrome. Return 0 if string is not palindrome.
// A palindrome is a sequence of characters which when reversed, is the same sequence of characters.
// Palindrome string examples: rotor, noon, madam
// Note: you may use reverseOneString() here but it is not necessary to use it. 
int isPalindrome(char s[STRING_LENGTH])
{
	char *p = s; // point to start of string
	int palindrome = 1, count = 0; // ? for ?
	int size = strlen(s); // get the size of the array
	char *q = &s[size - 1];	// point to end (last non null char of string)	
	// enter code here
	while (count < size / 2) { // should work with even and odd? 

		if (*p != *q) { // if the value of mirror letters are not matching, word is not palindrom. end it !
			palindrome = 0; // return 0 for false.
			break; // stop looping, its over.
		} // end if
		else { // if the chars are equal,
			q--; // move ending pointer left
			p++; // move beginning pointer right (meet in middle)
			count++; // counter to end our loop
		}// end else
	} // end while

	return palindrome;
} // end isPalindrome()

// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key;
	char input[STRING_LENGTH];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	printf("\nEnter a key value for encryption: "); // prompt for integer key
	scanf("%d", &key);

	encryptStrings(strings, key);
	printf("\nEncrypted Strings:\n");
	printStrings(strings);
	decryptStrings(strings, key);
	printf("\nDecrypted Strings:\n");
	printStrings(strings);

	getchar();									// flush out newline '\n' char

	printf("\nChecking for palindrome. Enter a string: ");				// prompt for string
	fgets(input, sizeof(input), stdin);		// store input string
	input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)

	if (isPalindrome(input))
		printf("The string is a palindrome");
	else
		printf("The string is not a palindrome");

	getchar();									// keep VS console open
	return 0;
}