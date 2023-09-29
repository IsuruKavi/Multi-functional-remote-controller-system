// PIC16F76 Configuration Bit Settings
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
#define LED1        PORTCbits.RC2
#define LED2        PORTCbits.RC3
#define Out_relay   PORTBbits.RB2
#define In_relay    PORTBbits.RB3
#define Down_relay  PORTBbits.RB1
#define Up_relay    PORTBbits.RB0
#define LED_OUT      PORTCbits.RC6
#define LED_IN       PORTCbits.RC7
#define LED_DOWN      PORTCbits.RC5
#define LED_UP        PORTCbits.RC4

//INPUTS

#define Pb PORTBbits.RB6
#define Out_button PORTBbits.RB7
#define In_button PORTBbits.RB4
#define Down_button PORTBbits.RB5
#define Up_button PORTCbits.RC0

void main(void) {
    // Outputs
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC7 = 0;
    TRISCbits.TRISC6 = 0;

    // Inputs
    TRISCbits.TRISC0 = 1;
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB7 = 1;


    //####Button_state(Bs)
    int Bs0 = 0;
    int Bs1=0;
    int Bs2=0;
    int Bs3=0;
    int Bs4=0;
    int Mode=0;
    int Val=0;
    LED1=1;
    LED2=0;
    In_relay=1;
    Out_relay=1;
    Up_relay=1;
    Down_relay=1;
      
    while (1) { 
        if ( Pb == 1 && Bs0==0 ) {
            __delay_ms(50);
            
            Mode=1;
            LED1=0;
            LED2=1;
                       
            Bs1=0;
            Bs2=0;
            Bs3=0;
            Bs4=0;
            Val=1;
            
            if( Pb==0){
                Bs0=1;
                                                      
            }}
        else if(Pb==1 && Bs0==1){
            __delay_ms(50);
            Mode=0;
            LED1=1;
            LED2=0;
            Val=0;
            
            if (Pb==0){
                Bs0=0;
                
                
            }
            }
 
//        code for Manual mode
        if(Mode==0 && Val==0){
           
            if(Out_button==1){
                if(In_relay==0 && Up_relay==0 && Down_relay==0){
                    Out_relay=1;
//                    LED_OUT=1;
//                   LED_IN=0;
                }
                    
            }else{
                Out_relay=0;
//                LED_OUT=0;
            }
            if(In_button==1){
                if(Out_relay==0 && Up_relay==0 && Down_relay==0){
                    In_relay=1;
//                    LED_OUT=0;
//                    LED_IN=1;
                }
                
            }else{
                In_relay=0;
//            LED_IN=0;
            }
               
            
            if(Down_button==1){
                if(Up_relay==0 && In_relay==0 && Out_relay==0){
                Down_relay=1;
//                LED_DOWN=1;
//                LED_UP=0;
                }
            }else{
                Down_relay=0;
//                LED_DOWN=0;
            }
            if(Up_button==1){
                if(Down_relay==0 && In_relay==0 && Out_relay==0 ){
                Up_relay=1;
//                LED_DOWN=0;
//                LED_UP=1;
                }
            }else{
                Up_relay=0;
//                LED_UP=0;
            }
            
            
        }
//        code for Auto Mode
        else {
            
            if(In_relay==1){
                
                
                for(int t=0; t<=3600; t++){
                   
                    
                    if(In_button==1 || Out_button==1 || Pb==1){
                        break;
                    }
                    else if(t==3600){
                        In_relay=0;
                        Bs3=0;
                    }
                    __delay_ms(50);
                }
                
            }
            if(Out_relay==1){
                
                for(int t=0; t<=3600; t++){
                   
                    
                    if(In_button==1 || Out_button==1|| Pb==1){
                        break;
                    }
                    else if(t==3600){
                        Out_relay=0;
                        Bs4=0;
                        
                    }
                    __delay_ms(50);
                }
                
            }
            if(Up_relay==1){
                
                
                for(int t=0; t<=2000; t++){
                   
                    
                    if(Up_button==1 || Down_button==1 || Pb==1){
                        break;
                    }
                    else if(t==2000){
                        Up_relay=0;
                        Bs1=0;
                    }
                    __delay_ms(50);
                }
                
            }
            if(Down_relay==1){
                
                
                for(int t=0; t<=2000; t++){
                   
                    
                    if(Up_button==1 || Down_button==1 || Pb==1){
                        break;
                    }
                    else if(t==2000){
                        Down_relay=0;
                        Bs2=0;
                    }
                    __delay_ms(50);
                }
                
            }
            
            
////            
            
//################################Down_button
            if(Down_button==1 && Bs1==0 && In_relay==0 && Out_relay==0 && Pb==0){
                __delay_ms(50);
                
                if(Up_relay==1){
                    Up_relay=0;
                    Bs2=0;
                    Bs1=1;
                    
                }else{
                Down_relay=1;
                if(Down_button==0){
                    
                    Bs1=1;
                         
                }}}
            else if(Down_button==1 && Bs1==1){
                __delay_ms(50);
                Down_relay=0;
                if(Down_button==0){
                    Bs1=0;
                }
            } 
            
//############################Up_button           
            
             if(Up_button==1 && Bs2==0 && In_relay==0 && Out_relay==0 && Pb==0){
                __delay_ms(50);
                
                if(Down_relay==1){
                    Down_relay=0;
                    Bs1=0;
                    Bs2=1;
                    
                }else{
                Up_relay=1;
                if(Up_button==0){
                    
                    Bs2=1;
                         
                }}}
            else if(Up_button==1 && Bs2==1){
                __delay_ms(50);
                Up_relay=0;
                if(Up_button==0){
                    Bs2=0;
                }
            }   
               
            
// ###########################In_button               
            
            if(In_button==1 && Bs3==0 && Up_relay==0 && Down_relay==0 && Pb==0){
                __delay_ms(50);
                
                if(Out_relay==1){
                    Out_relay=0;
                    Bs4=0;
                    Bs3=1;
                    
                }else{
                In_relay=1;
                if(In_button==0){
                    
                    Bs3=1;
                         
                }}}
            else if(In_button==1 && Bs3==1){
                __delay_ms(50);
                In_relay=0;
                if(In_button==0){
                    Bs3=0;
                }
            }
// ################################Out_button          
           if(Out_button==1 && Bs4==0 && Up_relay==0 && Down_relay==0 && Pb==0 ){
                __delay_ms(50);
                
                if(In_relay==1){
                    In_relay=0;
                    Bs3=0;
                    Bs4=1;
                    
                }else{
                Out_relay=1;
                if(Out_button==0){
                    
                    Bs4=1;
                         
                }}
                    
                }
            else if(Out_button==1 && Bs4==1){
                __delay_ms(50);
                Out_relay=0;
                if(Out_button==0){
                    Bs4=0;
                }
            }}
            
        // code for indicate led
        
        if(Up_relay==1){
            LED_UP=1;
        }else{
            LED_UP=0;
        }
        if(Down_relay==1){
            LED_DOWN=1;
        }else{
            LED_DOWN=0;
        }
        if(In_relay==1){
            LED_IN=1;
        }else{
            LED_IN=0;
        }
        if(Out_relay==1){
          LED_OUT=1;
        }else{
            LED_OUT=0;
        }               
        

            
       
    }
    
    }
