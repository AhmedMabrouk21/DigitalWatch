/*
 * seven_segment.h
 *
 * Created: 12/1/2022 7:55:19 PM
 *  Author: AhmedMabrouk
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "std_macros.h"

void seven_seg_init(void);
void seven_seg_write(uint16_t);
void seven_seg_write_hours(uint8_t);
void seven_seg_write_minuits(uint8_t);
void seven_seg_write_seconds(uint8_t);

#endif /* SEVEN_SEGMENT_H_ */