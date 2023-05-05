#include "msp.h" 
#define INT_1 BIT4
#define INT_2 BIT6
#define INT_3 BIT6
#define INT_4 BIT6
#define LED_PIN BIT0            // LED connected to P1.0
#define IR_SENSOR_PIN1 BIT6      // IR sensor connected to P6.6
#define IR_SENSOR_PIN2 BIT4     // IR sensor connected to P5.4



void move_forward(void);
void move_backward(void);
void stop(void);
void move_left(void);
void move_right(void);
void delayMs(int n);
void initializeTimer(void);
int i =0;

int main(void) {


P2->SEL0 &= ~INT_1;
P2->SEL1 &= ~INT_1;
P2->DIR |= INT_1;
	
P2->SEL0 &= ~INT_2;
P2->SEL1 &= ~INT_2;
P2->DIR |= INT_2;
	
P5->SEL0 &= ~INT_3;
P5->SEL1 &= ~INT_3;
P5->DIR |= INT_3;
	
P6->SEL0 &= ~INT_4;
P6->SEL1 &= ~INT_4;
P6->DIR |= INT_4;
	
P1->SEL0 &= ~LED_PIN;
P1->SEL1 &= ~LED_PIN;
P1->DIR |= LED_PIN ;	

	
while(1)
{
	initializeTimer();
	if(P4IN & IR_SENSOR_PIN1 || P4IN & IR_SENSOR_PIN2)  // If IR sensor detects an object
		{
			P1->OUT |= LED_PIN;    // Turn on the LED
			move_forward();
		}
	if(P4IN & IR_SENSOR_PIN1)
	{
		move_left();
	}
	if(P4IN & IR_SENSOR_PIN2)
	{
		move_right();
	}
	
	else
	{
		stop();
		move_backward();
	}

}
}


void move_forward(void)
{
	  P2->OUT |= INT_1;
	  P2->OUT &= ~INT_2;
	
	  P5->OUT |= INT_3;
	  P6->OUT &= ~INT_4;
}
void move_backward(void)
{
	  P2->OUT |= INT_1;
	  P2->OUT &= ~INT_2;
	
	  P5->OUT &= ~INT_3;
	  P6->OUT |= INT_4;
}
void stop(void)
{
	  P2->OUT &= ~INT_1;
	  P2->OUT &= ~INT_2;
	
	  P5->OUT &= ~INT_3;
	  P6->OUT &= ~INT_4;
}
void move_left(void)
{
	  P2->OUT &= ~INT_1;
	  P2->OUT |= INT_2;
	
	  P5->OUT &= ~INT_3;
	  P6->OUT &= ~INT_4;
}
void move_right(void)
{
	  P2->OUT &= ~INT_1;
	  P2->OUT &= ~INT_2;
	
	  P5->OUT &= ~INT_3;
	  P6->OUT |= INT_4;
}

void delayMs(int n)
{
	for(i =0; i<n; i++);
}
void initializeTimer(void)
{
    // Configure Timer32_1 to run at 1 MHz
    TIMER32_1->CONTROL = TIMER32_CONTROL_SIZE | TIMER32_CONTROL_PRESCALE_0 | TIMER32_CONTROL_MODE;
    TIMER32_1->LOAD = 1000000 - 1;
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE;
}
