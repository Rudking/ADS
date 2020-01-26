package assing13;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class colection {
	public static void main(String[] args) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		int choice;

		PriorityQueue<Integer> q1=new PriorityQueue<>();

		Stack<Integer> s1=new Stack<>();
		LinkedList<Integer> l1=new LinkedList<>();
		ArrayList<Integer> arrayList=new ArrayList<>();
		HashMap<String, Integer> hs=new HashMap<>();
		do
		{
			System.out.println("\n1. Queue\n2.Stack\n3.Linked List\n4.ArraList\n5.Map\n0.Exit\nENter your choice:");
			choice=sc.nextInt();
			switch(choice)
			{
			case 1:

				System.out.println("1. Enqueue\n2.Dequeue\n0.Exit");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nEnter Number: ");
					q1.add(new Integer(sc.nextInt()));
					System.out.println("Added :"+q1.peek());
					break;
				case 2:
					System.out.println("\nRemoved element:=>"+q1.remove());
					break;

				case 0:
					break;

				}
				break;
			case 2:
				System.out.println("\n1.Push\n2.Pop\n3.Top\n4.Exit;");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nENter Number: ");
					s1.push(new Integer(sc.nextInt()));
					break;
				case 2:
					System.out.println("\nPopped elemet:=> "+s1.pop());
					break;
				case 3:
					System.out.println("\nStack top: "+s1.peek());
					break;
				case 4:
					break;
				}
				break;
			case 3:

				System.out.println("\n====Linked LIST =====\n 1. ADD\n2.Remove\nFirst\n4.LAst");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nENter Number: ");
					l1.add(new Integer(sc.nextInt()));
					break;
				case 2:
					System.out.println("\nEnter element to remove: ");

					System.out.println("]nRemoved element:"+l1.remove(sc.nextInt()));
					break;
				case 3:
					System.out.println("\nFirst Element: "+l1.getFirst());
					break;
				case 4:
					System.out.println("\nLast Element: "+l1.getLast());
					break;
				case 5: break;
				}
				break;
			case 4:
				System.out.println("\n====ARRAY LIST ========");

				System.out.println("10 added\n20added");
				arrayList.add(new Integer(10));
				arrayList.add(new Integer(20));
				System.out.println("Removed element  at index 0 from arrayList: "+arrayList.remove(0));
				System.out.println("\nSize: "+arrayList.size());
				break;

			case 5:
				System.out.println("\n===== Hash Map=====");

				{
					System.out.println("\nENter Key");
					sc.next();
					String key=sc.nextLine();
					System.out.println("\nENter Value: ");
					int value=sc.nextInt();
					hs.put(key, value);
					System.out.println("\nRecord Insserted");
					hs.put("roll",2464);
					hs.put("Div", 4);

					System.out.println("\nRemoved element (roll):"+hs.remove("roll"));

					System.out.println("\nSize: "+hs.size());
					System.out.println("\nHashcode Value for this map: "+hs.hashCode());

				}
				break;
			default:
				System.out.println("\nWrong Choice");


			}
		}while(choice!=0);
	}
}
