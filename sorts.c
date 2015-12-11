/**
 * Algoritmos de Ordenacao
 * sorts.c
 * Arquivo com as implementacoes dos
 * algoritmos de ordenacao utilizados
 * Ver documentacao para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * 
 * @version 1.0
 * 
 */


#include"sorts.h"

/**
 * Bubble Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void bubble(int n, int v[]){
	
	int i, j, aux;
	
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(v[i]>v[j]){
				
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				
			}
	
}

/**
 * Shake Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void shake(int n, int v[]){
	
	int i, aux=0;
		
	while(!aux){
		
		aux = 1;
		
		for(i=1;i<n;i++)
			if(v[i]<v[i-1]){
					
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
				aux = 0;
				
			}
		
		if(aux)
			break;
		
		aux = 1;
		
		for(i=n-1;i>0;i--)
			if(v[i]<v[i-1]){
				
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
				aux = 0;
				
			}
			
	}
		
}

/**
 * Insertion Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void insertion(int n, int v[]){
	
	int i, j, aux;
	
	for(i=1;i<n;i++){
		
		aux = v[i];
		j = i-1;
		
		while(j>=0 && aux<v[j])
			v[j+1] = v[j--];
		
		v[j+1] = aux;
		
	}
	
}

/**
 * Shell Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void shell(int n, int v[]){
	
	int i, j, aux, gap=1;
	
	while(gap<n)
		gap = gap*3 +1;
	
	while(gap>1){
		
		gap /= 3;
		
		for(i=gap;i<n;i++){
			
			aux = v[i];
			j = i-gap;
			
			while(j>=0 && aux<v[j]){
				
				v[j+gap] = v[j];
				j -= gap;
				
			}
			
			v[j+gap] = aux;
			
		}
		
	}
	
}

/**
 * Selection Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void selection(int n, int v[]){
	
	int i, j, aux, min;
	
	for(i=0;i<n-1;i++){
		
		min = i;
		
		for(j=i+1;j<n;j++)
			if(v[j]<v[min])
				min = j;
		
		if(i!=min){
			
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
			
		}
		
	}
	
}

/**
 * Rank Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void rank(int n, int v[]){
	
	int i, j, aux, resp[n];
	
	for(i=0;i<n;i++){
		
		aux = 0;
		
		for(j=0;j<n;j++)
			if(v[i]>v[j])
				aux++;
		
		resp[aux] = v[i];
	
	}
	
	for(i=0;i<n;i++)
		v[i] = resp[i];
		
}

/**
 * Quick Sort com o primeiro elemento do bloco como pivo
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 * @param e menor indice do bloco
 * @param d maior indice do bloco
 */
void quickprimeiro(int n, int v[], int e, int d){
	
	int i, j, aux, pivo=e;
	
	for(i=e+1;i<=d;i++){
		
		j = i;
		
		if(v[j]<v[pivo]){
			
			aux = v[j];
			
			while(j>pivo)
				v[j] = v[(j--)-1];
			
			v[j] = aux;
			pivo++;
			
		}
		
	}
	
	if(pivo>e)
		quickprimeiro(n, v, e, pivo-1);
	if(pivo<d)
		quickprimeiro(n, v, pivo+1, d);
		
}

/**
 * Quick Sort com o elemento central do bloco como pivo
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 * @param e menor indice do bloco
 * @param d maior indice do bloco
 */
void quickcentral(int n, int v[], int e, int d){
	
	int i, j, aux, pivo=(e+d)/2;
	
	for(i=e+1;i<=d;i++){
		
		j = i;
		
		if(v[j]<v[pivo]){
			
			aux = v[j];
			
			while(j>pivo)
				v[j] = v[(j--)-1];
			
			v[j] = aux;
			pivo++;
			
		}
		
	}
	
	if(pivo>e)
		quickprimeiro(n, v, e, pivo-1);
	if(pivo<d)
		quickprimeiro(n, v, pivo+1, d);
		
}

/**
 * Quick Sort com um elemento aleatorio como pivo
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 * @param e menor indice do bloco
 * @param d maior indice do bloco
 */
void quickrandom(int n, int v[], int e, int d){
	
	int i, j, aux, pivo;
	
	srand(time(NULL));
	pivo = rand()%(d-e)+e;
	
	for(i=e+1;i<=d;i++){
		
		j = i;
		
		if(v[j]<v[pivo]){
			
			aux = v[j];
			
			while(j>pivo)
				v[j] = v[(j--)-1];
			
			v[j] = aux;
			pivo++;
			
		}
		
	}
	
	if(pivo>e)
		quickprimeiro(n, v, e, pivo-1);
	if(pivo<d)
		quickprimeiro(n, v, pivo+1, d);
		
}

/**
 * Quick Sort com mediana de 3 elementos como pivo
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 * @param e menor indice do bloco
 * @param d maior indice do bloco
 */
void quickmediana3(int n, int v[], int e, int d){
	
	int i, j, aux, pivo, m=(e+d)/2;
	
	if(e<m)
		if(m<d)
			pivo = m;
		else if(d<e)
			pivo = e;
		else
			pivo = d;
	else
		if(e<d)
			pivo = e;
		else if(d<m)
			pivo = m;
		else
			pivo = d;
	
	for(i=e+1;i<=d;i++){
		
		j = i;
		
		if(v[j]<v[pivo]){
			
			aux = v[j];
			
			while(j>pivo)
				v[j] = v[(j--)-1];
			
			v[j] = aux;
			pivo++;
			
		}
		
	}
	
	if(pivo>e)
		quickprimeiro(n, v, e, pivo-1);
	if(pivo<d)
		quickprimeiro(n, v, pivo+1, d);
		
}

/**
 * Merge Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void merge(int n, int v[]){
	
	int i, j, aux=1;
	
	while(aux<n){
		
		i=0;
		
		while(i+aux<n){
			
			j = i+2*aux;
			if(j>n)
				j=n;
			mergeaux(i, i+aux, j, v);
			i += 2*aux;
			
		}
		
		aux *= 2;
		
	}
	
}

/**
 * Funcao auxiliar do Merge Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void mergeaux(int p, int q, int r, int v[]){
	
	int i=p, j=q, k=0, aux[r-p];
	
	while(i<q && j<r)
		if(v[i]<=v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	
	while(i<q)
		aux[k++] = v[i++];
	
	while(j<r)
		aux[k++] = v[j++];
	
	for(i=p;i<r;i++)
		v[i] = aux[i-p];
	
}

/**
 * Heap Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void heap(int n, int v[]){
	
	int i=n/2, j, k, aux;
	
	while(1){
		
		if(i>0)
			aux = v[--i];
		else{
			
			if(--n == 0)
				return;
			aux = v[n];
			v[n] = v[0];
			
		}
		
		j = i;
		k = j*2 + 1;
		
		while(k<n){
			
			if(k+1<n && v[k+1]>v[k])
				k++;
			
			if(v[k]>aux){
				
				v[j] = v[k];
				j = k;
				k = j*2+1;
				
			}
			else
				break;
			
		}
		
		v[j] = aux;
		
	}
	
}

/**
 * Radix Sort
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void radix(int n, int v[]){
	
	int i, j=v[0], aux[n];
	long long int k=1;
	
	for(i=0;i<n;i++)
		if(v[i]>j)
			j=v[i];
	
	while(j/k>0){
		
		int bucket[10000] = {0};
		
		for(i=0;i<n;i++)
			bucket[(v[i]/k)%10000]++;
		
		for(i=1;i<10000;i++)
			bucket[i] += bucket[i-1];
		
		for(i=n-1;i>=0;i--)
			aux[--bucket[(v[i]/k)%10000]] = v[i];
		
		for(i=0;i<n;i++)
			v[i] = aux[i];
		
		k *= 10000;
		
	}
		
}

/**
 * Bubble Sort Binario
 * @param n tamanho do vetor
 * @param v vetor a ser ordenado
 */
void radixbin(int n, int v[]){
	
	int i, j=v[0], aux[n];
	long long int k=1;
	
	for(i=0;i<n;i++)
		if(v[i]>j)
			j=v[i];
	
	while(j/k>0){
		
		int bucket[2] = {0};
		
		for(i=0;i<n;i++)
			bucket[(v[i]/k)%2]++;
		
		for(i=1;i<2;i++)
			bucket[i] += bucket[i-1];
		
		for(i=n-1;i>=0;i--)
			aux[--bucket[(v[i]/k)%2]] = v[i];
		
		for(i=0;i<n;i++)
			v[i] = aux[i];
		
		k *= 2;
		
	}
		
}
