package assing1;
import assing.commonlist;
import java.util.Scanner;
class Node {

   public int data;
   public Node link;

   public Node() {
       link = null;
       data = 0;
   }
   /*  Constructor  */

   public Node(int d, Node n) {
       data = d;
       link = n;
   }
 }

public class SLL implements commonlist {

   Node start;
   Node end;
   int size;

   SLL() {
       start = null;
       end=null;
       size = 0;
   }

   public boolean isEmpty() {
       return start == null;
   }

   public void add(int val) {
       Node nptr = new Node(val, null);
       size++;
       if (start == null) {
           start = nptr;
           end=nptr;
          } else {
           end.link=nptr;
           end = nptr;
       }
   }
   public int size(){
       return size();
   }
   public void display(){
       System.out.print("\nSingly Linked List = ");
       if (size == 0) 
       {
       System.out.print("empty\n");
       return;
       }    
       if (start.link == null) 
       {
          System.out.println(start.data);
           return;
       }

       Node ptr = start;
       while (ptr.link != null)
       {
          System.out.print(ptr.data+ "->");
           ptr = ptr.link;
       }
       System.out.print(ptr.data+ "->");
   }
   public static void main(String[] args)
   {   
	   int choice,no;
       SLL sl=new SLL();
       Scanner sc=new Scanner(System.in);
      do
      {
    	  System.out.println("insert data");
    	  System.out.println("display data");
    	  System.out.println("size");
    	  System.out.println("enter choice");
    	  choice=sc.nextInt();
    	  switch(choice)
    	  {
    	  case 1:
    		  System.out.println("enter the data");
    		  no=sc.nextInt();
    		  sl.add(no);
    		  break;
    	  case 2:
    		  sl.display();
    		  break;
    		  
    	  }
      }while(choice<3);
   }
   
}