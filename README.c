//
//  README
//
//
//  Created by Christian Grinling on 10/11/2020.
//
/*
 
 ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------
 
 Could not be asked with writing it out the binary/Hexadecimal way so this is a small library
 -WIP- to make coding to your arduino in C a bit easier.
 
 Yours truly,
 Christian Grinling.
 
 ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------
 
 To run these files do the same commands just add in the Arduino_pin_Library.c into the first command
 avr-gcc -Wall -g -Os -mmcu=atmega328p Arduino_pin_Library.c ArduinoLibraryTest.c -o $1.elf
 avr-objcopy -O ihex Arduino_pin_Library.elf Arduino_pin_Library.hex
 avrdude -p atmega328p -P {Whatever port} -c arduino -b 115200 -D -U flash:w:$1.hex:i
 
 For mac users who can't be asked to type it like me use this script -
 #!/bin/bash
  
 avr-gcc -Wall -g -Os -mmcu=atmega328p $1.c $2.c -o $1.elf
 avr-objcopy -O ihex $1.elf $1.hex
 avrdude -p atmega328p -P $3 -c arduino -b 115200 -D -U flash:w:$1.hex:i
 
 ^ save to plain text then chmod +x (filepath) to make it executable.
 
 ./run-arduino-with-library Arduino_Pin_Library ArduinoLibraryTest {port number, eg- /dev/tty.usbmodem14301}

 ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------
 
 pinModeINPUT(int pin_number);
 ^ This function takes in a pin number(eg pin 13) and sets it as an input.
 
 pinModeOUTPUT(int pin_number);
 ^ This function takes in a pin number(eg pin 13) and sets it as an output.

 digitalWriteON(int pin_number);
 ^ This function takes in a pin number(eg pin 13) and sets it to 'High' aka turns it on.

 digitalWriteOFF(int pin_number);
 ^ This function takes in a pin number(eg pin 13) and sets it to 'Low' aka turns it off.

 delay(int ms);
 ^ This function takes in a time (eg 1000 for 1 second) and performs the delay
 (_delay_ms was just too many _ for me to type)

 blink_led_forever(int pin_number, int time_interval);
 ^ This function takes in a pin number(eg pin 13) and a time interval(eg 1000) between the blinks and blinks an led
 forever ***NOTE you cannot do anything else but blink with this!!!!

 blink_led_times(int pin_number, int amount, int time_interval);
 ^ This function takes in a pin number(eg pin 13), an amount of times you want the led to blink and a time interval(eg 1000) between the blinks and blinks an led for that number of times with that amount of time between them.
 
 digitalRead(int input_pin)
 ^This code takes an input pin number and returns either 1 if the input is low and 0 if the input is high.
 *******BEWARE******** THIS FUNCTION BARELY WORKS IM STILL WORKING ON THIS!
 
 ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------
 
 EXAMPLE CODE 1
 In this example we will set pin 13 as an output, turn it on wait 3 seconds then turn it off.

int main(void) {
 
    pinModeOUTPUT(13);
    digitalWriteON(13);
    delay(3000);
    digitalWriteOFF(13);
    
}

----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------

EXAMPLE CODE 2
In this example we will blink pin 8 for 5 times with a time of 2 seconds between and then blink pin
 9 for 10 times with an interval of 1 second.


int main(void) {

    blink_led_times(8,5,2000);
    blink_led_times(9,10,1000);

}

 ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------

 EXAMPLE CODE 3
 In this example we will take a button as input on pin 9, and the built in led as output on pin 13 and turn the led on if the button is pressed and off if not.

int main(void) {

    pinModeINPUT(9);
    pinModeOUTPUT(13);

    while(1){
        int result = digitalRead(9);
        if (result == 0) {
            //pressed
            digitalWriteON(13);
            
        }
        else if(result == 1){
            //not pressed
            digitalWriteOFF(13);
        }
    }
}
*/
