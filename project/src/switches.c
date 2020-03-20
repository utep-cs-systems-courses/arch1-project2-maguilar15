#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"
#include "buzzer.h"


/* Boolean Switches */ 

char switch_state_down1,
     switch_state_down2,
     switch_state_down3,
     switch_state_down4,
     switch_state_changed;    

char ledMode =0;
char buzzerChange =0;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  
  /* update switch state */
  P2IES |= (p2val & SWITCHES);	/* if up, then down */
  P2IES &= (p2val | ~SWITCHES);	/* if down, then up */
  return p2val;
}

void switch_init()		/* make switch */
{  
  P2REN |= SWITCHES;		/* enable resistors */
  P2IE = SWITCHES;		/* enable interrupts */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down2 = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  switch_state_down3 = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  switch_state_down4 = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  
  if(switch_state_down1){
    ledMode =1; //RED
  }
  
  if(switch_state_down2){
    ledMode = 2; //GREEN
  }

  if(switch_state_down3){
    if(buzzerChange){
      ledMode = 3;
      buzzerChange =0;
    }else{
      ledMode = 3; //SOUND
      buzzerChange =1;
    }
  }
  
  if(switch_state_down4){
    ledMode = 4; //DIM-LIGHTS
  }
  
}
