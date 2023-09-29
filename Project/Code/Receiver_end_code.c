/// PIC16F76 Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bit (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 16000000
#include <xc.h>
//OUTPUTS

#define Out_relay   PORTBbits.RB3
#define In_relay    PORTBbits.RB2
#define Down_relay  PORTBbits.RB1
#define Up_relay    PORTBbits.RB0

//INPUTS

#define Transmission_enable PORTAbits.RA0
#define Out_button PORTCbits.RC0
#define In_button PORTCbits.RC1
#define Down_button PORTCbits.RC2
#define Up_button PORTCbits.RC3

void main(void) {
    // Outputs
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3= 0;
    

    // Inputs
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC3 = 1;
    TRISAbits.TRISA0 = 1;
    
    In_relay=1;
    Out_relay=1;
    Up_relay=1;
    Down_relay=1; 
    __delay_ms(100);

    while (1) {
        //code for turning of relays when signal isn't received for 400ms 
        if(Transmission_enable==0 ){
            for(int t=0; t<=8; t++){
                    __delay_ms(50);
                    if(Transmission_enable==1){
                        break;
                    }
                    else if(t==8){
                        Up_relay=1;
                        Down_relay=1;
                        In_relay=1;
                        Out_relay=1;
                         }
                    
                }
        }//code to operate the relays.
        else{
         if(Up_button==1 && Down_button==0 && In_button==0 && Out_button==0){
           
            Up_relay=0;
                
        }
        if(Up_button==0){
            Up_relay=1;
            
        }
        if(Down_button==1 && Up_button==0 && In_button==0 && Out_button==0){
            
            Down_relay=0;
                
        }if(Down_button==0){
            Down_relay=1;
        }
        
        if(In_button==1 && Down_button==0 && Up_button==0 && Out_button==0){
           
            In_relay=0;
           
        }if(In_button==0){
            In_relay=1;
        
        }
        if(Out_button==1 &&  Down_button==0 && In_button==0 && Up_button==0){
            
            Out_relay=0;
            
        }if(Out_button==0){
            Out_relay=1;
        }
        
        }
        
    } }
