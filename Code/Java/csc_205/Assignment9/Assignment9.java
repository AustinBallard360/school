// Assignment #: ASU CSE205 Assignment #9
//         Name: LUKE SCHULZ
//    StudentID: 1211984746
//      Lecture: M - W 6:00 pm
//  Description: this program reads in a sequence of numbers from standard
//  input until 0 is read and stores the numbers in an array, it then
//  compute the largest number, the count of even numbers (includes both postive and negative),
//  the number of -1 inside the array, and also compute the sum of numbers at
//  odd indexes (i.e. 0, 2, 4, ...), using recursion.

import java.io.*;
import java.lang.Math;
import java.util.ArrayList;
public class Assignment9
{
/******************************************************************************
  ***Complete the main() method. See above program description for details.
******************************************************************************/
  public static void main (String[] args) throws IOException
  {
  	InputStreamReader is = new InputStreamReader(System.in);
    BufferedReader stdin = new BufferedReader (is);
    int inp = Integer.parseInt(stdin.readLine());
    ArrayList<Integer> arr = new ArrayList<Integer>();
    arr.add(inp); // make our array to hold ints.
    int ar[] = new int[100]; 
    int count = 0;

    while (inp != 0 ){ // until user inputs a zero
    	// get more inputs
    	inp = Integer.parseInt(stdin.readLine());
    	ar[count] = inp;
    	count++;
    	//arr.add(inp);
    }

    //System.out.println(inp);
    /*for( int i = 0 ; i < count ; i++){
    	System.out.print(ar[i]+", ");
    }*/
  	 
  	 int max = findMax(ar , 0 , count-1);
  	 int evenCount = countEven(ar , 0 , count-1);
  	 int negCount = countNegativeOne(ar , 0);
  	 System.out.println("Congratulations MAX IS "+max+" EVEN COUNT IS "+evenCount+ "THE -1 amt is  "+negCount );
  }

/*************************************************************************************
***(1)Complete the method. The method finds the largest number in the partial array
***range from startIndex to endIndex
*************************************************************************************/
public static int findMax(int[ ] ar, int startIndex, int endIndex)
{
	if (endIndex > startIndex){
		return Math.max(ar[endIndex] , findMax(ar , startIndex , endIndex-1) );
	} else
	return 0;
//return 0;
}

/**************************************************************************************
***(2)Complete the method. The method counts the number of even integers in the partial
***arrya range from startIndex to endIndex
*************************************************************************************/
public static int countEven(int[ ] numbers, int startIndex, int endIndex)
{
	int evenCount = 0;
	if(startIndex <= endIndex){
		if(numbers[startIndex] % 2 == 0){
			evenCount = 1;
		}
		else evenCount = 0;

		return evenCount + countEven(numbers, startIndex+1 , endIndex);
	}
			return evenCount;

}

/*************************************************************************************
***(3)Complete the method. The method counts the number of -1 inside an array with
***   "count" numbers, index ranges from 0 to count-1
*************************************************************************************/
public static int countNegativeOne(int[ ] numbers, int count)
{
	int x = numbers.length;
	System.out.print("length of arr is "+ x);
	int result;
	if(count == numbers.length-1){
		return 0;
	}
 	if(numbers[count] == -1){
 		System.out.print("We got one \n");
 		result = 1;
 	}
 	else{
 		result = 0;
 	}
 	return result + countNegativeOne(numbers , count+1);

}

/**************************************************************************************
***(4)Complete the method. The method computes the sum of numbers at index 1, 3, 5, ...
***  inside a partial array with "count" numbers inside, index ranges from 0 to count-1
***************************************************************************************/
public static int computeSumAtOddIndexes(int[ ] numbers, int count)
{

 return 0;
}


}// end of class Assignment9