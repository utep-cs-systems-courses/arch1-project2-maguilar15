#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_goes_off(); 
void buzzer_set_period(short cycles);

#define F5 698
#define D6 1175
#define D5 587
#define E6 1319
#define F6 1397
#define C6 1047
#define A5 880
#define G5 784
#define E5 659

extern char begin_song; 
extern int note_pattern[43]; 
extern int note_velocity[43];
extern int delay[43]; 


#endif // included
