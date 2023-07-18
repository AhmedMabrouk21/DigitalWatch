/*
 * Project.c
 *
 * Created: 12/1/2022 7:37:11 PM
 * Author : AhmedMabrouk
 */ 

#include "std_macros.h"
#include "KEYPAD.h"
#include "LCD_cfg.h"
#include "LCD.h"
#include "seven_segment_cfg.h"
#include "seven_segment.h"
#include "eeprom.h"
#include "timer0.h"

#define HOURS_ADD 0
#define MINS_ADD  1
#define SECS_ADD  2

#define LAST_HOURS_ADD 3
#define LAST_MINS_ADD  4

extern uint32_t timer0_value_ms;
uint8_t set_flag;

int main(void)
{
	
	SETBIT(GICR,INT2);    // Interrupt to INT0 Pin
	SETBIT(MCUCSR,ISC01); // Interrupt at falling edge
	
	LCD_init();
	KEYPAD_init();
	seven_seg_init();
	timer0_CTC_init(250);
	
	#ifdef START
	eeprom_write(SECS_ADD,0);
	eeprom_write(MINS_ADD,0);
	eeprom_write(HOURS_ADD,0);
	#endif
	
	SETBIT(PORTB,2); // set pin 0 port b as pulled up input
	uint8_t KEY1, KEY2;

    while (1)
    {
		LCD_write_command(0x80);
		LCD_write_number(eeprom_read(HOURS_ADD));
		LCD_write_char(':');
		LCD_write_number(eeprom_read(MINS_ADD));
		LCD_write_char(':');
		LCD_write_number(eeprom_read(SECS_ADD));
		LCD_write_char(' ');
		LCD_write_char(' ');
		
		
		if (set_flag == 1) {
			KEY1 = KEYPAD_get_key()-48;
			eeprom_write(HOURS_ADD,(KEY1));
			seven_seg_write_hours(eeprom_read(HOURS_ADD));
			
			KEY2 = KEYPAD_get_key()-48;
			eeprom_write(HOURS_ADD,((KEY1*10)+KEY2));
			seven_seg_write_hours(eeprom_read(HOURS_ADD));
			
			set_flag ++;
		}
			
		if (set_flag == 2) {
			KEY1 = KEYPAD_get_key()-48;
			eeprom_write(MINS_ADD,(KEY1));
			seven_seg_write_minuits(eeprom_read(MINS_ADD));
			
			KEY2 = KEYPAD_get_key()-48;
			eeprom_write(MINS_ADD,((KEY1*10)+KEY2));
			seven_seg_write_minuits(eeprom_read(MINS_ADD));
			
			set_flag = 0;
		}
    }
	
}

// 16Mhz, CC = 64/16 = 4 usec, Tov = 250*4 usec = 1 msec

ISR(TIMER0_COMP_vect) {
	timer0_value_ms ++;
	
	if (timer0_value_ms == 1000) {
		eeprom_write(SECS_ADD,(eeprom_read(SECS_ADD)+1));
		timer0_value_ms = 0;
	}
	
	if (eeprom_read(SECS_ADD) == 60) {
		eeprom_write(SECS_ADD,0);
		eeprom_write(MINS_ADD,(eeprom_read(MINS_ADD)+1));
	}
	
	if (eeprom_read(MINS_ADD) == 60) {
		eeprom_write(MINS_ADD,0);
		eeprom_write(HOURS_ADD,(eeprom_read(HOURS_ADD)+1));
	}
	
	if (eeprom_read(HOURS_ADD) == 24) {
		eeprom_write(HOURS_ADD,0);
	}
	
	seven_seg_write_seconds(eeprom_read(SECS_ADD));
	if (set_flag != 1) {
		seven_seg_write_minuits(eeprom_read(MINS_ADD));
	}
	if (set_flag != 2) {
		seven_seg_write_hours(eeprom_read(HOURS_ADD));
	}
}

ISR(INT2_vect) {
	set_flag = 1;
}
