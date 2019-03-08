#include <stdio.h>
#define SIZE 5

typedef struct SFila{
	int inicio;
	int fim;
	int dados[SIZE];
} TFila;

TFila fila;

long passos = 0;

void enqueue(int tamanho, int informacao){
	if ((fila.fim != -1) && ((fila.fim + 1) % tamanho == fila.inicio)){
		printf("\n\nFila cheia\n\n");
		return;
	}
	fila.fim = (fila.fim + 1) % tamanho;
	fila.dados[fila.fim] = informacao;
	passos++;
}

void listar(int tamanho){
	int i = fila.inicio;
	
	printf("\n\nListando a fila\n\n");
	do{
		printf("%d ",fila.dados[i]);
		i = (i + 1) % tamanho;
	}while ((fila.fim + 1) % tamanho != i);	
}	
	
int buscar(int tamanho, int chave){
	int i = fila.inicio;
	
	printf("\n\nListando a fila\n\n");
	do{
		if (fila.dados[i] == chave)
			return i;
		i = (i + 1) % tamanho;
	}while ((fila.fim + 1) % tamanho != i);	
	
	return -1;
}

void dequeue(int tamanho){
	fila.inicio = (fila.inicio + 1) % tamanho;
}



/*
int main(int argc, char **argv)
{	
	fila.inicio = 0;
	fila.fim = -1;
	int i = 0;
	while(++i <= SIZE){
		enqueue(SIZE,i);
	}
	
	listar(SIZE);

	printf("\n\n Passos: %ld", passos);
	
	return 0;
}
*/
int main(int argc, char **argv)
{
	fila.inicio = 0;
	fila.fim = -1;
	int leitura, key;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		enqueue(SIZE,leitura);
	}
	
	
	listar(SIZE);
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posicao = buscar(SIZE,key);
	if (posicao != -1)
		printf("Chave encontrada na posicao %d\n",posicao);
	else
		printf("Chave inexistente\n");
				
	dequeue(SIZE);
	dequeue(SIZE);
	dequeue(SIZE);
	listar(SIZE);


	return 0;
}


