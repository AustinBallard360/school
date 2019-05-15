import java.util.*;

public class LinkedListTester
{
	public static void main(String[] args){
		LinkedList list1 = new LinkedList();
		ListIterator iterator = list1.listIterator();

		iterator.add("Apple");
		printList(list1);

		iterator.add("Orange");
		printList(list1);
		iterator.add("Tomato");
		printList(list1);

		iterator = list1.listIterator();
		iterator.next();
		iterator.next();

		iterator.add("bananna");
		printList(list1);
		iterator.next();
		iterator.add("lemon");
		printList(list1);

		iterator = list1.listIterator();
		iterator.next();
		iterator.remove();

		while(iterator.hasNext()){
			System.out.println(iterator.next());
		}
	}

	public static void printList(LinkedList list1){
		ListIterator iterator = list1.listIterator();
		String result = "{ ";
		while (iterator.hasNext())
			result += iterator.hasNext() + "";
		result += "}";
		System.out.println(result);
	}
}