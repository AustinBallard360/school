// Assignment #: Arizona State University CSE205 #8
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00 PM

import java.util.*;
import java.io.*;

public class GroceryStore implements Serializable{

	// variables here	
	public ArrayList<Food> foodList;
	// constructor first
	public GroceryStore(){
		foodList = new ArrayList<Food>();
	}


	// now functions
	public boolean addFoodById(String category, String name, int id){
		int l = foodList.size();
		for( int i = 0 ; i<l ; i++){
			if(foodList.get(i).getId() == id){
				return false; // id is found inside foodList
			}
		}
			foodList.add(new Food(category, name, id)); // add new Food to foodList
			return true; // food added
	} // end addFoodById


	public int idExists(int foodId){
		int l = foodList.size();
		Food temp;
		for( int i = 0 ; i < l ; i++){
			temp = foodList.get(i);
			if(temp.getId() == foodId){
				return i;
			}
		} // end for
		return -1; // no matching ID was found.
	} // ends idExists


	public int categAndNameExists(String nCategory, String nName){ // checks existing ArrayList for items by category and name strings.
		int catTrue = 0, nameTrue=0;
		int l = foodList.size();
		for(int i = 0 ; i < l ; i++ ){
			Food temp = foodList.get(i);
			if(temp.getCategory().equals(nCategory)){ // if category matched on
				catTrue = 1; // set category flag to true
			}
			if(temp.getName().equals(nName)){ // if name matches
				nameTrue = 1; // set name flag to true
			}
			if(nameTrue == 1 && catTrue == 1){
				return i; // return the index of that item.
			}

			catTrue = 0; // reset the flags for each variation of loop
			nameTrue = 0; // prevents matching name for one item, and cat for different item etc.
		} // end for loop
		return -1; // if the loop finds no full matches, return -1
	}// end catAndNameExists


	public void sortById(){
		Sorts.sort(foodList , new IdComparator());
	}


	public void sortByCategAndName(){
		Sorts.sort(foodList , new CategAndNameComparator());
	}


	public boolean removeById(int id){
		// i already wrote this code, but i bet we could just re-use idExists(foodId);
		int l = foodList.size();
		for ( int i = 0 ; i < l ; i++){
			Food temp = foodList.get(i);
			if(temp.getId() == id){ // if the ID is found inside the arraylist
				foodList.remove(i); // remove the thing
				return true;
			}
		} // end for
		return false; // id was not found in arraylist.
	}// end removeById func



	public boolean removeByCategAndName(String category, String name){

		int x = categAndNameExists(category, name); // this function already finds existing food objects
		if(x == -1){ // if item does not exist
			return false; 
		}
		else { // if item does exist, x is index
			foodList.remove(x); // remove said item.
			return true; // item removed, success.
		}
	} // end removeByCategAndName()


	public String listFood(){
		int l = foodList.size();
		String bigString="";
		for(int i=0; i<l ; i++){
			bigString += foodList.get(i).toString(); // keep adding all the toString() to one big string.
		}
		return bigString;
	}// end listFood()


	public void closeGroceryStore(){ // wipes the ArrayList clean.
		foodList.clear(); 
	}
} // end class