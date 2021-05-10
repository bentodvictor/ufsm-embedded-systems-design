/*
		Giuliano Bohn Benedeti Becker
		Keli Tauana Ruppenthal
		Victor Dallagnol Bento
*/

void pwm_config(uint8_t pwm_num, uint8_t pin);

void pwm_on(uint8_t pwm_num); // ligar

void pwm_off(uint8_t pwm_num); // desligar

void pwm_set(uint8_t pwm_num, uint16_t duty); //trocar duty cycle (razão cíclica)