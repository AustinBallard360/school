/* This C program demonstartes switch statements w/ using breaks */
/* This C program was dilligently copied by LUKE SCHULZ 1/17/19 */
/* this file was copied from hw01q2 as a base*/
#include <stdio.h>
int main() {
	char ch;
	int a = 10, b = 20, i;
	double f;
	char prompt[100] = "Enter math operation :";

	for (i = 0; i < 5; i = i + 1) {
		printf("%s", prompt);
		ch = getchar();
		getchar();
		printf("ch = %c\n", ch);

		switch (ch) {
		case '+': f = a + b; printf("f = %.0f\n", f);break;
		case '-': f = a - b; printf("f = %.0f\n", f);break;
		case '*': f = a * b; printf("f = %.0f\n", f);break;
		case '/': f = a / b; printf("f = %.0f\n", f);break;
		default: printf("invalid operator\n"); break;
		}// end switch
		fflush(stdin);
	}// end for loop
	return 0;
} // end main
// this is a comment. we are done here boys