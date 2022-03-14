//
//  Arduino_Pin_Library.c
//  
//
//  Created by Christian Grinling on 10/11/2020.
//

#include "Arduino_Pin_Library.h"
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 8000000UL  // 1 MHz
#include <util/delay.h>
#include <string.h>

//PBO = pin8 PORTB = 0b00000001;
//PB1 = pin9 PORTB = 0b00000010;
//PB2 = pin10 PORTB = 0b00000100;
//PB3 = pin11 PORTB = 0b00001000;
//PB4 = pin12 PORTB = 0b00010000;
//PB5 = pin13 PORTB = 0b00100000;


//PD0 = pin0 PORTD = 0b00000010;
//PD1 = pin1 PORTD = 0b00000001;
//PD2= pin2 PORTD = 0b00000100;
//PD3 = pin3 PORTD = 0b00001000;
//PD4= pin4 PORTD = 0b00010000;
//PD5 = pin PORTD = 0b00100000;
//PD6= pin6 PORTD = 0b01000000;
//PD7 = pin7 PORTD = 0b10000000;

void delay(int ms) {
  while (0 < ms)
  {
    _delay_ms(1);
    --ms;
  }
}

void blink_led_forever(int pin_number, int time_interval){
    pinModeOUTPUT(pin_number);
    while(1){
        digitalWriteON(pin_number);
        delay(time_interval);
        digitalWriteOFF(pin_number);
        delay(time_interval);
        
    }

}

void blink_led_times(int pin_number, int amount, int time_interval) {
    pinModeOUTPUT(pin_number);
    int i;
    for (i=0;i<amount;i++){
        digitalWriteON(pin_number);
        delay(time_interval);
        digitalWriteOFF(pin_number);
        delay(time_interval);
    }

}

void pinModeOUTPUT(int pin_number) {
    
    if (pin_number >= 8) {
        
    int bitNumber = 0b00000001;
    int result = pin_number - 8;
        
    bitNumber = bitNumber << result;
    DDRB = DDRB | bitNumber;
        
    }
    
    else if (pin_number < 8) {
        
        int bitNumber = 0b10000000;
        int result = abs(pin_number - 7);
        bitNumber = bitNumber >> result;
        DDRD = DDRD | bitNumber;
    }
}

void pinModeINPUT(int pin_number) {
    
    if (pin_number >= 8) {
        
    int bitNumber = 0b00000001;
    int result = pin_number - 8;
        
    bitNumber = bitNumber << result;
    DDRB = DDRB & ~bitNumber;
    }
    
    else if (pin_number < 8) {
        
        int bitNumber = 0b10000000;
        int result = abs(pin_number - 7);
        bitNumber = bitNumber >> result;
        DDRD = DDRD & ~bitNumber;
    }
}

void digitalWriteON(int pin_number) {
    //use a bit shift
    if (pin_number >= 8) {
        
    int bitNumber = 0b00000001;
    int result = pin_number - 8;
        
    bitNumber = bitNumber << result;
    PORTB = PORTB | bitNumber;
        
    }
    
    else if (pin_number < 8) {
        
        int bitNumber = 0b10000000;
        int result = abs(pin_number - 7);
        bitNumber = bitNumber >> result;
        PORTD = PORTD | bitNumber;
    }
    
}

void digitalWriteOFF(int pin_number) {
    
    if (pin_number >= 8) {
        
    int bitNumber = 0b00000001;
    int result = pin_number - 8;
        
    bitNumber = bitNumber << result;
    PORTB = PORTB & ~bitNumber;
        
    }
    else if (pin_number < 8) {
        
        int bitNumber = 0b10000000;
        int result = abs(pin_number - 7);
        bitNumber = bitNumber >> result;
        PORTD = PORTD & ~bitNumber;
    }
    
}


int digitalRead(int input_pin) {
    if (input_pin >= 8) {
        
        int bitNumber = 0b00000001;
        int result = input_pin - 8;
        bitNumber = bitNumber << result;
            
        //val = PIND & bitNumber;
        int val = bit_is_clear(PINB, bitNumber);
    
        return val;
        
    }
    else if (input_pin < 8) {
        
        int bitNumber = 0b10000000;
        int result = abs(input_pin - 7);
        bitNumber = bitNumber >> result;
        
        //val = PIND & bitNumber;
        int val = bit_is_clear(PIND, bitNumber);

        return val;
    }
    //0 is pressed
    //1 is not pressed
}


