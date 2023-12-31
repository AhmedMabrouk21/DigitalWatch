/*
 * std_macros.h
 *
 * Created: 11/22/2022 8:38:16 PM
 *  Author: AhmedMabrouk
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)


#endif /* STD_MACROS_H_ */