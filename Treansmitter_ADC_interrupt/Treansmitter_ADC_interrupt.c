#include<lpc21XX.h>  
#include"ADC.h"
#include"Lcd_4bit.h"
#include"PLL.h"
#include"UART.h" 



void Delay(unsigned int );          

void main (void)
{ 
	unsigned int ADC_result1;
	
	PINSEL0|=0x00000000;
	PINSEL1|=0x00000000;
	PINSEL2|=0x00000000;

 
	UART_init();
	PLL_SET();
  LCD_Init();
	ADC_init();	
	LCD_Command(0x80);
	LCD_string("ADC value1:");

    while(1)                
    {
			
			ADC_result1=ADC_read(0,2);
			 Delay(2);
			
			
			  LCD_Command(0x8C);
		    display(ADC_result1);	
				 
     
		}
}

void Delay(unsigned int time)
{
    int j;
    int i;
    for(i=0;i<time;i++)
    {
        for(j=0;j<60000;j++)
        {
        }
    }
}









