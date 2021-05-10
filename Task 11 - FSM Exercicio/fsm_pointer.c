/*
	Giuliano Bohn
	Keli Ruppenthal
	Victor D. Bento
*/

#include <asf.h>
#include <scanf_printf.h>
#define MAX_BUFFER 30

/* estados */
typedef enum {
    ST_STX = 0, ST_QTD = 1, ST_DATA = 2, ST_CHK = 3, ST_ETX = 4
} States;

/* definição de um tipo - Action */
typedef void (*Action)(uint8_t data);

/* estrutura para cada estado */
struct StateMachine {
    States state;
    unsigned char buffer[MAX_BUFFER];
    unsigned char chkBuffer;
    int indBuffer;
    int qtdBuffer;
    Action action[] = {stSTX, stQtd, stData, stChk, stETX};
} sm;
 
void stSTX(unsigned char data)
{
    printf("State: STX - Data: %c\n", data);
	if (data == STX) {
        sm.indBuffer = sm.qtdBuffer = 0;
        sm.chkBuffer = 0;
        sm.state = ST_QTD;
    }
}
 
void stQtd(unsigned char data)
{
    printf("State: QTD - Data: %c\n", data);
    sm.qtdBuffer = data;
    sm.state = ST_DATA;
}
 
void stData(unsigned char data)
{
    printf("State: DATA - Data: %c\n", data);
    sm.buffer[sm.indBuffer++] = data;
    sm.chkBuffer ^= data;
    if (--sm.qtdBuffer == 0) {
        sm.state = ST_CHK;
    }
}
 
void stChk(unsigned char data)
{
    printf("State: CHK - Data: %c\n", data);
    if (data == sm.chkBuffer) {
        sm.state = ST_ETX;
    }
    else {
        sm.state = ST_STX;
    }
}
 
void stETX(unsigned char data)
{
    printf("State: ETX - Data: %c\n", data);
    if (data == ETX) {
        handlePackage(sm.buffer, sm.indBuffer);
    }
    sm.state = ST_STX;
}
 
void handleRx(unsigned char *data, int qtd)
{
    int i;
	
	/* for para percorrer dados	*/
    for (i = 0; i &lt; qtd; i++)
        sm.action[sm.state](data[i]);
	
    printf("Fim da leitura de dados.\n");
}

/*	Inicialização da maquina de estados	*/
void initFSM()
{
	sm.state = ST_STX;
	sm.buffer[0] = 0;
	sm.chkBuffer = 0;
	sm.indBuffer = 0;
	sm.qtdBuffer = 0;
}

/* 	Simulação	*/
int main()
{
	system_init();
	
	/* configura scanf e printf */
	configure_usart();
	
	unsigned char data[] = {STX, 5, 11, 22, 33, 44, 55, 39, ETX};
	
	initFSM();
	
	handleRx(data, sizeof(data));
	
	return 0;
}