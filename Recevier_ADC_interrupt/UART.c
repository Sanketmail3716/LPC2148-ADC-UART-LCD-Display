#include"UART.h"

void UART_init()
{
PINSEL0|=0X00000005;
U0LCR=0X83;
U0DLL=0X01;
U0DLM=0X01;
U0LCR=0X03;

}

void UART_Tx(char data)
{
 U0THR=data;
while(!(U0LSR&(1<<5)));

}

char UART_Rx()
{
  while(!(U0LSR&(1<<0)));
	return U0RBR;
	
}
