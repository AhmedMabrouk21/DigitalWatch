/*
 * seven_segment_cfg.h
 *
 * Created: 12/1/2022 7:55:38 PM
 *  Author: AhmedMabrouk
 */ 


#ifndef SEVEN_SEGMENT_CFG_H_
#define SEVEN_SEGMENT_CFG_H_

#include "std_macros.h"

#define SEVEN_SEG_INIT_PORT() DDRD |= 0x7f; PORTD = 0x7f; SETBIT(DDRB,1); SETBIT(DDRB,3); SETBIT(DDRB,4); SETBIT(DDRB,5); SETBIT(DDRB,6); SETBIT(DDRB,7);
#define SS_PORT PORTD

#ifdef SS_ANODE
#define EN1_DIS() CLRBIT(PORTB,1);
#define EN1_EN()  SETBIT(PORTB,1);
#define EN2_DIS() CLRBIT(PORTB,3);
#define EN2_EN()  SETBIT(PORTB,3);
#define EN3_DIS() CLRBIT(PORTB,4);
#define EN3_EN()  SETBIT(PORTB,4);
#define EN4_DIS() CLRBIT(PORTB,5);
#define EN4_EN()  SETBIT(PORTB,5);
#define EN5_DIS() CLRBIT(PORTB,6);
#define EN5_EN()  SETBIT(PORTB,6);
#define EN6_DIS() CLRBIT(PORTB,7);
#define EN6_EN()  SETBIT(PORTB,7);
#else
#define EN1_DIS() SETBIT(PORTB,1);
#define EN1_EN()  CLRBIT(PORTB,1);
#define EN2_DIS() SETBIT(PORTB,3);
#define EN2_EN()  CLRBIT(PORTB,3);
#define EN3_DIS() SETBIT(PORTB,4);
#define EN3_EN()  CLRBIT(PORTB,4);
#define EN4_DIS() SETBIT(PORTB,5);
#define EN4_EN()  CLRBIT(PORTB,5);
#define EN5_DIS() SETBIT(PORTB,6);
#define EN5_EN()  CLRBIT(PORTB,6);
#define EN6_DIS() SETBIT(PORTB,7);
#define EN6_EN()  CLRBIT(PORTB,7);
#endif

#endif /* SEVEN_SEGMENT_CFG_H_ */