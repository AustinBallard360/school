

#ifndef _NOBLE_H_
#define _NOBLE_H_
#include <string>
// Q1b: Create Noble class (5 points)
using namespace std;


// Part 1: Create a child class of the Book class named 'Nobel'
class Noble : public Book { // IS A BOOK

public:
	// Part2: Declare constructor which accepts the same 3 parameters as the parent class Book's constructor.
	// Pass the 3 parameters to the super constructor of the Book class.
	Noble(string bookName, int noOfCopies, libraryType libType) : Book(bookName, noOfCopies, libType) // call base class constructor. (IDK  if this class has unique members ???)
	{
		// things unique to Nobel class..... none so far ???
	}; // end constructor

	// Part 3: Re-declare the method displayBook (virtual method found inside of parent class Book)
	virtual void displayBook();

}; // end class

#endif // _NOBLE_H_