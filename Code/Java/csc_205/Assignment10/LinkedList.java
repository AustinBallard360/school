// Assignment #: Arizona State University CSE205 #10
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M - W 6PM
//  Description: The LinkedList defines a linked list using its node class
//  object and also defines a iterator class to traverse the linked list.

import java.util.NoSuchElementException;
import java.util.Arrays; // for my reverse() function


public class LinkedList
{
   //The only instance variable that points to the first node
   private Node first;

   //nested class to represent a node
   private class Node
   {
      public Object data;
      public Node next;
   }

   // Constructs an empty linked list.
   public LinkedList()
   {
      first = null;
   }

   //Returns the first element in the linked list.
   public Object getFirst()
   {
      if (first == null)
         throw new NoSuchElementException();
      return first.data;
   }

   //Removes the first element in the linked list.
   public Object removeFirst()
   {
      if (first == null)
         throw new NoSuchElementException();
      Object element = first.data;
      first = first.next;
      return element;
   }

   //Adds an element to the front of the linked list.
   public void addFirst(Object element)
   {
      Node newNode = new Node();
      newNode.data = element;
      newNode.next = first;
      first = newNode;
   }

   //toString() method prints the elements out from front to tail
   public String toString()
   {
      ListIterator iterator = listIterator();
      String result  = "{ ";
      while (iterator.hasNext())
      {
         result += iterator.next() + " ";
      }
      result += "}\n";

      return result;
   }

  //*****************************************************************
  //size() method returns the number of nodes inside this LinkedList
  //*****************************************************************
   public int size()
   {
      ListIterator iterator = listIterator();
      int count = 0;
      while (iterator.hasNext())
      {
         count++;
         iterator.next();
      }
      return count;
   }

  //*************** Below is where you should add your own codes ***********

    //*****************************************************************
    //searchElement() method returns the index of the first occurrence of the parameter object
    //in the linked list if it exists. It returns -1 if it does not exit.
    //*****************************************************************
   public int searchElement(Object element)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      int size = this.size(); // get the size of our List
      Object xdata;
      int index = 0;
      while(iterator.hasNext()){
        xdata = iterator.next();
        if(xdata.equals(element)){ // use .equals() cause its a String Object i think
          return index;
        }//end if
        index++;
      }// end while
      return -1; // if not found, return -1

   }// end searchElement()

  //*****************************************************************
  // getElement() method returns the element at the parameter index
  // If the index is out of bounds, throw an IndexOutOfBoundsException.
  //*****************************************************************
   public Object getElement(int index)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata;
      try{
        for(int i = 0 ; i <= index ; i++){
          xdata = iterator.next();
          if(i==index){
            return xdata; // return the string at the index position *** MAY NEED TO ADJUST BY +/-1 ***
          }
          i++;
        }// end for i
      }// end try
      catch(IndexOutOfBoundsException ex){
      
        System.out.println("Inded Out of Bounds EX on getElement()");
      }
      return -1; // this should never be.
   } // end getElement()

   //*****************************************************************
   //setElement() method sets the parameter object at the parameter index in the linked list.
   // If the index is out of bounds, throws an IndexOutOfBoundsException
   //*****************************************************************
   public void setElement(int index, Object element)
   {
      //Add your own code
    //*** This is the exact same as insertElement() except we use set() instead of add() ** //
      ListIterator iterator = listIterator();
      Object xdata;
      try{

        for (int i = 0 ; i <= index ; i++){
          xdata = iterator.next();
          if(i == index){
            iterator.set(element);// insert new node 
          }
        }// end for i
      }// end try

      catch(IndexOutOfBoundsException ex){
        System.out.println("Index out of bounds exception in setElement()");
      }

   }// end setElement()
   //*****************************************************************
   //insertElement() method inserts the parameter object at the parameter index.
   //If the index is out of bounds, throws an IndexOutOfBoundsException
   //Note: the element can be inserted at the end, i.e. inserted at size() index/position
   //*****************************************************************
   public void insertElement(int index, Object element)
   {
          //Add your own code
      ListIterator iterator = listIterator();
      int counter = 0;
      int flag = 0;
      //Object xdata = null;
      try{

        for (int i = 0 ; i <= index ; i++){
        	if(iterator.hasNext()){
        		iterator.next();
        	}
          if(i == index){
            iterator.add(element);// insert new node 
            break;
          }
        }// end for 
      }// end try

      catch(IndexOutOfBoundsException ex){
        System.out.println("Index out of bounds exception in setElement()");
      }
   }
  //*****************************************************************
  //removeElement()method removes and returns element at parameter index and throw
  //an IndexOutOfBoundsException if the index is out of bounds
  //*****************************************************************
   public Object removeElement(int index)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata; 
      try{

        for(int i = 0 ; i <= index ; i++){
         xdata = iterator.next();
          if(i == index){
            iterator.remove(); // remove last traversed index.
            return xdata;
          }// end if

        }//end for i
    }// end try
    catch(IndexOutOfBoundsException ex){
      System.out.println("Index out of bounds exception for removeElement()");
    }
    return null;
   }// end removeElement()

   //*****************************************************************
   //countHowMany(Object) method returns the number of occurences of the parameter object in the LinkedList
   //*****************************************************************
   public int countHowMany(Object searchedObject)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      int count = 0;
      Object xdata;

      try{

        while(iterator.hasNext()){
          xdata = iterator.next(); 
          if(xdata.equals(searchedObject)){
            count++; // add each isntance of object, for running total.
          }// end if
        }//end for i

      }//end try block
      catch(Exception ex){
        System.out.println("Unexpeted exception in countHowMany()");
      } // end catch block
      return count; // return after try block.

   } // end countHowmany();

   //*****************************************************************
   //removeDuplicate() method removes all occurences of the parameter objects from the LinkedList
   //*****************************************************************
   public void removeDuplicate(Object removedObject)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata;

      while(iterator.hasNext()){
        xdata = iterator.next();
        if(xdata.equals(removedObject)){
          iterator.remove();
        }// end if
      }// end while
   }// end removeDuplicate()

   //*****************************************************************
   //insertAtFront(Object, int) method inserts the parameter object number of times at the front of the linked list
   //for example, a call of insertAtFront("A", 3) will insert string "A" three times in front of the linked list.
   //*****************************************************************
   public void insertAtFront(Object element, int howManyTimes)
   {
      //Add your own code
      ListIterator iterator = listIterator(); // before we traverse list at all
      for(int i = 0 ; i < howManyTimes ; i++){
      	iterator.add(element); // add same item as many times as desired
      }
      /*for(int i = 0 ; i < howManyTimes ; i++){
        // HOW CAN I USE A FUNCTION THAT IS INSIDE OF THE CLASS 
        first.addFirst();

      }// end for i*/
   }// end insertAtFront()

   //*****************************************************************
   //appendAtEnd(Object, int) method appends the parameter object number of times at the end of the linked list
   //for example, a call of appendAtEnd("B", 3) will append string "B" three times at the end of the linked list.
   //*****************************************************************
   public void appendAtEnd(Object element, int howManyTimes)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata = null;
      while(iterator.hasNext()){
      	xdata = iterator.next();
      }
      iterator.add(xdata); // change last object to our desired object
      //now that we have no more objects up "next" aka at the end of list
      // add new object
      for(int i = 0 ; i < howManyTimes ; i++){
      	 // add same item as many times as desired
      	if(i == 0){
      		iterator.set(element);
      	}else
      		iterator.add(xdata);
      }
   }

   //*****************************************************************
   //insertInFront(Object element1, Object element2) method insert the
   //second parameter object, i.e. element2 immediately in front of the
   //first occurence of first parameter object - element1.
   //if element1 is not found inside the linked list, then insert element2
   //at the front/head of the linked list.
   //*****************************************************************
   public void insertInFront(Object element1, Object element2)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata;
      int flag = 0;

      int index = 0;
      while(iterator.hasNext()){
        xdata = iterator.next();
        if(xdata.equals(element1)){
        	iterator.add(element2); // this works, i dont need the index
        	flag = 1;
        	break; // this exits the loop right? just more effective, we could keep going it doesnt matter
        }// end if

      }// end while
      if(flag==0){
      	iterator = listIterator();
      	iterator.add(element2);
      }
   } // end insertInFront()

   //*****************************************************************
   //appendAfter(Object element1, Object element2) method appends the second parameter object, i.e. element2 right after
   //the first occurence of first parameter object,
   //if element1 is not inside the linked list, then append element2 at the front/head of the linked list.
   //*****************************************************************
   public void appendAfter(Object element1, Object element2)
   {
      //Add your own code
      ListIterator iterator = listIterator();

      Object xdata;
      int index = 0;
      int flag = 0; // signals if first element has already been replaced
      while(iterator.hasNext()){
        xdata = iterator.next();
        if(xdata.equals(element1)){
        	iterator.next(); // one more position forward so we
          	iterator.add(element2);  // add element
          	flag = 1; // note that appending has happened
        	break; // this exits the loop right? just more effective, we could keep going it doesnt matter
        }// end if

      }// end while
      if(flag==0){
      	iterator = listIterator();
      	iterator.add(element2);
      }

   }

  //*****************************************************************
  //reverse(int howMany) reverse the first parameter number of elements inside the linked list.
  //for example, if the original linked list is { A B C D E F G }, a call of reverse(3) will
  //change the linked list to { C B A D E F G }. Note #1: you need to consider the boundary value, i.e.
  //cases where howMany <= 0 or howMany > size()
  //Note #2: reverse(size()) should reverse the whole linked list
  //*****************************************************************
   public void reverse(int howMany)
   {
      //Add your own code
      ListIterator iterator = listIterator();
      Object xdata;

      if(howMany < 0 || howMany > this.size()){
      	System.out.print("No"); // handles boundary cases ( i hope)
      }else{

      	Object[] holder = new Object[howMany]; // create array for holding our Objects

      	for(int i = 0 ; i < howMany ; i++){ // traverse the List and populate our array with initial values
      		xdata = iterator.next(); // get the object / move forward
      		holder[i] = xdata; // put object in array
      	} // end for I

      	iterator = listIterator(); // reset our iterator.
      	for( int j = howMany-1 ; j >= 0 ; j--){ // go forward on the list, setting each with the value as we go backwards on the array
      		iterator.next(); // go to first position
      		iterator.set(holder[j]); // swap first object with last array value
      	} // end for J
      }// end big else block


   }

//***********Don't change the following LinkedListIterator class******************

   //***************************************************************
   //Method creates an iterator on the current LinkedList
   //***************************************************************
   public ListIterator listIterator()
   {
      return new LinkedListIterator();
   }

   //***************************************************************
   //nested class to define its iterator
   //***************************************************************
   private class LinkedListIterator implements ListIterator
   {

      private Node position;
      private Node previous;

      // Constructs an iterator that points to the front
      // of the linked list.   of the linked list.
      public LinkedListIterator()
      {
         position = null;
         previous = null;
      }

     // Moves the iterator past the next element, and returns
     // the traversed element's data.
      public Object next()
      {
         if (!hasNext())
            throw new NoSuchElementException();
         previous = position; // Remember for remove

         if (position == null)
            position = first;
         else
            position = position.next;

         return position.data;
      }

      // Tests if there is an element after the iterator position  position
      public boolean hasNext()
      {
         if (position == null)
            return first != null;
         else
            return position.next != null;
      }

      // Adds an element after the iterator position
      // and moves the iterator to the inserted element.
      public void add(Object element)
      {
         if (position == null)
         {
            addFirst(element);
            position = first;
         }
         else
         {
            Node newNode = new Node();
            newNode.data = element;
            newNode.next = position.next;
            position.next = newNode;
            position = newNode;
         }
         previous = position;
      }

    // Removes the last traversed element. This method may
    // only be called after a call to the next() method.
      public void remove()
      {
         if (previous == position)
            throw new IllegalStateException();

         if (position == first)
         {
            removeFirst();
         }
         else
         {
            previous.next = position.next;
         }
         position = previous;
      }

      // Sets the last traversed element to a different value
      public void set(Object element)
      {
         if (position == null)
            throw new NoSuchElementException();
         position.data = element;
      }
   } // END CLASS LinkedListIterator Implements ListIterator
}// end outside class