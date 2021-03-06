/*
     servoRangeFinder.c
     gcc -o servoRangeFinder servoRangeFinder.c -lpigpio -lrt -lpthread 
     sudo ./servoRangeFinder
*/
#include <stdio.h>
#include <pigpio.h>
#include <math.h>

#define LOWERLIMIT 500
#define UPPERLIMIT 2300

int main(int argc, char *argv[])
{
	if (gpioInitialise()<0)
	{
		fprintf(stderr, "pigpio initalisation failed\n");
		return 1;
	}
 
	// Set servo pulses | updates servos at 50Hz
	gpioServo(21, 1450); //Move servo to it's midpoint 
		
	while(1)
	{
		gpioServo(21, LOWERLIMIT);
		printf("Moving Servo to %d\n",LOWERLIMIT);
		sleep(3);
		gpioServo(21, UPPERLIMIT);
		printf("Moving Servo to %d\n",UPPERLIMIT);
		sleep(3);
	}
return 0;
}

// Range for Upper Servo on GPIO pin 21, is 550 to 2250
// Range for the Lower Servo on GPIO pin 20 is 500 to 2400