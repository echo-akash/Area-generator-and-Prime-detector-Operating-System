#ifndef STRING_H
#define STRING_H

#include "dataTypes.h"

uint16 strlength(string s)
{
	uint16 i=1;
	while(s[i++])
	{
	
	}
	return i-1;	

}

uint8 stringEq(string ch1, string ch2)
{
	uint8 result=1;
	uint8 size = strlength(ch1);
	if(size!=strlength(ch2)) result=0;
	else
	{
		uint8 i=0;
		for(i=0;i<size;i++)
		{
			if(ch1[i]!=ch2[i]) result=0;
			if(result==0) break;
		}
	}
	return result;
}
uint16 stringToInt(string temp)
{
	uint16 len = strlength(temp);
	uint16 i,num=0,mul=1;
	for(i=0;i<len;i++)
	{
		num=num+((temp[len-(i+1)]-48)*mul);
		mul*=10;
	}
	return num;
}
string intToString(uint16 num)
{
	    string temp;
	    uint16 ind=0,len=0;
	    //uint16 Ncr=ncr(i,j);
	    uint16 tempNum=num;
	    while(tempNum!=0)
	    {
		len++;
		tempNum/=10;

	    }
	    tempNum=num;
	    for(ind=0;ind<len;ind++)
	    {
		uint16 rem=tempNum%10;
		tempNum=tempNum/10;
		temp[len-(ind+1)]=rem+48;
	    }

	    temp[len]='\0';
	    return temp;

}


string intToString32(uint32 num)
{
	    string temp;
	    uint32 ind=0,len=0;
	    //uint16 Ncr=ncr(i,j);
	    uint32 tempNum=num;
	    while(tempNum!=0)
	    {
		len++;
		tempNum/=10;

	    }
	    tempNum=num;
	    for(ind=0;ind<len;ind++)
	    {
		uint32 rem=tempNum%10;
		tempNum=tempNum/10;
		temp[len-(ind+1)]=rem+48;
	    }

	    temp[len]='\0';
	    return temp;

}



#endif