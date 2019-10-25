#include "include/screen.h"
#include "include/pat.h"
#include "include/input.h"
void kmain()
{	
   clearScreen();
	
   
   print("***THIS IS AN OPERATING SYSTEM***\n");
   while(1)
   {
   	print("\nHere are the options:\n");
   	print("1. Check whether number is prime or not\n");
   	print("2. Determine area of triangle\n");
   	print("3. Determine area of rectangle\n");
	print("4. Exit\n");
	//print("\nEnter Your Choice: ");
	
	string ch;
	ch=readStr();
	print(ch);
	print("\n");
	if(stringEq(ch,"1"))
	{
		print("Enter the number: ");
		string num1;
		num1=readStr();
	
		print("\n\n");
				
		uint32 num2=stringToInt(num1);
		
		
		pri(num2);

		
		
	}
	else if(stringEq(ch,"2"))
	{
		print("Enter the base: ");
		string b;
		b=readStr();
		print(b);
		print("\n\n");
		uint32 b1=stringToInt(b);
		print("\n\n");
		print("Enter the height: ");
		string h;
		h=readStr();
				print(h);
		print("\n\n");

		uint32 h1=stringToInt(h);
		print("\n\n");
		

		trian(b1,h1);
	}
	else if(stringEq(ch,"3"))
	{
		print("Enter the base: ");
		string b2;	
		b2=readStr();
		uint32 b22=stringToInt(b2);
		print("\n\n");
		print("Enter the height: ");
		string h2;	
		h2=readStr();
		uint32 h22=stringToInt(h2);
		print("\n\n");
		
		rect(b22,h22);
	}
	
	else if(stringEq(ch,"4"))
	{
		break;	
	}
	else
	{
		print("Invalid choice. Try again.\n");
	}
   }

	
}

