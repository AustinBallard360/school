// Luke Schulz
// 4/25/19
// ASU ID# = 1211984746
// 240 Tu-Th 4:30

#include <string>
#include <iostream>

using namespace std;


int foo(int x, int y){ // size n problem

    if (y<=0){ // stopping condition #1
        return x;
    }
    if( x<= 0){ // stopping condition #2
        return y;
    }

    if(x>=y){ // size m solution
        return ( x + foo(x-1 , y - 2));
    }
    if( x < y){// size m solution 2
        return ( y + foo(x-2, y-3));
    }
}

int main(){
    cout << "foo(5 , 6 ) = " ;
    cout << foo(5,6);

} // end main
