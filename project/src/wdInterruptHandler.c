#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){ 
  if (P2IFG & SWITCHES) { //searches for buttons
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler(); //take care of switches 
  }
void __interrupt_vec(WDT_VECTOR) WDT(){
    sm_update_led();//state machine
    led_update();
  }
}
