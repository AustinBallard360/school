// Assignment #: Arizona State University CSE205 #11
//         Name: Luke Schulz
//    StudentID: 1211984746
//      Lecture: M-W 6:00PM
//  Description: This is a utility class that provide a static method that
//				 takes an infix string, checked and determine if parentheses
//				 are matching, if matching, returns a postfix string.

import java.util.Stack;
import java.lang.Character;

public class InfixToPostfixConverter
{
	//**********************************************************************
	//The precedence method determines the precedence between two operators.
  	//If the first operator is of higher or equal precedence than the second
  	//operator, it returns true, otherwise it returns false.
    //***********************************************************************
   public static boolean precedence(char first, char second)
   {
   	int c1 = 0;
   	int c2 = 0;
   	if(Character.isLetter(first)){
   		c1 = 1;
   	}
   	if(first == '+' || first == '-'){
   		c1 = 2;
   	}
   	if( first == '*' || first == '/'){
   		c1 = 3;
   	}
   	if(first == '(' || first == ')'){
   		c1 = 4;
   	}
   	// same thing for second char
   	if(Character.isLetter(second)){
   		c2 = 1;
   	}
   	if(second == '+' || second == '-'){
   		c2 = 2;
   	}
   	if( second == '*' || second == '/'){
   		c2 = 3;
   	}
   	if(second == '(' ||second == ')'){
   		c2 = 4;
   	}

   	if( c1 >= c2){
   		return true;
   	}else{
   		return false;
   	}

   }// end precedence function

	//*************************************************************************
	//The static convertToPostfix method will convert the infixString
	//into the corresponding postfix string. Check the algorithm on
	//assignment #11's description page. Mark each case clearly inside the code
    //*************************************************************************
   public static String convertToPostfix(String infixString)
   {
      //initialize the resulting postfix string
      String postfixString = "";
      // initialize topstack character
      char topStack;

      //initialize the stack
      Stack<Character> stack1 = new Stack<Character>();

     //Obtain the character at index i in the string
      for (int i=0; i < infixString.length(); i++)
      {

         char currentChar = infixString.charAt(i);

      	//Case A: // OPERANDS ( NUMBERS )
         if(Character.isLetter(currentChar) == true){
         	postfixString += currentChar;
         } // end CASE A

      	//Case B: // LEFT PARENTHESIS
         if(currentChar == '(' ){
         	stack1.push(currentChar);
         }// end case B

         //NEW CASE C
         int flagg = 0;
         if(currentChar == '+' || currentChar==  '-' || currentChar== '*' || currentChar== '/'){
            if(stack1.empty()==true){
               stack1.push(currentChar);
               flagg = 1;
            }else{
               while(stack1.empty()==false){
               boolean check = precedence(currentChar, stack1.peek());
               if(check==true){
                  topStack = stack1.pop();
                  postfixString += topStack;
               }
               else{
                  stack1.push(currentChar);
                  break;
               }}

            }
         }

      	//Case E:
         int flag = 0;
         if(currentChar == ')' && stack1.empty() == false){
            //System.out.println("DO I EVER GO??");
            while(stack1.empty() == false){
               topStack = stack1.pop();
               if(topStack == '('){
                  flag = 1;
                  //System.out.println(" I FOUND U !!!!!");
                  break;
               }
               postfixString += topStack;
            }
            if(stack1.empty() == true && flag ==0){
               return "No matching open parenthesis error";
            }
         }


      } //end of for loop


    	//Case F:
         if(stack1.empty() == false){ // if there is still stuff in the stack
            while(stack1.empty() == false){
               topStack = stack1.pop();
               if(topStack == '('){
                  return "No matching close parenthesis error";
               }
               else{
                  postfixString+=topStack;
                  //System.out.println(" THIS IS WHAT I PRINTED LASTEST "+topStack);
               }
            }
         
         }

   return "The Postfix Expression is: "+postfixString;

   }//end of convertToPostfix method

}//end of the InfixToPostfixConverter class