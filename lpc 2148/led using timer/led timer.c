#include<lpc214x.h>

void delay(unsigned int z);        

void pll();

int main(void)
{
	int i;
    IO0DIR=0xffffffff;
    pll(); 
	                 //Fosc=12Mhz,CCLK=60Mhz,PCLK=60MHz
    while(1) {
		for(i=0;i<8;i++)
		{
        IO0SET=(1<<i);
        delay(1000000);               //1sec delay
        IO0CLR=(1<<i);
        delay(1000000);
		}		//1sec delay
    }
}


void pll()                  //Fosc=12Mhz,CCLK=60Mhz,PCLK=15MHz
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    VPBDIV=0x00;
}


void delay(unsigned int z)
{
    T0CTCR=0x0;                                 //Select Timer Mode
    T0TCR=0x00;                 //Timer off
    T0PR=14;                 //Prescaler value for 1microsecond
    T0TCR=0x02;                 //Timer reset
    T0TCR=0x01;                 //Timer ON
    while(T0TC<z);           
    T0TCR=0x00;                 //Timer OFF
    T0TC=0;                     //Clear the TC value. This is Optional.
}