#include <stdio.h>
#define SIZE 100000

int fila[SIZE];
long passos = 0;

int fim = -1;

void enfileirar(int f[], int tamanho, int informacao){
	int i;
	for (i = 0; i < tamanho; i++){
		passos++;
		if (f[i] == 0){
			f[i] = informacao;
			return;
		}
	}	
	printf("\nFila cheia\n");
}

void listar(int f[], int tamanho){
	int i;
	printf("\n\nListando uma fila\n\n");
	for (i = 0; i < tamanho; i++){
		if (f[i] != 0)
			printf("[%d] -> %d\n",i , f[i]);
	}
}

int buscar(int f[], int tamanho, int chave){
	int i;
	for (i = 0; i < tamanho; i++){
		if (f[i] == chave){
			return i;
		}
	}
	return -1;
} 

void desenfileirar(int f[], int tamanho){
	int i;
	if (f[0] == 0){
		printf("\n\nFila vazia\n\n");
		return;
	}
	
	for (i = 0; i < tamanho - 1; i++){
		f[i] = f[i + 1];
	}
	f[i] = 0;
}

int main(int argc, char **argv)
{	
	int i = 0;
	while(++i <= SIZE){
		enqueue(fila,SIZE,i);
	}
	
	listar(fila, SIZE);

	printf("\n\n Passos: %ld", passos);
	
	return 0;
}
/*
int main(int argc, char **argv)
{
	int leitura, key;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		enfileirar(fila,SIZE,leitura);
	}
	
	listar(fila, SIZE);
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posicao = buscar(fila,SIZE,key);
	if (posicao != -1)
		printf("Chave encontrada na posicao %d\n",posicao);
	else
		printf("Chave inexistente\n");
				
	desenfileirar(fila,SIZE);
	desenfileirar(fila,SIZE);
	desenfileirar(fila,SIZE);
	listar(fila,SIZE);

	
	return 0;
}

*/
