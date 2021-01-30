#include<lpc214x.h>

void pll()                       //Fosc=12Mhz,CCLK=60Mhz,PCLK=60MHz
{
    PLL0CON=0X01;
    PLL0CFG=0X24;
    PLL0FEED=0XAA;
    PLL0FEED=0X55;
    while((PLL0STAT&(1<<10))==0);
    PLL0CON=0X03;
    PLL0FEED=0XAA;
    PLL0FEED=0X55;
    VPBDIV=0X01;
}

void wait()
{
    T1CTCR=0X0;          //Timer Mode
    T1PR=59999;                 //Prescaler Value
    T1MR0=1000;                 //Match Register Value
    T1MCR=0x00000004;       //TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC.
    T1TCR=0X02;                 //Reset Timer
    T1TCR=0X01;                 //Timer ON
    while(T1TC!=T1MR0);
    T1TC=0;                         //Timer OFF
}

int main(void)
{
	 int i;
    IODIR0=0xffffffff;
    pll();                             //Fosc=12Mhz,CCLK=60Mhz,PCLK=60MHz

    while(1) {
		for(i=0;i<8;i++)
		{
        	IO0SET =(1<<i);
        	wait();
        	IO0CLR =(i<<i);
        	wait();
		}
    }

}