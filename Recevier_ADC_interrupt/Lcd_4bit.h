#include<lpc214x.h> 

#define Rs 17
#define Rw 18
#define En 19

void LCD_Init();
void LCD_Command(unsigned char);
void LCD_Char(unsigned char);
void LCD_string(unsigned char *);
void display(unsigned int adcval);