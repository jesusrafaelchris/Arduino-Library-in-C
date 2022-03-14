//
//  Test.c
//  
//
//  Created by Christian Grinling on 10/11/2020.
//

#include <stdio.h>
#include "Arduino_Pin_Library.h"

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
