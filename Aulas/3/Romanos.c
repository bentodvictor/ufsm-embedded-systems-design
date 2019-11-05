#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* macros de testes - baseado em minUnit: www.jera.com/techinfo/jtns/jtn002.html */
#define verifica(mensagem, teste) do { if (!(teste)) return mensagem; } while (0)
#define executa_teste(teste) do { char *mensagem = teste(); testes_executados++; \
                                if (mensagem) return mensagem; } while (0)
int testes_executados = 0;

static char * executa_testes(void);

int main()
{
	 char *resultado = executa_testes();
     if (resultado != 0)
     {
         printf("%s\n", resultado);
     }
     else
     {
         printf("TODOS OS TESTES PASSARAM\n");
     }
     printf("Testes executados: %d\n", testes_executados);

     getch();
     return resultado != 0;
}

/* Teste de exemplo - apenas para demonstração */
/***********************************************/
static int Rom2Dec (char *romanos)
{
	int dec = 0 ;
	char temp = 'Z';
	
	while (*romanos != '\0'){
		if(*romanos == 'I'){
			dec += 1;
			temp = 'I';
		}
		
		if(*romanos == 'V'){
			dec += 5;
			if(temp == 'I'){
				dec -= 2;
			}
			temp = 'V';
		}
		
		if(*romanos == 'X'){
			dec += 10;
			if(temp == 'I'){
				dec -= 2;
			}
			if(temp == 'V'){
				dec -= 10;
			}
			temp = 'X';
		}
		
		if(*romanos == 'L'){
				dec += 50;
			if(temp == 'I'){
				dec -= 2;
			}
			if(temp == 'V'){
				dec -= 10;
			}
			if(temp == 'X'){
				dec -= 20;
			}
			temp = 'L';
		}
		if(*romanos == 'C'){
			dec += 100;
			if(temp == 'I'){
				dec -= 2;
			}
			if(temp == 'V'){
				dec -= 10;
			}
			if(temp == 'X'){
				dec -= 20;
			}if(temp == 'L'){
				dec -= 100;
			}
			temp = 'C';
		}
		if(*romanos == 'D'){
				dec += 500;
			if(temp == 'I'){
				dec -= 2;
			}
			if(temp == 'V'){
				dec -= 10;
			}
			if(temp == 'X'){
				dec -= 20;
			}if(temp == 'L'){
				dec -= 100;
			}
			if(temp == 'C'){
				dec -= 200;
			}
			temp = 'D';
		}
		if(*romanos == 'M'){
				dec += 1000;
				if(temp == 'I'){
				dec -= 2;
			}
			if(temp == 'V'){
				dec -= 10;
			}
			if(temp == 'X'){
				dec -= 20;
			}
			if(temp == 'L'){
				dec -= 100;
			}
			if(temp == 'C'){
				dec -= 200;
			}
			if(temp == 'D'){
				dec -= 1000;
			}
			temp = 'M';
		}
		romanos++;
	}	
	return dec;
}


static char * Teste_CXCIII_Retorna_193(void)
{
    verifica("erro: com CXCIII deveria retornar 193", Rom2Dec("CXCIII") == 193);
    return 0;
}

static char * Teste_I_Retorna_1(void)
{
    verifica("erro: com I deveria retornar 1", Rom2Dec("I") == 1);
    return 0;
}

static char * Teste_XX_Retorna_20(void)
{
    verifica("erro: com XX deveria retornar 20", Rom2Dec("XX") == 20);
    return 0;
}

// ERRO
static char * Teste_CC_Retorna_200(void)
{
    verifica("erro: com CC deveria retornar 200", Rom2Dec("ICC") == 200);
    return 0;
}

static char * Teste_III_Retorna_3(void)
{
    verifica("erro: com III deveria retornar 3", Rom2Dec("III") == 3);
    return 0;
}
/***********************************************/

static char * executa_testes(void)
{
	executa_teste(Teste_CXCIII_Retorna_193);
	executa_teste(Teste_I_Retorna_1);
	executa_teste(Teste_XX_Retorna_20);
	executa_teste(Teste_CC_Retorna_200);
	executa_teste(Teste_III_Retorna_3);
	
    return 0;
}
