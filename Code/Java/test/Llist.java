// LOL LINKED LIST TEST
import java.util.*;

public class Llist{
	public static void main(String[] args){
		LinkedList<String> list1 = new LinkedList<String>();


		list1.add("Aa");
		list1.add("Bb");
		list1.add("Cc");
		list1.add("Dd");
		list1.add("Ee");
		list1.add("Ff");
		list1.add("Gg");
		list1.add("Hh");
		list1.add("Ii");

		Iterator<String> itr=list1.iterator();


		String first = itr.next();
		System.out.println(first);
		System.out.println(itr.next());
		itr.next();
		itr.next();
		System.out.println(itr.next());
		System.out.println(list1.indexOf(first));
		String yo = list1.get(0);
		System.out.println(yo);

		list1.add(0, "nummaa 11 tho?!");
		System.out.println(list1.get(0));
		System.out.println(list1.indexOf(first));
		System.out.println(yo);

		Object ob1 = new Object();
		//String st1 = "yooooo";

		ob1 = "Yoooo";
		String st1 = "Yoooo";

		if(ob1.equals(st1)){
			System.out.println(ob1);
			System.out.println("IS EQUAL LOL");
		}


		/*while(itr.hasNext()){
			System.out.println(itr.next());
		}*/

		//System.out.println(list1);

	}// end main
}// end class