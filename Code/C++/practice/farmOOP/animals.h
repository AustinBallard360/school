#ifndef _ANIMALS_H_
#define _ANIMALS_H_

#include <string>
#include <iostream>
using namespace std;

enum animalType { cat = 0 , dog , bear, wolf};

class Animals {
    private:
        string name;
        int age;
        animalType type;
    public:
        Animals(string animalName , int animalAge , animalType aType );
        string getName();
        int getAge();
        animalType getType();

        void printAnimal();

    
    };

#endif