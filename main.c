#include <stdio.h>
#include "pico/stdlib.h"

#define Led 25
#define Button 0

bool state = 0, flag = 0;

int main(){
	gpio_init(Led);
	gpio_init(Button);
	
	//gpio_set_dir(Button, false);
	gpio_set_dir(Button, GPIO_IN);
	gpio_set_dir(Led, GPIO_OUT);

	gpio_set_input_enabled(Button, true);

	gpio_pull_up(Button);
	gpio_is_pulled_up(Button);
	

	while(1){
		/*
		if((gpio_get(Button))&&(flag == 0)){
			state = 1;
			flag = 1;
		}

		if(state == 1)&&(flag == 1)){
			state = 0;
			flag = 0;
		}
		*/
		if(flag == 0){
			if(gpio_get(Button) == 0){
				state = 1;
				flag = 1;
				sleep_ms(150);
			}
		}

		if(flag == 1){
			if(gpio_get(Button) == 0){
				state = 0;
				flag = 0;
				sleep_ms(150);
			}
		}

		gpio_put(Led, state);
	
	}	
}

