/*
	GIULIANO BOHN
	KELI RUPPENTHAL
	VICTOR D. BENTO
*/


#include <asf.h>
#include <stdio.h>
#define N 5

void configure_usart(void);

//	Instancia do modulo
struct usart_module usart_instance;
struct usart_config config_usart;

void configure_usart(void)
{
//	Configura SETUP
	usart_get_config_defaults(&config_usart);

//	Muda configurações do SETUP
	config_usart.baudrate    = 9600;
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
//! [setup_change_config]

//			FUNÇÃO PARA PRINTF
	stdio_serial_init(&usart_instance, EDBG_CDC_MODULE, &config_usart);

//	Setup enable
	usart_enable(&usart_instance);
}


int main(void)
{
	system_init();		// Inicialização
	configure_usart();		// Configuração da UART
	int counter = 0;		// Contador até o numero máximo do vetor
	char lim[N];			// Vetor para testar scanf

	//	Scanf, escreve caracteres em um vetor
	for (counter = 0; counter < N; counter++){
		printf("Informe o %d caracter do vetor:", counter+1);
		scanf("%c", &lim[counter]);
		printf("\n");
	}

	// Printa vetor de caracteres, testa PRINT
	printf("\n\n===================\nVETOR:\n");
	for (counter = 0; counter < N; counter++){
		printf("vetor[%d]: %d\n", counter, (int)lim[counter]);
	}
/*
	while (true) {
		break;
	}*/
}