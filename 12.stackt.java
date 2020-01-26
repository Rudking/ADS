package assing12;



import java.util.Scanner;
import java.lang.Exception;

abstract class stack <t>
{
	public t s[];
	public int capacity;
	public int top;
	
	public  void push(t x)
	{
		RuntimeException r=new RuntimeException("stack is full");
		try
		{
		if(isfull())
		{
			throw r;
		}
		else
			top++;
		s[top]=x;
		}
		catch(RuntimeException re)
		{
			System.out.println(re);
		}
	}
	void display()
	{
		int t=top;
		while(t!=-1)
		{
			System.out.println(s[t]);
			t--;
		}
	}
	boolean isfull()
	{
		if(top==capacity-1)
			return true;
		else 
			return false;
	}
	boolean isempty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
}
class instack extends stack <Integer>
{
	instack(int n)
	{
		capacity=n;
		top=-1;
		s=new Integer[capacity];
	}
	int pop()
	{
		RuntimeException re=new RuntimeException("stack is empty");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				int temp=s[top];
				top--;
				return temp;
			}
		}
			catch(RuntimeException e)
			{
				System.out.println(e);
			}
		return -1;
	}
	
}
class chstack extends stack <Character>
{
	chstack(int n)
	{
		capacity=n;
		top=-1;
		s=new Character[capacity];
	}
	char pop()
	{
		RuntimeException re=new RuntimeException("stack is empty");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				char temp=s[top];
				top--;
				return temp;
			}
		}
			catch(RuntimeException e)
			{
				System.out.println(e);
			}
		return '#';
	}
	
}
class stackt
{
	public static void main(String args[])
	{
		int t,ch,choice,e;
		char a;
		Scanner sc=new Scanner(System.in);
		instack s=new instack(8);
		chstack c=new chstack(8);
		System.out.println("1.Integer Stack"+"2.Character Stack");
		t=sc.nextInt();
		if(t==1)
		{
		do
		{
			
		System.out.println("1.push"+"2.pop"+"3.display");
		System.out.println("enter the choice");
		
		ch=sc.nextInt();
		switch(ch)
		{
		case 1:
			System.out.println("enter the element");
			e=sc.nextInt();
			s.push(e);
			break;
			case 2:
				e=s.pop();
			System.out.println("poped element is:"+e);
			break;
			case 3:
				s.display();
				break;
		}
				
				System.out.println("do you want to continue(1/0)");
				choice=sc.nextInt();
			
		}while(choice==1);
		}
		
		else
		{
		do
		{
			
		System.out.println("1.push"+"2.pop"+"3.display");
		System.out.println("enter the choice");
		
		ch=sc.nextInt();
		switch(ch)
		{
		case 1:
			System.out.println("enter the element");
			a=sc.next().charAt(0);
			c.push(a);
			break;
			case 2:
				a=c.pop();
			System.out.println("poped element is:"+a);
			break;
			case 3:
				c.display();
				break;
		}
				
				System.out.println("do you want to continue(1/0)");
				choice=sc.nextInt();
			
		}while(choice==1);
		}
		
		
		
		
	}
}





















