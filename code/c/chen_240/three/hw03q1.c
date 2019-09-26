//CSE240 Spring 2019 HW3

// LUKE SCHULZ
// Visual Studio

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]);
void encryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void decryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
int splitAndPrintSentences(char s[NUM_STRINGS*STRING_LENGTH]);
void inputMatrix(int matrixA[3][3]);
void determinant(int matrixA[3][3]);

// Problem 1: initializeStrings (5 points)
// Traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 35 column 2D array full of null terminators.
// The null terminator is represented by the character value '\0' and is used to denote the end of a string.
// This may come in use later in the program to know the end of string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	int rowCount = 0, columnCount; // vars for looping thru arrays
	while (rowCount < NUM_STRINGS) { // for each of the four rows
		columnCount = 0;
		while (columnCount < STRING_LENGTH) { // loop thru all the columns in each row. ( nested )
			strings[rowCount][columnCount] = '\0'; // set char to desired value
			columnCount++; // move to next column
		} // end nested column loop
		rowCount++; // move to next row
	} // end top row loop
	// void, no return.
}

// Problem 2: printStrings (5 points)
// Traverse the 2D character array "strings" and print each of the contained strings.
// See the example outputs provided in the word document. Your output should match the example outputs.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	// i feel like i could copy and past the above code to loop thru the arrays again but i want to write it w/ for loops this time
	int i, j; // counters for loops // i == ROW COUNT // j == COLUMN COUNT
	for (i = 0; i < NUM_STRINGS; i++) { // go thru each row
		for (j = 0; j < STRING_LENGTH; j++) { // go thru each column
			if(strings[i][j] != '\0') // dont print if == null 
				printf("%c", strings[i][j]);
		} // end column loop
		printf("\n"); // NewLine after each string / row
	}// end row loop
}

// Problem 3: reverseString (5 points)
// Reverse each string of strings[][]. 
// Consider one string at a time and reverse the characters. For instance, "hi hello" should reverse to "olleh ih".
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	int rowCount, colCount; // declare index counters
	for (rowCount = 0; rowCount < NUM_STRINGS; rowCount++) {
		strrev(strings[rowCount]); // reverse string / row
	}// end rows loop

}

// Problem 4: encryptStrings (5 points)
// Traverse the 2D character array 'strings' and encrypt each string in 2 steps as follows-
// 1) Reverse the string. 
// Hint: Use 'reverseStrings()' for this step. 
// 2) Then shift those ASCII characters forward by the integer value of 'key'.
// If the string is "hello" and key = 2, reversing will get you "olleh" and adding key to it will result in "qnnfj"
// If the value of 'key' is large, you will extend past the alphabetical characters and reach non-alphabetical characters. Thats ok.

// NOTE: DO NOT encrypt the null terminator character. Use the null terminator '\0' to find the end string.
// *** NOTE: If you were unable to code for reverseStrings(), then skip that step in this function and simply shift the characters ahead by 'key'.
//			While decrypting in the next function, you will again have to skip the reversing part. You will get partial points in that case.	
void encryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	int rowCount, colCount; // for looping thru array
	reverseStrings(strings); // reverse all strings

	//now shift forward 'key'
	for ( rowCount = 0; rowCount<NUM_STRINGS ; rowCount++){ //go thru rows
		// no action at row level goto columns
		for (colCount = 0; colCount < STRING_LENGTH; colCount++) { // go thru columns
			if (strings[rowCount][colCount] != '\0') // if not null
				strings[rowCount][colCount] = (strings[rowCount][colCount] + key); // add key value to char value (char + int OK ?? )
		} // end columns loop
	}// end rows loop
	
}
// Problem 5: decryptStrings (5 points)
// HINT: This should be very similiar to the encryption function defined above.
// Traverse the 2D character array 'strings' and decrypt each string in 2 steps as follows- 
// 1) Shift those ASCII characters backward by the integer value of 'key'.
// 2) Then reverse the string.
// Hint: Use 'reverseStrings()' for this step.
// *** NOTE: If you were unable to code for reverseStrings(), then skip that step in this function and simply shift the characters backward by 'key'.
//			You will get partial points in that case.
void decryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{	//started from copy paste
	int rowCount, colCount; // for looping thru array
	//reverseStrings(strings[NUM_STRINGS][STRING_LENGTH]); // reverse all strings

	//now shift BACKWARD 'key'
	for (rowCount = 0; rowCount < NUM_STRINGS; rowCount++) { //go thru rows
		// no action at row level goto columns
		for (colCount = 0; colCount < STRING_LENGTH; colCount++) { // go thru columns
			if (strings[rowCount][colCount] != '\0') // if not null
				strings[rowCount][colCount] = (strings[rowCount][colCount] - key); // SUBTRACT key value to char value (char - int OK ?? )
		} // end columns loop
	}// end rows loop
	reverseStrings(strings); // reverse the strings.
}

// Problem 6: splitAndPrintSentences (10 points)
// Split s[] into individual sentences and store them in str[][].
// Read s[] character by character and copy into str[][], such that sentence 1 is in str[0][], sentence 2 is in str[1][] and so on.
// Print the char array str[][], so that you will print the separated sentences. Finally return the number of sentences in 'count'
// Dont forget to initialize str[][] with nulls.
// Hint: Sentences are separated by full-stop.

int splitAndPrintSentences(char s[NUM_STRINGS*STRING_LENGTH])
{
	char str[NUM_STRINGS][STRING_LENGTH];
	int charCount = 0; // counter goes thru whole input string.
	int sentanceCharCount = 0; // count way thru each sentance, rest on period / full stop
	int count = 0; // count number of sentances. increment on full stop
	initializeStrings(str);
	
	// this while loop goes thru the input string and breaks it into multiple strings
	while (charCount < 200) { // go thru each character in the string
		if (s[charCount] == '\0') {
			printf(" I BROKE ! \n");
			break;
		}
		if (count < 4) { // this is hackey, but i was getting stack errors from i think going into str[4+][x] 
			str[count][sentanceCharCount] = s[charCount]; // write into new sub strings
		}
		
		if (str[count][sentanceCharCount] == '.') { // on period increment count
			sentanceCharCount = 0; // reset so that the next str[x] starts at str[x][0]
			count++; // move to next sentance / str[x++]
		}
		sentanceCharCount++; // increment position in sub sentence. ( after conditional checks)
		charCount++; // increment charcoutn at end
	} // end while

	//now print the string // USE THE FUNCTION WE ALREAYD MADE, DUH
	printStrings(str); // print em
	
	return count; // just the number of sentances.

}

// Problem 7: inputMatrix (10 points)
// Ask the user for each element of the 3X3  matrix and store the elements in "matrixA[][]"
// Display the matrix in the following form:
// matrixA =
// 1 2 3
// 4 5 6
// 7 8 9
// The user may input any inetgers for matrix elements, not necessarily same as example above.
void inputMatrix(int matrixA[3][3])
{
	// no need for new array?
	int rcount, ccount; // count rows and columns
	for (rcount = 0; rcount < 3; rcount++) { // loop thru rows
		for (ccount = 0; ccount < 3; ccount++) { // loop thru columns
			printf("Enter matrix element [%d][%d] : ", rcount, ccount); // print prompt
			scanf("%d", &matrixA[rcount][ccount]); // take int and store it in matrix. (I know it said not to use addresses and pointers but.... this is how i found it in my research.
		}// end column loop ( nested)
	}// end row loop
	printf("\nmatrixA = \n");
	printf("%d ", matrixA[0][0]);
	printf("%d ", matrixA[0][1]);
	printf("%d \n", matrixA[0][2]);
	// lazy mans way to print, im sure i could loop more.
	printf("%d ", matrixA[1][0]);
	printf("%d ", matrixA[1][1]);
	printf("%d \n", matrixA[1][2]);

	printf("%d ", matrixA[2][0]);
	printf("%d ", matrixA[2][1]);
	printf("%d \n", matrixA[2][2]);
}

// Problem 8: determinant (5 points)
// Calculate the determinant of the 3x3 matrix "matrixA[][]" and print it.
// Read about how to caclualte the determinant of 3x3 matrix. Here is a video tutorial: https://www.khanacademy.org/math/algebra-home/alg-matrices/alg-determinants-and-inverses-of-large-matrices/v/finding-the-determinant-of-a-3x3-matrix-method-2
// Since it is strictly a 3x3 matrix, you may use hardcoded indices. For eg- matrixA[0][0] to access 1st element of the matrix
void determinant(int matrixA[3][3])
{
	int  det = 0;
	int a = matrixA[0][0], b = matrixA[0][1], c = matrixA[0][2]; // get co-efficient or cofactors or w/e
	int det1 = 0;  
	det1 = ((matrixA[1][1] * matrixA[2][2]) - (matrixA[1][2] * matrixA[2][1])); // find the sub determinant 1/3 

	int det2 = 0;
	det2 = ((matrixA[1][0] * matrixA[2][2]) - (matrixA[1][2] * matrixA[2][0])); //sub determinant 2/3

	int det3;
	det3 = ((matrixA[1][0] * matrixA[2][1]) - (matrixA[1][1] * matrixA[2][0])); // sub det 3/3 
	
	det = ((a * det1) - (b * det2) + (c * det3)); // do the rest of formula
	
	printf("\nDeterminant of matrix = %d\n", det);
}

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char sentences[NUM_STRINGS*STRING_LENGTH];
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key, count;
	char input[STRING_LENGTH];
	int matrixA[3][3];						// 3x3 int array for matrix

	printf("CSE240 HW3: 2D Character Arrays\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter string for encryption: "); // prompt for string
		fgets(input, sizeof(input), stdin); // store input string
		input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input); // copy input to 2D strings array
	}

	printf("\nEnter a key value for encryption: "); // prompt for integer key
	scanf("%d", &key);

	encryptStrings(strings, key);
	printf("\nEncrypted Strings:\n");
	printStrings(strings);
	decryptStrings(strings, key);
	printf("\nDecrypted Strings:\n");
	printStrings(strings);

	i = getchar(); // remove the character '\n'
	printf("\nEnter sentences(max 4): ");
	fgets(sentences, sizeof(sentences), stdin); // store string
	input[strlen(sentences) - 1] = '\0';			// convert trailing '\n' char to '\0' (null terminator)
	count = splitAndPrintSentences(sentences);
	printf("\nNumber of sentences= %d \n", count);

	printf("\nCSE240 HW3: 2D Integer Arrays\n\n");
	inputMatrix(matrixA);
	determinant(matrixA);

	i = getchar(); // remove the character '\n'
	i = getchar(); // keep console open in VS
	return 0;
}