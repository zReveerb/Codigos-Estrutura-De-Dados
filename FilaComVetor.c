//Esta é uma implementação de fila comum utilizando vetores em C
//Criado por Heitor Gabriel 19/08/25

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct fila{
	int p;	//primeiro
	int u; //ultimo
	int info[TAM];
}Fila;


void Cria(Fila *f);
void InsereFinal(Fila *f, int elem);
void RemoveInicio(Fila *f);
int EhCheia(Fila f);
int EhVazia(Fila f);
void MostrarPrimeiro(Fila f);
void MostrarTudo(Fila *f);


int main(){
	puts("Bem vindo usuario! Este eh um programa de implementacao de filas em C.");
	Fila f;
	Cria(&f);
	
	int escolha = 0, elem;
		
	while(escolha != 5){
		printf("Digite\n1-Inserir no FINAL da FILA\n2-REMOVER o PRIMEIRO elemento\n3-MOSTRAR O PRIMEIRO\n4-chamar TODOS da FILA\n5-SAIR\n");
		scanf("%d",&escolha);
		system("cls || clear");

		switch(escolha){
			case 1:
				printf("DIGITE O ELEMENTO: ");
				scanf("%d", &elem);
				system("cls || clear");

				InsereFinal(&f, elem);
				break;
			case 2:
				RemoveInicio(&f);
				break;
			case 3:
				MostrarPrimeiro(f);
				break;
			case 4:
				MostrarTudo(&f);
				break;
		}
	}
	
	return 0;
}

void Cria(Fila *f){
	f->p = -1;
	f->u = -1;
}

void InsereFinal(Fila *f, int elem){
    
    if(EhVazia(*f)){
        f->p = f->u = 0;
        f->info[f->u] = elem;
    }
	else if(EhCheia(*f)){
		puts("Ja esta cheia!");
	}else if(f->u == TAM-1){
		f->u = 0;
		f->info[f->u] = elem;
	}else{
		f->u += 1;
		f->info[f->u] = elem;
	}
}

void RemoveInicio(Fila *f){
	if(EhVazia(*f)){
		puts("Ja vazia!");
	}else if (f->u == f->p){
		f->u = f->p = -1;
	}else{
		if(f->p == TAM-1){
			f->p = 0;
		}
		else{
			f->p += 1;
		}
	}
}

int EhCheia(Fila f){
	if(f.p == 0 && f.u == TAM-1 || f.p == f.u + 1){
		return 1;
	}
	return 0;
}

int EhVazia(Fila f){
	if(f.p == -1 && f.u == -1){
		return 1;
	}
	return 0;
}

void MostrarPrimeiro(Fila f){
	if(EhVazia(f)){
		puts("Fila vazia");
	}else{
		printf("PRIMEIRO DA FILA = %d\n", f.info[f.p]);
	}
}

void MostrarTudo(Fila *f){
	while(!(EhVazia(*f))){
		printf("PRIMEIRO DA FILA = %d\n", f->info[f->p]);
		RemoveInicio(f);
	}
}