#include"ADC.h"
#include"Lcd_4bit.h"
void ADC_init()
{
  PINSEL0 |=0x00000000;
	PINSEL1|=0x04000000;
	PINSEL2 |=0x00000000;	
	
}

 unsigned int ADC_read( char chanel,char shift)
{  unsigned int ADC_r;
 	   
		switch(chanel)
		{
				case 0:
						AD0CR|=(0x00200F00|(1<<shift));
		        AD0CR|=(1<<24);
	          while(!(AD0GDR&(1<<31)));
				    ADC_r=AD0GDR;
				    Delay(1);
				    AD0CR=0x00200F00;
            break;	 
	     case 1:
		        AD1CR|=(0x00200F00|(1<<shift));
		        AD1CR|=(1<<24);
	          while(!(AD1GDR&(1<<31)));
            ADC_r=AD1GDR;
			      Delay(1);
            AD1CR=0x00200F00;			 
            break;	 	 
		}
		ADC_r=(ADC_r>>6)&0X03FF;
		return ADC_r;

}
 
 