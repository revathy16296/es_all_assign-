 #include<lpc214x.h>

 void delay(unsigned int t);
 void pll();
  
  void main(){
  IO0DIR|=0xFFFFFFFF;
  pll();
  while(1)
  {
  	IO0SET|=(1<<1);
	delay(100);
	IO0CLR|=(1<<1);
	delay(100);
	}
}

 void delay(unsigned int t)
 {
 	T0CTCR=0x0;
	T0TCR=0;
	T0PR=59;
	T0TCR=0x02;
	T0TCR=0x01;
	while(T0TC<t);
	T0TCR=0;
	T0TC=0x00;
}

void pll()
{
 PLL0CON=0x01;
 PLL0CFG=0x24;
 PLL0FEED=0xAA;
 PLL0FEED=0x55;
 while(!PLL0STAT &(1<<10)==0);
  PLL0CON=0x03;
 PLL0FEED=0xAA;
 PLL0FEED=0x55;
 }