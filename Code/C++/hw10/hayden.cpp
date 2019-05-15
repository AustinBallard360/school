// Include necessary header files
#include <iostream>
#include <fstream>
#include <string> 
//#include "Container.h"
#include "book.h" // ??? needed ???
//#include "noble.h"
#include "hayden.h"
// Q2a: Define displayBook() for Hayden class (5 points)
// Define the function displayBook() that you declared within the Hayden class in the header file
// See expected output in question file.
#define LIBNAME "Hayden"
void Hayden::displayBook() { // define virtual function for this child class
	string name = Hayden::getName(); // use accessor methods to get all of our data
	int copies = Hayden::getCopies();
	libraryType libType = Hayden::getLibraryType();

	// now display data for user for one book of hayden class
	cout << "Book name: " << name << endl;
	cout << "Copies: " << copies << endl;
	cout << "Library: " << LIBNAME << endl;
	cout << "\n"; // newline 4 pretty display


}


// (displayList() function in hw10.cpp should call this function.)

