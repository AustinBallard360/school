// Include necessary header files
#include <iostream>
#include <fstream>
#include <string> 
//#include "Container.h"
#include "book.h" // ??? needed ???
#include "noble.h"
//#include "hayden.h"

#define LIBNAME  "Noble" //macro for displaying library name as text

void Noble::displayBook() { // define virtual function for this child class
	string name = Noble::getName(); // use accessor methods to get all of our data
	int copies = Noble::getCopies();
	libraryType libType = Noble::getLibraryType();

	// now display data for user for one book of NOBLE class
	cout << "Book name: " << name << endl;
	cout << "Copies: " << copies << endl;
	cout << "Library: " << LIBNAME << endl;
	cout << "\n"; // newline 4 pretty display


}
// Q2b: Define displayBook() for Noble class (5 points)
// Define the function displayBook() that you declared within the Noble class in the header file
// See expected output in question file.

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files


