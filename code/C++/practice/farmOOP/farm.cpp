#include <iostream>
#include <fstream>
#include <string>
#include "animals.h"

using namespace std;

Animals cat1 =  Animals("cat" , 13 ,  cat);
Animals dog1 = Animals("Dog" , 4 , dog);
Animals bear1 = Animals("Bear" , 5 , bear);
Animals wolf1 = Animals("Wolfie" , 2 , wolf);

// int arraySizeGet(Animals arr);

int main(){
    int arraySizeGet(Animals arr);

    Animals animalArray[] = {cat1 , dog1 , bear1 , wolf1};
    int size = sizeof(animalArray)/sizeof(animalArray[0]);
    //int size = arraySizeGet(animalArray);
    for(int c = 0 ; c < size ; c++ ){
        animalArray[c].printAnimal();
    }


}
//     int arraySizeGet(Animals arr){
//     int size = (sizeof(arr) / sizeof(arr[0]);
//     return size;
// }
