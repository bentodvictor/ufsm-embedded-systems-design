#include <stdio.h>
#include <stdlib.h>

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
static int retornax (int x)
{
	return x;
}

static char * teste_retorna1_caso_recebe1(void)
{
    verifica("erro: deveria retornar 1", retornax(1) == 1);
    return 0;
}
/***********************************************/

static char * executa_testes(void)
{
	/* Colocar os testes aqui */
    /* Exemplo fictício!*/
	executa_teste(teste_retorna1_caso_recebe1);
    return 0;
}