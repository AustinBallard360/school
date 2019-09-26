// Assignment #: Arizona State University CSE205 #8
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM

import java.util.*;
//import java.io.*;


public class IdComparator implements Comparator<Food> {
 // class goes here
	//public idComparator() {} // dont think i need constructor.
	@Override
	public int compare(Food first, Food second){
	// make this function somehow
		return (second.getId()-first.getId()); // just takes the difference of the ID ints,
	//return int
} // end compare func.

} // end class
