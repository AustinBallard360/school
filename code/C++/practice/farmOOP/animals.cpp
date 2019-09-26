#include "animals.h"
#include <iostream>
#include <fstream>
#include <string>


// #include <iostream>
// #include <fstream>
// #include <string>

Animals::Animals(string animalName, int animalAge , animalType aType){
    name = animalName;
    age = animalAge;
    type = aType;
}

int Animals::getAge(){
    return age;
}

string Animals::getName(){
    return name;
}

animalType Animals::getType(){
    return type;
}

void Animals::printAnimal(){
    cout << "Name is : " << name << endl;
    cout << "Age is : " << age << endl;
    cout << "Type is : " << type << endl;

}
