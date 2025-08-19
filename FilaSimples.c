//Esta é uma implementação de fila comum utilizando listas em C
//Criado por Heitor Gabriel 19/08/25

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no *prox;
	int info;
}No;

typedef struct fila{
	struct no *last;
	struct no *first;
}Fila;

int EhVazia(Fila *f);
void Cria(Fila **f);
void InsereFinal(Fila **f, int elem);
void RemoveInicio(Fila **f);
void LiberaTudo(Fila **f);
void MostraFirst(Fila *f);
void MostraTudo(Fila **f);

int main(){
	puts("Bem vindo usuario! Este eh um programa de implementacao de filas em C.");
	Fila *f;
	Cria(&f);
	
	int escolha = 0, elem;
		
	while(escolha != 5){
		printf("Digite\n1-Inserir no FINAL da FILA\n2-REMOVER o PRIMEIRO elemento\n3-MOSTRAR O PRIMEIRO\n4-chamar TODOS da FILA\n5-SAIR\n");
		scanf("%d",&escolha);
		switch(escolha){
			case 1:
				printf("DIGITE O ELEMENTO: ");
				scanf("%d", &elem);
				InsereFinal(&f, elem);
				break;
			case 2:
				RemoveInicio(&f);
				break;
			case 3:
				MostraFirst(f);
				break;
			case 4:
				MostraTudo(&f);
				break;
		}
	}
	LiberaTudo(&f);
	return 0;
}



int EhVazia(Fila *f){
	return (!(f->first));
}

void Cria(Fila **f){
	*f = (Fila*)malloc(sizeof(Fila));
	if(!(*f)){
		puts("ERRO DE ALOCACAO DE MEMORIA!");
		exit(1);
	}
	(*f)->first = (*f)->last = NULL;
}

void InsereFinal(Fila **f, int elem){
	No *aux;
	aux = (No*)malloc(sizeof(No));
	if(!aux){
		puts("Erro de alocacao de memoria!");
		exit(1);
	}
	aux->info = elem;
	aux->prox = NULL;
	if(EhVazia(*f)){
		(*f)->first = (*f)->last = aux;
	}else{
		(*f)->last->prox = aux;
		(*f)->last = aux;
	}
}

void RemoveInicio(Fila **f){
	No *aux;
	if(EhVazia(*f)){
		puts("Ja esta vazia!");
	}else if((*f)->first == (*f)->last){
		aux = (*f)->first;
		(*f)->first = (*f)->last = NULL;
		free(aux);
	}else{
		aux = (*f)->first;
		(*f)->first = (*f)->first->prox;
		free(aux);
	}
}

void LiberaTudo(Fila **f){
	while(!(EhVazia(*f))){
		RemoveInicio(f);
	}
	free(*f);
}

void MostraFirst(Fila *f){
	if(EhVazia(f)){
		puts("Fila VAZIA!");
	}else{
		printf("Primeiro da fila = %d\n", f->first->info);
	}
}

void MostraTudo(Fila **f){
	while(!(EhVazia(*f))){
		printf("Primeiro da fila = %d\n", (*f)->first->info);
		RemoveInicio(f);
	}
}
