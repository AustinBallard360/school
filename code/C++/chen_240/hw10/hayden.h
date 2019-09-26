
#ifndef _HAYDEN_H
#define _HAYDEN_H
#include <string>
using namespace std;
// Q1a: Create Hayden class (5 points)

// Part 1: Create a child class of the Book class named 'Hayden'
class Hayden : public Book { // IS A BOOK

	public:
		// Part2: Declare constructor which accepts the same 3 parameters as the parent class Book's constructor.
		// Pass the 3 parameters to the super constructor of the Book class.
		Hayden(string bookName, int noOfCopies, libraryType libType) : Book(bookName, noOfCopies, libType) // call base class constructor. (IDK  if this class has unique members ???)
		{
			// things unique to hayden class..... none so far ???
		}; // end constructor

		// Part 3: Re-declare the method displayBook (virtual method found inside of parent class Book)
		virtual void displayBook();
		
}; // end class








#endif // _HAYDEN_H