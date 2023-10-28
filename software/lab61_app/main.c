// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{
	int i = 0;
	volatile unsigned int *LED_PIO = (unsigned int*)0x40; //make a pointer to access the PIO block
	volatile unsigned int *SW_PIO = (unsigned int*)0x60;
	volatile unsigned int *RUN_PIO = (unsigned int*)0x20;

	*LED_PIO = 0; //clear all LEDs
	unsigned int tf = 0;
	while ( (1+1) != 3) //infinite loop
	{
//		for (i = 0; i < 100000; i++); //software delay
//		*LED_PIO |= 0x1; //set LSB
//		for (i = 0; i < 100000; i++); //software delay
//		*LED_PIO &= ~0x1; //clear LSB

		unsigned int sum = 0;

		if(*RUN_PIO == 0 && tf == 0) {
			sum = *LED_PIO + *SW_PIO;
			if (sum > 255){
				sum = sum - 256;
			}
			*LED_PIO = sum;
			tf = 1;
		} else if(*RUN_PIO == 1 && tf == 1){
			tf = 0;
		}

//		if(*RUN_PIO == 1){
//			*LED_PIO = *SW_PIO;
//			sum = 0;
//		} else {
//			sum = sum + *SW_PIO;
//			if (sum > 255) {
//				sum = sum -255;
//			}
//			*LED_PIO = sum;
//		}

	}
	return 1; //never gets here
}
