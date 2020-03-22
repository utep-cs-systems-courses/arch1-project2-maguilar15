#include <msp430.h>
#include "buzzer.h"
#include "stateMachine.h"
#include "switches.h"
#include "led.h"

static char pwmCount = 0;
void sm_update_led()
{
  // PWM mod 3 === 0  ^ PWM mod 3 === 2	
 
  pwmCount = (pwmCount+1)%3; //range from 0-2

  static char new_red, new_green;
  
  switch(ledMode){
  case 1:
    new_red= 1;
    new_green = 1;
    break;
  case 2:
    new_red =0;
    new_green=0;
    break;
  case 3:
    switch(buzzerChange){
    case 0:
      buzzer_set_period(3500);
      break;
    case 1:
      buzzer_set_period(0);
      break;
    }
    break; // break from main statement
  case 4:
    new_red = (pwmCount < 1); //red dims
    new_green = (pwmCount < 1); //green dims
    break;
  }
  if(red_on != new_red || green_on != new_green){
    red_on = new_red;
    green_on = new_green;
    led_changed = 1;
  }
  

}
