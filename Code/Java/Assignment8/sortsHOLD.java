// Assignment #: Arizona State University CSE205 #8 // THIS IS THE ORIGINAL SORTS
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM

import java.util.*;
//import java.io.*;
public class Sorts{


 // end class

public  static void sort(ArrayList<Food> foodList, Comparator<Food> xComparator){
	int length = foodList.size();
	int index;
	Food min;
	int minIndex;
	int dif, minDif;
	Food temp;
	Food food1, food2;

	for(int i = 0 ; i < length ; i++){
		food1 = foodList.get(i);
		temp = food1;
		min = food1;
		index = i;
		dif=0; // base value for comparison
		minDif=0;
		minIndex=i;

		for(int j = i+1 ; j < length ; j++){
			food2 = foodList.get(j);
			dif=xComparator.compare(food1, food2); // + food1 is larger // - food2 is larger
			if(dif<minDif){ // if the difference between the last two compared is less than current min difference
				minDif=dif; // set new minimum difference.
				minIndex=j; // get the index for min element.
				min=food2; // get minimum element as object
			}// end if
		}// end for J
	foodList.set(index, min); // replace i index element with min object. // if there was no smaller element, just replaces itself.
	foodList.set(minIndex, temp); // replaces min element with i element.


	}// end for i
} // end sort func
}