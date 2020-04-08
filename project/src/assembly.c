#include "buzzer.h"
#include "stateMachine.h" 



void do_something()
{ 	

	switch(buzzerChange)   // extern char buzzerChange (stateMachine.h) 
	{
	case 0: 
		buzzer_set_period(3500); 
		break; 
	case 1: 
		buzzer_set_period(0); 
		break; 
	}



}
