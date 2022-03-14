//
//  Arduino_Pin_Library.h
//  
//
//  Created by Christian Grinling on 10/11/2020.
//

#ifndef Arduino_Pin_Library_h
#define Arduino_Pin_Library_h

#include <stdio.h>

void pinModeINPUT(int pin_number);

void digitalWriteON(int pin_number);

void pinModeOUTPUT(int pin_number);

void delay(int ms);

void digitalWriteOFF(int pin_number);

void blink_led_forever(int pin_number, int time_interval);

void blink_led_times(int pin_number, int amount, int time_interval);

int digitalRead(int input_pin);


#endif /* Arduino_Pin_Library_h */
