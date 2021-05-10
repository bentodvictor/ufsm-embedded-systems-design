/*
	Victor Dallagnol Bento
	Victor Oliveira Costa
	Vinicius Bohrer dos Santos
*/

struct adc_module adc_instance;

uint8_t adc[2];

void adc_config(uint8_t adc_num, uint8_t adc_chan,uint8_t adc_res, uint16_t adc_freq){
	struct adc_config config_adc;
	
	adc[adc_num] = adc_chan;

	adc_get_config_defaults(&config_adc);
	
	// resolution
	if(adc_res == 8 || adc_res == 10 || adc_res == 12){
		config_adc.resolution = adc_res;
	}
	else{
		config_adc.resolution = 10;
	}
	
	// frequency
	config_adc.clock_prescaler =  system_gclk_gen_get_hz(GCLK_GENERATOR_0)/adc_freq;
	
	config_adc.positive_imput = ADC_POSITIVE_IMPUT_TEMP;
	
	adc_init(&adc_instance, ADC, &config_adc);
	
	adc_enable(&adc_instance);
	
}


void uint16_t adc_read(uint8_t adc_num, uint8_t adc_chan){
	system init();
	
	adc[adc_num] = adc_chan;
	
	configure_adc();
	
	adc_start_conversion(&adc_instance);
	
	uint16_t result;
    
	do {
     
    } while (adc_read(&adc_instance, &result) == STATUS_BUSY);
	while(1){
	
	}
}