#include <iostream>
#include <fstream>
#include <string>
//#include "test.h"

using namespace std;

	int qmax = 0 , dmax = 0 , nmax = 0 , pmax = 0;
	int comboCounter = 0;
	int tempTotal = 0;
	int trueTotal = 0;
	long loopcount = 0;

	int prompt() {
		cout << "Please choose a number of Monies (in pennies). \n We will find all possible change combinations for that amount.\n";
			cin >> trueTotal; // get user input
			if( trueTotal> -1 && trueTotal < 100000 && cin.fail() == false ){ // check that input is valid positive integer
				return 1; // valid integer input, continue
			} else{ // input was negative, too large, or non int
				cout << "You trying to break my program bro! Get out of here! \n"; // error message 2 user
				cout << "You entered " << trueTotal; // debug info
				return 0; // return with fail
			}
	}

int main(){
	
	while(prompt() != 0 ){
		qmax = trueTotal / 25; // get maximum number of each denomination based off user inputed total
		dmax = trueTotal / 10;
		nmax = trueTotal / 5;
		pmax = trueTotal;
		comboCounter = 0; // reset on each run
		
		
		for(int q = 0 ; q <= qmax ; q++ ){ // outter loop, goes four times. test each ammount of possible quarters.
			for( int d = 0 ; d <= dmax ; d++) { // inner loop, runs 10 times per quarter
				for( int n = 0 ; n <= nmax ; n++){ // inner loop, runs 20 times per dime
					for( int p = 0 ; p <= pmax ; p++){ // inner loop, runs 100 times per nickel ( so this will run 100p*20n*10d*4q) should run 80k times
						tempTotal = (q*25 + d*10 + n*5 + p*1);
						loopcount++;
						if(tempTotal == trueTotal){
							comboCounter++;
							cout << "One solution is " << q << "quaters & " << d <<" dimes & " << n << " nickles & " << p << " pennies \n";
						}
					} // end pennies, final inner
				}// end nickles loop
			} // end dimes loop
		} // end quarters outter
		cout << "Total # of solutions for "<< trueTotal <<  " pennies is " << comboCounter;
		cout << "\nTotal loops done is " << loopcount << endl;
		
	} // end quit block
	cout << "Thank you, goodbye!\n";
	
} // end main
