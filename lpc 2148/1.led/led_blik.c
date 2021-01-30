#include<lpc214x.h>

void delay();
int main(void)
{
	int i;
    IO0DIR |=0XfffffFFF;              //Port 0 is now acting as a output pin
  	while(1) {
  		for(i=0;i<8;i++)
  	 		{
        	IO0SET |=(1<<i);      //Port 0's all pins are high now (LED is glowing)
        	delay();
        	IO0CLR |=(1<<i);      //Port 0's all pins are low now (LED is OFF)
        	delay();
		}
		}	
}       
        
void delay()
{
    unsigned int i,c;
    for(i=0;i<800000;i++);
	{
	c++;
	}
}
