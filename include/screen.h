#ifndef SCREEN_H
#define SCREEN_H

#include "dataTypes.h"
#include "string.h"
#include "system.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 25, sd = 2; 
int color = 0x03;
void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        string vidmem=(string)0xb8000;
        for(i;i<(sw*(to+1)*sd);i++)
        {
        vidmem[i]=0x0;
                //vidmem[(i / 2)*2 + 1 ] = color ;
                //vidmem[(i / 2)*2 ] = 0;
        }
}
void updateCursor()
{
    unsigned temp;

    temp = cursorY * sw + cursorX;                                  

    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D4, temp);

}
void clearScreen()
{
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}

void scrollUp(uint8 lineNumber)
{
        string vidmem = (string)0xb8000;
        uint16 i = 0;
        clearLine(0,lineNumber-1);                                            
        for (i;i<sw*(sh-1)*sd;i++)
        {
                vidmem[i] = vidmem[i+sw*sd*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}


void newLineCheck() //screen er sesh line e eshe porle next line er belay shbksu uthay dewa lgbe
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void printch(char c)
{
    string vidmem = (string) 0xb8000;     
    switch(c)
    {
        case (0x08)://0x08 is backspace button
                if(cursorX > 0) 
                {
            cursorX--;                                                          
                        vidmem[(cursorY * sw + cursorX)*sd]=0; 
        }
            break;
    
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = color;
                cursorX++; 
                break;
    
    }
    if(cursorX >= sw) 
    {
    cursorX = 0;
    cursorY++;
                                                                      
    }
    updateCursor();
    newLineCheck();
}

void print (string ch)
{
        uint16 i = 0;
        uint8 length = strlength(ch);             
        for(i;i<length;i++)
        {
                printch(ch[i]);
        }
       
        
}


#endif