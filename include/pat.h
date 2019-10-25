#include "dataTypes.h"




void pri(uint32 num2)
{
    
	uint32 i, flag = 0;
	
    for(i=2; i<=num2/2; ++i)
    {
        // condition for nonprime number
        if(num2%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0){
    	print(intToString(num2));
    	print("\n is a prime number\n");
    }
    else{
    	print(intToString(num2));
        print("\n is not a prime number\n");
    }

}


void trian(uint32 b1,uint32 h1)
{
	uint32 ans;
	ans = (1/2)*b1*h1;
	print("\n area of triangle is : ");
	print(intToString(ans));
	print("\n");

}


void rect(uint32 b22, uint32 h22)
{
	uint32 ans2;
	ans2 = b22*h22;
	print("\n area of rectangle is : ");
	print(intToString(ans2));
	print("\n");	
}