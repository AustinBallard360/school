/** Luke Schulz
 * 1211984746
 * Assignment #3
 * Palindrome class (To be test)
 */
package assign1;

/**
 * @author Luke Schulz
 * Class Palindrome.
 * Simple class with only one private data, a single string.
 * Can contain any type of characters, but cases will not be respected, and neither will punctuation
 * single function isPalindrome() to determine if said string is a palindrome
 */

public class Palindrome {
	
	private String testString;
	
	/**
	 * constructor for the Palindrome class
	 * @param tString - single string parameter, ideally a palindrome
	 */
	public Palindrome(String tString) {
		testString = tString;
	}
	
	/**
	 * Only function in class
	 * Checks the classes member string for if it is a palindrome
	 * Case is not considered, punctation and whitespace is not considered
	 * @return is a boolean true or false, depending on if the string is indeed a palindrome (true).
	 */
	public boolean isPalindrome() {
		char[] chars = testString.replaceAll("[^A-Za-z0-9]+", "").toLowerCase().toCharArray();
		int size = chars.length; 
		int leftIndex = 0; 
		int rightIndex = (size - 1);
		boolean trueFlag = true; 
		
		while ( trueFlag == true && leftIndex <= rightIndex) { 
			if(chars[leftIndex] != chars[rightIndex]) {
				trueFlag = false; 
			}
			leftIndex++;
			rightIndex--;
		}
		
		return trueFlag;
	}
}
