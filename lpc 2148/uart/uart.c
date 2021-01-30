#include<lpc214x.h>
void delay(unsigned int z);
void serial(int n);
void pll(void)
{
  PLL0CON=0X01;
  PLL0CFG=0X24;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  while((PLL0STAT&(1<<10))==0);
  PLL0CON=0X03;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  VPBDIV=0x01;             //pclk=60mhz
}

void ser_int()
{
  PINSEL0=0X5;
  U0LCR=0X83;
  U0DLL=135;
  U0DLM=1;
  U0LCR=0X03;
}

int tx(unsigned int c)
{
  while((U0LSR&(1<<5))==0);
  U0THR=c;
  return c;
}

int rx()
{
  unsigned int a;
  while((U0LSR&(1<<0))==0);
  a=U0RBR;
  return a;
}

int main(void)
{
  unsigned int b,c;
  pll();
  ser_int();
  while(1) {
    b=rx();
	c=tx(b);	
	serial(b);
	tx(b);
	

	}
}

void delay(unsigned int z)
{
    T0CTCR=0x0;                                  
    T0TCR=0x00;                 
    T0PR=14;                 
    T0TCR=0x02;                 
    T0TCR=0x01;                 
    while(T0TC<z);           
    T0TCR=0x00;                 
    T0TC=0;                     
}

void serial(int n)
{
	
	IO1DIR |=0xFFFFFFFF;
	while(1){
		if(n==6){
			IO1SET|=0xFFFFFFFF;
			delay(1000);
			IO1CLR=0xFFFFFFFF;
			delay(1000);
		}
	}	
}