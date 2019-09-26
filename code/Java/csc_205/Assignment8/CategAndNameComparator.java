// Assignment #: Arizona State University CSE205 #8
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM

import java.util.*;
//import java.io.*;
public class CategAndNameComparator implements Comparator<Food>{
	
	@Override
	public int compare(Food first, Food second){
	// make this function somehow
		int catComp = (second.getCategory().compareTo(first.getCategory()));

		if(catComp==0){ // if the categories are identical go onto check names
			int nameComp = (second.getName().compareTo(first.getName()));
			if(nameComp < 0){
				return -1; // flag that name 2 is smaller.
			}
			// THIS BROKE THE 3rd OUTPUt
		}
		//else{ // if no match of categories
			return catComp; // return difference of categories.
		//}

	//return int
} // end compare func.

}// end class
