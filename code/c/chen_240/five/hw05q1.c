
// CSE240 Spring 2019 HW5
// LUKE SCHULZ
// VISUAL STUDIO ! 

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of patients, like patients' record.
// Each record has this information: patient's name, doctor's name, critical level of patient, room number.
// The struct 'patientRecord' holds information of one patient. Critical level is enum type.
// An array of structs called 'list' is made to hold the list of patients.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_PATIENTS 15
#define MAX_NAME_LENGTH 25

typedef enum { very_critical = 0, critical, not_critical } criticalType; // enum type 
// 0 - 1 - 2 <WORSE , BAD , OK > 

struct patientRecord {					// struct for patient details
	char patientName[MAX_NAME_LENGTH]; // 25 char array for name 
	char doctorName[MAX_NAME_LENGTH]; // 25 char array for name
	criticalType criticalLevel; // defType => 0 , 1 , 2 
	unsigned int roomNumber; // i wonder why unsigned ???
};

struct patientRecord list[MAX_PATIENTS]; // declare list of patients (size = 15 patients)
int count = 0;							// the number of patients currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* patientName_input, char* doctorName_input, char* criticalLevel_input, unsigned int roomNumber_input); // 20 points
void display();				// 10 points
void sort();				// 10 points
void load(char* fileName);	// 10 points

// CONSTANTS STRINGS FOR STRCMP / printing of critical levels
const char vcrit[] = "very critical", crit[] = "critical", notcrit[] = "not critical";

int main()
{
	char* fileName = "Patient_List.txt";
	load(fileName);	// load list of patients from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new patient\n");
		printf("\t d: display patient list\n");
		printf("\t s: sort patient list by name\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); // save list of patients to file (overwrites file, if it exists)
	return 0;
} // ################################# END MAIN ############################################################

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char patientName_input[MAX_NAME_LENGTH], doctorName_input[MAX_NAME_LENGTH];
	unsigned int roomNumber_input, add_result = 0;
	char criticalLevel_input[20];
	switch (c)
	{
	case 'a':
		// input patient record from user
		printf("\nEnter patient name: ");
		fgets(patientName_input, sizeof(patientName_input), stdin);
		patientName_input[strlen(patientName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter doctor name: ");
		fgets(doctorName_input, sizeof(doctorName_input), stdin);
		doctorName_input[strlen(doctorName_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether patient is 'very critical' or 'critical' or 'not critical': ");
		fgets(criticalLevel_input, sizeof(criticalLevel_input), stdin);
		criticalLevel_input[strlen(criticalLevel_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter room number: ");
		scanf("%d", &roomNumber_input);
		flushStdIn();

		// add the patient to the list
		add_result = add(patientName_input, doctorName_input, criticalLevel_input, roomNumber_input);
		if (add_result == 0)
			printf("\nPatient is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nPatient successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Patient list is full! \n\n");

		break;
	case 'd': display();	break;
	case 's': sort();		break;

	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : add (20 points)
// This function is used to add a patient into the list. You can simply add the new patient to the end of list (array of structs).
// Do not allow the patient to be added to the list if it already exists in the list. You can do that by checking patient names already in the list.
// If the patient already exists then return 0 without adding it to the list. If the patient does not exist in the list then go on to add the patient at the end of the list and return 1.
// If patient list is full, then do not add new patientto the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'criticalLevel_input' to an enum type and store it in the list because the critical level has enum type (not string type).
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of patients currently in the list
int add(char* patientName_input, char* doctorName_input, char* criticalLevel_input, unsigned int roomNumber_input)
{
	if (count == 15) { // check if list is full already first
		return 2; // we are full, cant add anymore
	}

	int i; // counter for looping to check duplicates
	for (i = 0; i < count; i++) { // loop thru all the existing structs and check for duplicate patient names
		if (strcmp(list[i].patientName, patientName_input) == 0) { // if the input name matches name of existing entry
			// this is a duplicate entry, do not add.
			return 0;
		} 
	} // end duplicate check

	// if we get here, its a new patient and we will go ahead and add him to the list.
	enum criticaltype critStat = 0; // default to zero so i dont get exceptions when i am debugging and miss spell critical
	// Set critStat to enum type by stringt comparison of user input.
	// i declared these constants  at the top of page
	if (strcmp(criticalLevel_input, vcrit) == 0) { critStat = very_critical; } // input string == "very critical"
	if (strcmp(criticalLevel_input, crit) == 0) { critStat = critical; } // input string == "critical"
	if (strcmp(criticalLevel_input, notcrit) == 0) { critStat = not_critical;  } //input string == "not critical"

	struct patientRecord *p = &list[count]; // declare object pointer 
	strcpy(p->patientName, patientName_input); // load user input patient name into current struct object
	strcpy(p->doctorName, doctorName_input); // load user input doctor name into current object
	p->criticalLevel = critStat; // set object critical level as our critStat we got from converting user string to enum type.
	p->roomNumber = roomNumber_input; // set object room number to users input.
	count++; // increment the count of patients on the list

	return 1; // patient added if you get here... return 1
}


// Q2 : display (10 points)
// This function displays the patient list with the details (struct elements) of each patient. 
// Parse through the list and print the patient details one after the other. See expected output screenshots in question pdf file.
// NOTE: Critical level is stored in the struct as enum type. You need to display 'very critical','critical' or 'not critical'
void display()
{
	int i = 0; // counter for loop
	struct patientRecord *p = list ; // lazy man mixing pointers and array index. idk how to know when my pointer reach the end if I only used pointer ???
	for (i = 0; i < count; i++, p++) { // for each entry in our array
		printf("\nPatient name: %s\n", p->patientName); // print patient name
		printf("Doctor name: %s\n", p->doctorName); // print doctor
		if (p->criticalLevel == 0) {printf("Critical level: %s\n", vcrit);} // CONDITIONAL print proper string for whatever critical level
		if (p->criticalLevel == 1) {printf("Critical level: %s\n", crit);}// CONDITIONAL print proper string for whatever critical level
		if (p->criticalLevel == 2) { printf("Critical level: %s\n", notcrit);}// CONDITIONAL print proper string for whatever critical level
		printf("Room number: %d\n", p->roomNumber); // print room number as int
		
	} // end for

}

// Q3 : sort (10 points)
// This function is used to sort the list(array of structs) alphabetically by patient name.
// Parse the list and compare the patient names to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new array of structs having sorted patients.
// Hint: One of the string library function can be useful to implement this function because the sorting needs to happen by patient name which is a string.
//       Use a temp struct (already declared) if you need to swap two structs in your logic
void sort()
{
	struct patientRecord patientTemp;	// needed for swapping structs. Not absolutely necessary to use.
	// enter code here
	int i; // index for loop
	int j; // index for nested loop
	for (i = 0; i < count; i++) { // for each patient entry in our list array
		for (j = i; j < count; j++) { // compare each entry against the rest of the array
			if (strcmpi(list[j].patientName, list[i].patientName) < 0) {// if j is smaller than current i 
				patientTemp = list[i]; // hold our starting i record
				list[i] = list[j]; // set current to value of lesser
				list[j] = patientTemp; // set lesser to old value of current
			} // end if
		} // end for j
	} // end for i

	// display message for user to check the result of sorting.
	printf("\nPatient list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the patient list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	FILE* file;
	int i, criticalLevelValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of patients in the list

	// Parse the list and write patient record to file
	// 
	for (i = 0; i < count; i++)
	{
		fwrite(list[i].patientName, sizeof(list[i].patientName), 1, file);
		fwrite(list[i].doctorName, sizeof(list[i].doctorName), 1, file);
		// convert enum to a number for storing
		if (list[i].criticalLevel == very_critical)
			criticalLevelValue = 0;		// 0 for very_critical
		else if (list[i].criticalLevel == critical)
			criticalLevelValue = 1;		// 1 for critical
		else
			criticalLevelValue = 2;		// 2 for not_critical

		fwrite(&criticalLevelValue, sizeof(criticalLevelValue), 1, file);
		fwrite(&list[i].roomNumber, sizeof(list[i].roomNumber), 1, file);
	}

	fclose(file);			// close the file after writing
}

// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the patient list from the saved file and builds the array of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Patient_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the patient list to read the patient details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{ 
	FILE* file; // make file pointer
		file = fopen(fileName, "rb");		// open file for writing
		if(file != NULL) { // check for valid buffer input thing
			fread(&count, sizeof(count), 1, file); // get our count
			int critLevel; // temp for translation to enum
			criticalType critType; // translated value from file as int
			int i; // index for list[]
			for (i = 0; i < count; i++) { // loop thru the file for however many our count was ==
				fread(&list[i].patientName, sizeof(list[i].patientName), 1, file); // read patientName to obj
				fread(&list[i].doctorName, sizeof(list[i].doctorName), 1, file); // read doctorname to obj
				fread(&critLevel , sizeof(list[i].criticalLevel), 1, file); // read the crit level which was saved as an integer. but save it to temporary holder.
					if (critLevel == 0) { critType = very_critical; }// CONDITIONS for translating read int into enum type
					if (critLevel == 1) { critType = critical; }	// CONDITIONS for translating read int into enum type
					if (critLevel == 2) { critType = not_critical; }// CONDITIONS for translating read int into enum type
					list[i].criticalLevel = critType; // store crit type into object... 
				fread(&list[i].roomNumber, sizeof(list[i].roomNumber), 1, file); // read room number
			} // end reading loop

		}
		else { // if file==null
			printf("%s not found.\n", fileName); // print 2 user 
			return; // needed???
		}

		printf("Patient recod loaded from %s.\n", fileName); // print file load to user
		fclose(file);			// close the file after writing
		return; // needed??

}
