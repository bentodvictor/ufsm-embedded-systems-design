/*
		Giuliano Bohn Benedeti Becker
		Keli Tauana Ruppenthal
		Victor Dallagnol Bento
*/


#ifndef DRIVER-TIMER_H_
#define DRIVER-TIMER_H_


timer_config(uint8_t timer_num, uint16_t period_ms);
timer_start(uint8_t timer_num);
timer_stop(uint8_t timer_num);
uint32_t timer_count(uint8_t timer_num);
timer_delay(uint8_t timer_num, uint16_t period_ms);


#endif /* DRIVER-TIMER_H_ */