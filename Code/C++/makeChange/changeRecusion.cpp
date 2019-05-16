#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	int qmax = 0 , dmax = 0 , nmax = 0 , pmax = 0;
	int comboCounter = 0;
    int bigCount = 0;
	//int tempTotal = 0;
	int trueTotal = 0;
	long loopcount = 0;
    int pcount = 0;
    int dcount = 0;
    int ncount = 0;
    int qcount = 0;

	int prompt() {
		cout << "Please choose a number of Monies (in cents (no decimal)). \n We will find all possible change combinations for that amount.\n";
			cin >> trueTotal; // get user input
			if( trueTotal> -1 && trueTotal < 100000 && cin.fail() == false ){ // check that input is valid positive integer
				return 1; // valid integer input, continue
			} else{ // input was negative, too large, or non int
				cout << "You trying to break my program bro! Get out of here! \n"; // error message 2 user
				cout << "You entered " << trueTotal; // debug info
				return 0; // return with fail
			}
	}
    int getCombos(int Quarters, int Dimes, int Nickles, int Pennies){ // this does not need to be an int, Im just counting the bigCount in a static variable. int type literally useless
    // all the return values literally do nothing. should be void
        int tempCount = 0; // tally the total of change per recusion
        loopcount++; // show me how many recursions

        if(Pennies >=0 && Nickles >=0 && Dimes >= 0 && Quarters >= 0){ //  if you are not negative on any of your elements, proceed.
             getCombos(Quarters, Dimes, Nickles, Pennies-1 ); // recursion with one less cent (Will pass -1 pennies eventually) that triggers the next condition
        }
        else if(Pennies < 0 && Nickles >= 0){ // this means you have done all reall combos of 100 pennies are @ -1 pennies, recurse next less denomination & force break
             getCombos( Quarters , Dimes , (Nickles - 1) , pmax); // we went thru 100 pennies, now lose a dime and go thru 100 more times
            return 0; // this is not a real run, because it had -1 pennies
        }
        else if(Nickles < 0 && Dimes >= 0 ){ // if we run thru all nickles (-1 nickles is passed) then remove a dime and reset nickles {
            //cout << "\n\n I WAS PASSED Q = " << Quarters << " D = " <<Dimes << " N = " << Nickles << " P = " << Pennies <<"\n"; // BIG DEBUGGER HERE LOOOL
            getCombos( Quarters , (Dimes - 1) , nmax , pmax ); // recurse with one less dime, and full nickles full pennies
             return 0; // not a real run, had -1 nickles (signals we need to stop dropping nickles and drop a dime.)
        }
        else if(Dimes < 0 && Quarters >= 0){ // passed -1 dimes, time to rest dimes and remove a quarter.
            getCombos( (Quarters-1) , dmax , nmax , pmax); // recurse with one less quarter, full everything else.
            return 0; // not a real run, had -1 Dimes
        }
        else if(Quarters < 0){ // we passed -1 quarters, we are done.
            return 0; // not a real run.
            cout <<" how many XD \n"; // you cant print after a return luke so dumb
        } // end conditional block
        tempCount = (25 * Quarters + 10*Dimes + 5*Nickles +  1*Pennies );
        if (tempCount == trueTotal ){
            bigCount++;
            
            cout << "One solution is " << Quarters << "quaters & " << Dimes <<" dimes & " << Nickles << " nickles & " << Pennies << " pennies \n";
            return 1; // this function is now our combo counter!!! PogU ! it will add one if true
            // this function is now our combo counter!!! PogU ! it will add one if true
        } else{
           // cout << " BIG FAIL ON THAT ONE PAL \n";
            return  0 ; // we did not have a match, add nothing to total.
        }
    } // end getCombos

int main(){
	
	while(prompt() != 0 ){
		qmax = trueTotal / 25; // get maximum number of each denomination based off user inputed total
		dmax = trueTotal / 10;
		nmax = trueTotal / 5;
		pmax = trueTotal;
        cout <<" qmax == " <<qmax << " dmax == " << dmax << "nmax == " <<nmax <<"pmax == " <<pmax << "\n"; 
		comboCounter = getCombos(qmax , dmax , nmax , pmax);

		cout << "Total # of solutions for "<< trueTotal <<  " cents is " << bigCount;//comboCounter;
		cout << "\nTotal recursions done is " << loopcount << endl;
		
	} // end quit block
	cout << "Thank you, goodbye!\n";
	
} // end main