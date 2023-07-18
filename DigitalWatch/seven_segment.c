/*
 * seven_segment.c
 *
 * Created: 12/1/2022 7:55:04 PM
 *  Author: AhmedMabrouk
 */ 

#include "seven_segment.h"
#include "seven_segment_cfg.h"

uint8_t ss_data[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};

void seven_seg_init(void) {
	SEVEN_SEG_INIT_PORT()
	#ifdef SS_ANODE
	uint8_t i;
	for (i=0; i < 10; i++) {
		ss_data[i] ^= 0b01111111;
	}
	#endif
}

void seven_seg_write(uint16_t num) {
	EN1_DIS();
	EN2_DIS();
	EN3_DIS();
	EN4_DIS();
	
	if ((num >= 0) && (num <= 9)) {
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num];
		_delay_ms(1);
		
	} else if ((num >= 10) && (num <= 99)) {
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/10];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_ms(1);
		
	} else if ((num >= 100) && (num <= 999)) {
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/100];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[(num%100)/10];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_DIS();
		EN3_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_ms(1);
		
	} else if ((num >= 1000) && (num <= 9999)) {
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/1000];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[(num%1000)/100];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_DIS();
		EN3_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[(num%100)/10];
		_delay_ms(1);
		
		EN1_DIS();
		EN2_DIS();
		EN3_DIS();
		EN4_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_ms(1);
	}
	
}

void seven_seg_write_minuits(uint8_t num) {
	EN1_DIS();
	EN2_DIS();
	EN3_DIS();
	EN4_DIS();
	EN5_DIS();
	EN6_DIS();
	
	if ((num >= 0) && (num <= 9)) {
		EN4_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num];
		_delay_us(100);
		
		EN4_DIS();
		EN3_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[0];
		_delay_us(100);
		
	} else if ((num >= 10) && (num <= 99)) {
		EN3_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/10];
		_delay_us(100);
		
		EN3_DIS();
		EN4_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_us(100);
		
	}
}

void seven_seg_write_seconds(uint8_t num) {
	EN1_DIS();
	EN2_DIS();
	EN3_DIS();
	EN4_DIS();
	EN5_DIS();
	EN6_DIS();
	
	if ((num >= 0) && (num <= 9)) {
		EN2_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num];
		_delay_us(100);
		
		EN2_DIS();
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[0];
		_delay_us(100);
		
	} else if ((num >= 10) && (num <= 99)) {
		EN1_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/10];
		_delay_us(100);
		
		EN1_DIS();
		EN2_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_us(100);
		
	}
}

void seven_seg_write_hours(uint8_t num) {
	EN1_DIS();
	EN2_DIS();
	EN3_DIS();
	EN4_DIS();
	EN5_DIS();
	EN6_DIS();
	
	if ((num >= 0) && (num <= 9)) {
		EN6_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num];
		_delay_us(100);
		
		EN6_DIS();
		EN5_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[0];
		_delay_us(100);
		
		} else if ((num >= 10) && (num <= 99)) {
		EN5_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num/10];
		_delay_us(100);
		
		EN5_DIS();
		EN6_EN();
		SS_PORT &= 0b10000000;
		SS_PORT |= ss_data[num%10];
		_delay_us(100);
		
	}
}