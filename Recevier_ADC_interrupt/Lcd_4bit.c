#include"Lcd_4bit.h"
#include"UART.h"

void LCD_Init()
{   
  IODIR1 |=0x00FE0000;
   Delay(10);
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
  LCD_Command(0x06);
	LCD_Command(0x01);
}
void LCD_Command(unsigned char cmd)
{  
	IOCLR1=(1<< Rs)|(1<<Rw);
	IOCLR1=0X00F00000;
	IOSET1=((cmd&0xF0)<<16);
	IOSET1=(1<<En);
	Delay(10);
	IOCLR1=(1<<En);
	IOCLR1=0X00F00000;
	IOSET1=(((cmd<<4)&0xF0)<<16);
	IOSET1=(1<<En);
	Delay(10);
	IOCLR1=(1<<En);	
   
}

void  LCD_Char(unsigned char data)
{    
   IOCLR1=(1<< Rw);
	IOCLR1=0X00F00000;
	IOSET1=((data&0xF0)<<16);
	IOSET1=(1<<En)|(1<<Rs);
	Delay(10);
	IOCLR1=(1<<En);
	IOCLR1=0X00F00000;
	IOSET1=(((data<<4)&0xF0)<<16);
	IOSET1=(1<<En);
	Delay(10);
	IOCLR1=(1<<En);	 
    
}
void LCD_string(unsigned char *s)
{   while(*s)
   LCD_Char(*s++);
}

void display(unsigned int adcval)
{
    LCD_Command(0xC0);
    LCD_Char((adcval/1000)+48);
    LCD_Char(((adcval/100)%10)+48);
    LCD_Char(((adcval/10)%10)+48);
    LCD_Char((adcval%10)+48);
	
	  	
	}