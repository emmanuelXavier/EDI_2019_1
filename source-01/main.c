#include <stdio.h>
#define SIZE 5

int pilha[SIZE];

void empilhar(int p[], int tamanho, int informacao){
	int i;
	for (i = 0; i < tamanho; i++){
		if (p[i] == 0){
			p[i] = informacao;
			return;
		}
	}	
	printf("\nPilha cheia\n");
}

void listar(int p[], int tamanho){
	int i;
	printf("\n\nListando uma pilha\n\n");
	for (i = tamanho -1; i >= 0; i--){
		if (p[i] != 0)
			printf("[%d] -> %d\n",i , p[i]);
	}
}

int buscar(int p[], int tamanho, int chave){
	int i;
	for (i = tamanho -1; i >= 0; i--){
		if (p[i] == chave){
			return i;
		}
	}
	return -1;
} 

void desempilhar(int p[], int tamanho){
	int i;
	for (i = tamanho - 1; i >= 0;i--){
		if (p[i] != 0){
			p[i] = 0;
			return;
		}
	}
	printf("\n\nA pilha esta vazia\n\n");
}



int main(int argc, char **argv)
{
	int leitura, key;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		empilhar(pilha,SIZE,leitura);
	}
	
	listar(pilha, SIZE);
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posicao = buscar(pilha,SIZE,key);
	if (posicao != -1)
		printf("Chave encontrada na posicao %d\n",posicao);
	else
		printf("Chave inexistente\n");
				
	desempilhar(pilha,SIZE);
	desempilhar(pilha,SIZE);
	desempilhar(pilha,SIZE);
	listar(pilha,SIZE);
	
	return 0;
}

