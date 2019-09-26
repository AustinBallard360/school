// LUKE SCHULZ
/* CSC 240 HW2q2
1/26/19*/

#include <stdio.h>
int main() {
	// ATTEMPT TO DEFINE MY MACROS
#define subm(x,y) x-y
#define cubem(x) x*x*x
#define minm(x,y) ((x<=y) ? x : y )
#define oddm(x) ((x%2 == 1) ? 1 : 0)

	int a, b, mx, fx; // mx=MacroResult // fx = FunctionResult
	a = 5, b = 7;
	//do subf/m #1
	 fx =subf(a, b);
	 mx =subm(a, b);
	// print subf/m results
		printf("subf(a, b) = %d \n", fx);
		printf("subm(a, b) = %d \n", mx);
	
	// do subf/m #2
	fx = subf(a++, b--);
	a = 5; b = 7; // reset a,b values
	mx = subm(a++, b--);
		// print subf/m results # 2
		printf("subf(a++, b--) = %d \n", fx);
		printf("subm(a++, b--) = %d \n", mx);
	
	// do cubef/m #1
	a = 5; b = 7; // re-reset values
	fx = cubef(a);
	mx = cubem(a);
		//print cubef/m results
		printf("cubef(a) = %d \n", fx);
		printf("cubem(a) = %d \n", mx);

	// do cubef/m #2
	fx = cubef(--a);
	a = 5; b = 7;
	mx = cubem(--a);
		//print cubef/m #2
		printf("cubef(--a) = %d \n", fx);
		printf("cubem(--a) = %d \n", mx);

	// do minf/m #1
	a = 5; b = 7; //re-re-reset vars
	fx = minf(a, b);
	mx = minm(a, b);
		//print minf/m # 1
		printf("minf(a, b) = %d \n", fx);
		printf("minm(a, b) = %d \n", mx);

	// do minf/m # 2
	fx = minf(--a, --b);
	a = 5; b = 7;
	mx = minm(--a, --b);
		// print minf/m # 2
		printf("minf(--a, --b) = %d \n", fx);
		printf("minm(--a, --b) = %d \n", mx);
	
	//do oddf/m # 1
	a = 5; b = 7; // re-re-re-reset vars
	fx = oddf(a);
	mx = oddm(a);
	//print oddf/m # 2
		printf("oddf(a) = %d \n", fx);
		printf("offm(a) = %d \n", mx);

	// do oddf/m # 2
	fx = oddf(a++);
	a = 5; b = 7;
	mx = oddm(a++);
	//print oddf/m # 2
	printf("oddf(a++) = %d \n", fx);
	printf("oddm(a++) = %d \n", mx);



}// end main


int subf(int a, int b) {
	return a - b;
}
int cubef(int a) {
	return a * a * a;
}
int minf(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int oddf(int a) {
	if (a % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}