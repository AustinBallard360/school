// Assignment #: Arizona State University CSE205 #8
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM
import java.util.*;
//import java.io.*;
public class Sorts{


 // end class

	public  static void sort(ArrayList<Food> foodList, Comparator<Food> xComparator){
	int i=0,j=0;
	int l = foodList.size();
	int index=0;
	int diff, minDiff;
	Food food1,food2,min,temp;

	for(i=0;i<l;i++){
		minDiff=0;
		food1 = foodList.get(i);
		min = foodList.get(i);
		index = i;

		for(j=i+1; j<l ; j++){

			food2 = foodList.get(j);
			diff = xComparator.compare(food1, food2);
			if(diff<minDiff){
				minDiff = diff;
				index = j;
				min = foodList.get(j); // should be same as food2
			}//end if

		}// end j
		temp = foodList.get(i); // should be food1;
		foodList.set(i, foodList.get(index));
		foodList.set(index, temp);

	}// end i

	} // end sort func
}