/** Luke Schulz
 * 1211984746
 * Assignment #3
 * Palindrome Junit test class
 */

package assign1;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class PalindromeTest {

	@Test
	void test1() {
		/**Test to ensure basic palindrome case returns TRUE */
		Palindrome test1 = new Palindrome("otto");
		assertTrue( test1.isPalindrome()); 
	}
	@Test
	void test2() {
		/** Test for punctuated palindrome returns TRUE */
		Palindrome test2 = new Palindrome("o....tto");
		assertTrue(test2.isPalindrome());
	}
	
	@Test
	void test3() {
		/** Test to make sure non palindrome returns false */
		Palindrome test3 = new Palindrome("bobby");
		assertFalse(test3.isPalindrome());
	}
	@Test
	void test4() {
		/**Test to make sure uppercase palindromes are TRUE */
		Palindrome test4 = new Palindrome("Otto");
		assertTrue(test4.isPalindrome());
	}
		
	@Test
	void test5() {
		/**Test to make sure non palindromes return FALSE */
		Palindrome test5 = new Palindrome("jorge");
		assertFalse(test5.isPalindrome());
	}
	@Test
	void test6() {
		/**Test to make sure Digits are ok TRUE case */
		Palindrome test6 = new Palindrome("45ollo54");
		assertTrue(test6.isPalindrome() );
	}
	@Test
	void test7() {
		/**Test to make sure that punctuation is not considered, true case */
		Palindrome test7 = new Palindrome("oo...;'[oo");
		assertTrue(test7.isPalindrome());
	}
	@Test
	void test8() {
		/**Test to make sure that punctuation is not considered, FALSE case */
		Palindrome test8 = new Palindrome("l...xcl");
		assertFalse(test8.isPalindrome());
	}
	
	@Test
	void test9(){
		/**Test to make sure empty string is considered as Palindrome (TRUE) */
		Palindrome test9 = new Palindrome("");
		assertTrue(test9.isPalindrome());
	}
	@Test
	void test10(){
		/** Test to make sure whitespace is not considered in TRUE case */
		Palindrome test10 = new Palindrome("o t t o ");
		assertTrue(test10.isPalindrome());
	}
	void test11(){
		/** Test to make sure whitespace is not considered in FALSE case */
		Palindrome test11 = new Palindrome("o t b o ");
		assertFalse(test11.isPalindrome());
	}

}
