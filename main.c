/**
 * Algoritmos de Ordenacao
 * main.c
 * Arquivo principal para a ordenacao
 * de inteiros atraves de diversos algoritmos
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * 
 * @version 1.0
 * 
 */

#include"sorts.h"

int main(int argc, char *argv[]) {
	
	if(argc < 3) {
		printf("Uso: ./trab4 <modo> <quantidade>\n");
		return 1;
	}
	
	int i, n=atoi(argv[2]);
	int v[n];
	
	for(i=0;i<n;i++)
		scanf("%d", &v[i]);
	
	if(!strcmp(argv[1], "bubble"))
		bubble(n, v);
	else if(!strcmp(argv[1], "shake"))
		shake(n, v);
	else if(!strcmp(argv[1], "insertion"))
		insertion(n, v);
	else if(!strcmp(argv[1], "shell"))
		shell(n, v);
	else if(!strcmp(argv[1], "selection"))
		selection(n, v);
	else if(!strcmp(argv[1], "rank"))
		rank(n, v);
	else if(!strcmp(argv[1], "quickprimeiro"))
		quickprimeiro(n, v, 0, n-1);
	else if(!strcmp(argv[1], "quickcentral"))
		quickcentral(n, v, 0, n-1);
	else if(!strcmp(argv[1], "quickrandom"))
		quickrandom(n, v, 0, n-1);
	else if(!strcmp(argv[1], "quickmediana3"))
		quickmediana3(n, v, 0, n-1);
	else if(!strcmp(argv[1], "merge"))
		merge(n, v);
	else if(!strcmp(argv[1], "heap"))
		heap(n, v);
	else if(!strcmp(argv[1], "radix"))
		radix(n, v);
	else if(!strcmp(argv[1], "radixbin"))
		radixbin(n, v);
	else
		n=-1;
	
	if(n==-1)
		printf("Modo invalido.\n");
	else
		for(i=0;i<n;i++)
			printf("%d\n", v[i]);
	
	return 0;
}
