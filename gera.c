/**
 * Algoritmos de Ordenacao
 * gera.c
 * Arquivo gerador de numeros
 * conforme o modo desejado
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * 
 * @version 1.0
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv[]) {
	
	if(argc < 3) {
		printf("Uso: ./gera <modo> <quantidade>\n");
		return 1;
	}
	
	int i, n=atoi(argv[2]);
	srand(time(NULL));
	
	if(!strcmp(argv[1], "-a"))
		for(i=0;i<n;i++)
			printf("%d\n", rand());
	else if(!strcmp(argv[1], "-c"))
		for(i=1;i<=n;i++)
			printf("%d\n", i);
	else if(!strcmp(argv[1], "-d"))
		for(i=n;i>=1;i--)
			printf("%d\n", i);
	else
		printf("Modo invalido.\nModos disponiveis:\n-a\tGera numeros em ordem aleatoria\n-c\tGera numeros em ordem crescente\n-d\tGera numeros em ordem decrescente\n");
	
	return 0;
}
