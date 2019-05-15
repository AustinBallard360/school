
//CSE240 Spring 2019 HW10
// Luke Schulz
// VS


// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of books.
// Each book has name, number of copies and library type (hayden or noble).
// This information is stored as an object of Book class. Class defined in book.h
// The classes Hayden and Noble are child classes of the Book class.
// When adding a new book, these child classes are used to make the book node of the list.
// So each node in the list is actually an object of either Hayden or Noble class.

//
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// Do not modify given code.

// You can assume that all input is valid:
// Valid name:	String containing alphabetical letters
// Valid number: a positive integer

#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "book.h"
#include "noble.h"
#include "hayden.h"

using namespace std;

// functions already implemented:
void executeAction(char c);
Book* searchBook(string name_input);


// functions that need implementation:
void addBook(string name_input, int copies_input, libraryType type);			// 7 points
void displayList();							// 4 points
void save(string fileName);					// 7 points
void load(string fileName);					// 7 points

Container* list = NULL;				// global list

int main()
{
	char c = 'i';				// initialized to a dummy value

  // During first execution, there will be no list.txt in source directory. list.txt is generated by save() while exiting the program.
	load("list.txt");			
	do {
		cout << "\nCSE240 HW10\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new book\n";
		cout << "\t d: display book list\n";
		cout << "\t c: change copies of a book\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int copies_input;
	int type_input = 2;
	libraryType type;
	Book* bookResult = NULL;

	switch (c)
	{
	case 'a':	// add book
				// input book details from user
		cout << endl << "Enter book name: ";
		getline(cin, name_input);
		cout << "Enter number of copies: ";
		cin >> copies_input;
		cin.ignore();

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter book type: " << endl;
			cout << "0. Hayden " << endl;
			cout << "1. Noble" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (libraryType)type_input;

		// searchBook() will return the book object if found, else returns NULL
		bookResult = searchBook(name_input);
		if (bookResult == NULL)
		{
			addBook(name_input, copies_input, type);
			cout << endl << "Book added to list!" << endl << endl;
		}
		else
			cout << endl << "Book already present in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change number of copies
		cout << endl << "Enter book name: ";
		getline(cin, name_input);
		// searchBook() will return the book node if found, else returns NULL
		bookResult = searchBook(name_input);
		if (bookResult == NULL)
		{
			cout << endl << "Book not in list!" << endl << endl;
		}
		else
		{
			// if book exists in the list, then ask user for new number of copies
			cout << endl << "Enter new number of copies: ";
			cin >> copies_input;
			cin.ignore();

			// Q3c Call changeNoOfCopies() here   (1 point)
			bookResult->changeNoOfCopies(bookResult, copies_input); // use book pointer to access change copies function and pass same book pointer as param
			// 'bookResult' contains the book whose 'copies' is to be changed.
			// 'copies_input' contains the new copies of the book.
			// Call the function with appropriate arguments.


			cout << endl << "Number of copies changed!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// No implementation needed here, however it may be helpful to review this function
Book* searchBook(string name_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parse till end of list
	{
		if (tempList->book->getName() == name_input)
		{
			return tempList->book;	// return the book if found
		}

		tempList = tempList->next;		// parse the list
	}

	return NULL;						// return NULL if book not found in list
}

// Q3b: Define Friend Function changeNoOfCopies()  (3 points)
// Define the function changeNoOfCopies()that is declared in book.h file.
// This function sets the new 'copies' of the book. The book object and new number of copies is to be passed as function arguments.
// Use 'd' display option after using 'c' option to verify.
// You will need to implement add() and displayList() before you test this function.
void Book::changeNoOfCopies(Book* b, int newCopies) {
	b->copies = newCopies; // change objects copies attribute via pointer. ( should work for both child classes )
}

// Q4: addBook  (7 points)
// This function is used to add a new book to the global linked list 'list'. You may add the new book to head or tail of the list. (Sample solution adds to tail)
// libraryType 'type' can be hayden or noble. You will need to use the function argument �type� to determine which constructor to use to create new book node.
// For example, if the user enters type as 'noble', then you need to use Noble class and constructor to create new book node and add it to the list.
// NOTE: In executeAction(), searchBook() is called before this function. Therefore no need to check here if the book exists in the list.
//       See how this fucntion is called in case 'a' of executeAction()

void addBook(string name_input, int copies_input, libraryType type) 
{
	// CONTAINER OBJECT HAS TWO MEMBERS
		// BOOK POINTER
		// NEXT POINTER 
	Container* tempList = list;				// work on a copy of 'list'

	if(tempList == NULL){// case that this is first addition
		tempList = new Container; // make our first object
		if (type == 0) { // case is hayden
			Hayden* hBook = new Hayden(name_input, copies_input, type); // create hayden object & pointer ?
			tempList->book = hBook; // point our container book to actual book
			tempList->next = NULL; 
		}
		else { // catch all, in case of bad type will assign to noble
			Noble* nBook = new Noble(name_input, copies_input, type); // create noble object & pointer ?
			tempList->book = nBook; // point our container book to actual book
			tempList->next = NULL; 
		}
		list = tempList; // make this thing our head.
		return; // end empty list case
	} // end empty list case

	// all other cases ( list is not empty);
	Container* newCont = new Container(); // create our fresh container object;
	while (tempList->next != NULL) { // move thru list
		tempList = tempList->next; // move to end of list for tail insert
	}
	// now we are at the end of 
	if (type == 0) { // case is hayden
		Hayden* hBook = new Hayden(name_input, copies_input, type); // create hayden object & pointer ?
		newCont->book = hBook; // point our container book to actual book
		newCont->next = NULL;
	}
	else { // catch all, in case of bad type will assign to noble
		Noble* nBook = new Noble(name_input, copies_input, type); // create noble object & pointer ?
		newCont->book = nBook; // point our container book to actual book
		newCont->next = NULL;
	}
	tempList->next = newCont; // our newContainer is now at the end of the list!
}

// Q5: displayList	(4 points)
// This function displays the list of book and their details (name, copies, library name)
// Parse the list and use the class member function to display the book info.
// See expected output in the question file.


void displayList()
{
	Container *tempList = list;			// work on a copy of 'list'
	cout << endl;	
	while (tempList != NULL) { // while we have a real container object.
		tempList->book->displayBook(); // show that book
		tempList = tempList->next; // iterate thru list
	} // no more containers! done
}

// Q6: save  (7 points)
// Save the linked list of books to a file list.txt using ofstream.
// You will need to save the number of books in linked list. That will help in load() when reading the file.
// One format to store is:
// <no. of books>
// <Boook1 name>
// <Boook1 copies>
// <Boook1 type>
// <Boook2 name>
// <Boook2 copies>
// <Boook2 type>
// and so on..
// You may store the list in another format if you wish. You need to read the file in load () the same way that it is saved in save().
// This function is called when exiting the program (end of main() ).
// Hint: You may want to cast the enum �libraryType� to an int before writing it to the file.


void save(string fileName)
{
	// first count total list items
	int count = 0;
	Container* tempList = list; // work on copy of list ;)
	while (tempList != NULL) { // get our total count of books
		count++;
		tempList = tempList->next; // move thru list
	}

	ofstream myFile;  // declare File variable
	myFile.open(fileName); // open txt file
	if (myFile.is_open()) { // check success
		tempList = list; // reset templist to head
		myFile << count << endl; // save our count to file
		while (tempList != NULL) { // move thru linked list
			myFile << tempList->book->getName() << endl; // save data to file
			myFile << tempList->book->getCopies() << endl;
			myFile << tempList->book->getLibraryType() << endl;

			tempList = tempList->next; // iterate thru linked list
		} // end data save loop
		myFile.close(); // close data file
		return;
	} // end if file open
	else { cout << "Problem saving! " << endl; } // print error to user if file save didnt go.
}

// Q7: load (7 points)
// Load the linked list of books from the file using ifstream.
// You will need to create the linked list in the same order that is was saved to the file in save().
// First, read the number of books saved in the file.
// Then, for every book you will need to create a new Book node depending on book type. You may add the book to head or tail of the list. 
// This function is called at the beginning of main().
// Hint: If you casted the enum 'libraryType' to an int, you will need to cast it back to 'libraryType' when making the book node.
//		Check if the file really opened, then read from the file.

void load(string fileName) // load list.txt
{
	int count = 0; // count var 
	string bookName; // vars for holding out input from file
	int bookCopies; // we will gather them all for each book
	int type; // then use them as parameters for book constructor // WE USE INT HERE? FSTREAM DOESNT LIKE ENUM TYPE ??? // OR STRING ?!?!

	Container* tempList = list; // get list head pointer
	// we can assume that this will always start with an empty list... ?

	ifstream myFile; // declare file type var;
	myFile.open(fileName); // open our list.txt file
	if (myFile.is_open()) { // if we successfully open the file
		myFile >> count; // get our count value from file
		for (int i = 0; i < count; i++) { // loop thru save file 
			Container* temp = new Container(); // create new Contact container object
			temp->next = NULL; // set container next to null

			myFile.ignore(); // clear the last newline
			getline(myFile, bookName ); // get whole line preserve whitespace
			myFile >> bookCopies;
			myFile >> type; // get LIBRARY TYPE AS INT

			// now we have all our book info we can construct a Book object;
			if(type == 0){//hayden case
				temp->book = new Hayden(bookName, bookCopies, hayden); // create new Book object and place pointer in container also
			}else{ // will catch all non hayden instances including bad input
				temp->book = new Noble(bookName, bookCopies, noble); // create new book object in container
			}
			if (list == NULL) { // in case of first addition
				list = temp; // set first node to head.
				tempList = list; // reset our tempList to point to the head also
			}else{ // in case of all other additions
				while (tempList->next != NULL) { // while have real nodes
					tempList = tempList->next; // move to end of list
				}
				// now we are at the tail of list;
				tempList->next = temp; // place our new container at the end of the list
			}
		} // end for i count
		myFile.close(); // close file

	} // end if file is open
} // end save