/*
		Giuliano Bohn Benedeti Becker
		Keli Tauana Ruppenthal
		Victor Dallagnol Bento
*/

void gpio_config(uint8_t gpio_num, uint8_t pin, uint8_t dir);
void gpio_write(uint8_t gpio_num, uint8_t val);
void gpio_read(uint8_t gpio_num, uint8_t *val);
void gpio_toggle(uint8_t gpio_num);
void gpio_dir(uint8_t gpio_num);