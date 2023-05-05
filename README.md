# Obstracle-avoidace-rover
This is simple project where I have built a obstacle avoidance rover using MSP432 board in C. 


The code is self explained and very easy to edit. The forward, backward, right, left are already defined if you want you can change the pin numbers to. 
In the code, the pin are declared in BIT.
For Example,
I want to declare P2.2 pin as output on MSP432 board then in the code I would declare as P2->SEL0 &= ~BIT2. BIT2 represents pin 2 in port 2.

I have used IR sensors to detect the obstacles.  You can use below pics and videos as reference.
