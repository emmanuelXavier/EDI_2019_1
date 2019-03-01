#include <stdio.h>
#define SIZE 5

typedef int numerico;

typedef struct SPilha {
	int topo;
	int dados[SIZE];
} TPilha;

TPilha pilha;

void push(int tamanho, int informacao){
	if (pilha.topo + 1 == tamanho){
		printf("\nPilha cheia\n\n");
		return;
	}
		
	pilha.dados[++pilha.topo] = informacao;
}

void listar(){
	int i;
	printf("\n\nListando uma pilha\n\n");
	for (i = pilha.topo; i >= 0; i--){
			printf("[%d] -> %d\n",i , pilha.dados[i]);
	}
}

int buscar(int chave){
	int i;
	for (i = pilha.topo; i >= 0; i--){
		if (pilha.dados[i] == chave){
			return i;
		}
	}
	return -1;
} 

void pop(){
	if (pilha.topo == -1){
		printf("\nPilha vazia\n\n");
		return;
	}
	pilha.topo--;
}


int main(int argc, char **argv)
{
	int leitura, key;
	
	pilha.topo = -1;
	
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		push(SIZE,leitura);
	}
	
	listar();
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posicao = buscar(key);
	if (posicao != -1)
		printf("Chave encontrada na posicao %d\n",posicao);
	else
		printf("Chave inexistente\n");
				
	pop();
	pop();
	pop();
	listar();
	
	return 0;
}

