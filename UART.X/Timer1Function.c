/* 
 * File:   Timer1Function.c
 * Author: tm2-weber
 *
 * Created on 13 November 2019, 12:25
 */
#include "Timer1Function.h"
#include "IOSetup.h"

void InterruptSetup(void){
    T1CON = 0;              //Clear the Timer 1 configuration
    TMR1 = 0;               //Reset the Timer 1 counter
    PR1 = 20000;            //Set the Timer 1 period (max 65535)
    T1CONbits.TCS = 0;      //Select the internal clock (Fosc/4)
    T1CONbits.TCKPS = 1;    //Prescaler (0=1:1, 1=1:8, )
    Timer1IntPrior = 6;     //Ser the Timer 1 interrupt priority to 3
    Timer1Enable = 1;       //Enable Timer 1 interrupt
    T1CONbits.TON = 1;      //Turn on Timer 1
}

int delay = 0, letterCount = 0;
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void){  
    IFS0bits.T1IF=0; //reset the timer 1 interrupt flag

/*
    
    if(delay == 10){
        if(letterCount == 25){
            letterCount = 0;
        }
        U2TXREG = 'A' + letterCount;
        
        letterCount++;
        
        LED2Latch = ~LED2Latch;
    }
    
    if(delay == 10){
        delay = 0;
    }
    
    delay++;
 
   */ 
    char string[] = {'M','A','G','L', ' '};
    sendString(&string);
}