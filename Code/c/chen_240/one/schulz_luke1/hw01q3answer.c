#include <stdio.h>
#pragma warning(disable : 4996) // needed if using Visual Studio

// CSE 240 Fall 2018 Homework 1 Question 3 (20 points)
// Before starting this assignment, please compile and run this program. 
// You will first notice that the program will not compile. Fix the errors and define the error types.
// Next, you will notice that the program is printing incorrect information. Fix the errors and define those error types.

int main(){

	// Problem 1: (4 points)
	// The statement below should cause the program to not compile. Correct the error(s). (2 points).

	double p = 20.18;

	printf("p is equal to %f\n", p);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual, we declared it wrong \n\n"); 


	// Problem 2: (4 points)
	// Half of 50 is 25, why is the program printing that half of 50 is 0? Correct the error(s) (2 points).

	int q = 50;

	printf("Half of %d is %d\n", q, (q / 2));

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: semantic, because it was calculating correctly, just not what we meant to do\n\n");

     //Problem 3    (2 points)
     //Integer variable y is initialized to 100 and its value needs to be printed. Correct the error(s).(1 point)
   int y = 100;
   printf("y is %d\n",y); 
    // Your answer should be either Syntactic, Semantic, or Contextual. (1 point)
	printf("Error Type: syntactic \n\n");
     
     //Give your explanation here:
     printf("You need to use  %%d to print an integer. this is Syntax error because we simply called wrong command \n\n");
	// Problem 4: (2 points)
	// Float variable f has been initialized to 3.14, why does the program seem to think otherwise? Correct the error(s) (2 points).

	float f = 3.14;

	if (f == 10) // gotta use == 
	printf("f is equal to 10.\n");
	if (f > 10)
	printf("f is greater than 10.\n");
	if (f < 10)
	printf("f is less than 10.\n");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: this is semantic error. We were setting f to ten, but that was not our true intention \n\n");


	// Problem 5: (4 points)
	// Surely, 60 is an even number. Why is the program printing that 60 is an odd number? Correct the error(s) ( points).

	q = 60;

	if (q % 2 == 0) // this needs to be modulus or it wont work right? 60/2 = 30 ? // or check against 30 not 0
		printf("%d is an even number.\n", q);
	if (q % 2 != 0)
		printf("%d is an odd number.\n", q);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic, because we were just not doing the right logic. \n\n");


	// Problem 6: (4 points)
	// This bit of code is meant to print "Hello World!". Correct the error(s) (2 points).

	printf("Hello World!\n");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantics, because we were calling for Character variable, then just typing a string instead of using a declared char variable \n\n");
	printf("Enter any character to exit \n");
	getchar(); // so the program doesnt go away in visual studio
return 0;
}
