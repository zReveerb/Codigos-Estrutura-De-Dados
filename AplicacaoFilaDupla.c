#include <stdlib.h>
#include <stdio.h>


typedef struct filadupla{
    struct filadupla *prox;
    struct filadupla *ant;
    int info;
}FilaD;

typedef struct extremos{
    struct filadupla *first;
    struct filadupla *last;
}Extremos;


void InsereInicio(Extremos **lf, int elem);
void InsereFim(Extremos **lf, int elem);
void RemoveInicio(Extremos **lf);
void RemoveFim(Extremos **lf);
void MostraFirst(Extremos *lf);
void MostraLast(Extremos *lf);
void Cria(Extremos **lf);
int EhVazia(Extremos *lf);
void LiberaMemoria(Extremos **lf);
int main()
{
    printf("Bem vindo usuário!\n");
    Extremos *lf;
    int escolha = -1, elem;
    Cria(&lf);
    while(escolha != 7){
        printf("Digite\n1-InserirInicio\n2-InserirFim\n3-RemoverInicio\n4-RemoverFim\n5-MostrarFirst\n6-MostrarLast\n7-SAIR\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Digite o elemento de inserçao: ");
                scanf("%d", &elem);
                InsereInicio(&lf, elem);
                break;
            case 2:
                printf("Digite o elemento de inserçao: ");
                scanf("%d", &elem);
                InsereFim(&lf, elem);
                break;
            case 3:
                RemoveInicio(&lf);
                break;
            case 4:
                RemoveFim(&lf);
                break;
            case 5:
                MostraFirst(lf);
                break;
            case 6:
                MostraLast(lf);
                break;
        }
    }
    LiberaMemoria(&lf);
    return 0;
}

void Cria(Extremos **lf){
    *lf = (Extremos*)malloc(sizeof(Extremos));
    if(!(*lf)){
        puts("ERRO DE ALOCACAO!");
        exit(1);
    }
    (*lf)->first = (*lf)->last = NULL;
}
int EhVazia(Extremos *lf){
    if(lf->first == NULL){
        return 1;
    }
    return 0;
}

void InsereFim(Extremos **lf, int elem){
    FilaD *aux;
    aux = (FilaD*)malloc(sizeof(FilaD));
    if(!aux){
        puts("ERRO DE ALOCACAO!");
        exit(1);
    }
    aux->info = elem;
    if(EhVazia(*lf)){
        aux->prox = aux->ant = NULL;
        (*lf)->last = (*lf)->first = aux;
    }
    else{
        aux->prox = NULL;
        aux->ant = (*lf)->last;
        (*lf)->last->prox = aux;
        (*lf)->last = aux;
    }
}

void InsereInicio(Extremos **lf, int elem){
    FilaD *aux;
    aux = (FilaD*)malloc(sizeof(FilaD));
    if(!aux){
        puts("ERRO DE ALOCACAO!");
        exit(1);
    }
    aux->info = elem;
    if(EhVazia(*lf)){
        aux->prox = aux->ant = NULL;
        (*lf)->last = (*lf)->first = aux;
    }
    else{
        aux->ant = NULL;
        aux->prox = (*lf)->first;
        (*lf)->first->ant = aux;
        (*lf)->first = aux;
    }
}

void RemoveFim(Extremos **lf){
    FilaD *aux;
    if(EhVazia(*lf)){
        puts("VAZIA JA");
    }else if( (*lf)->first == (*lf)->last){
        aux = (*lf)->last;
        (*lf)->first = (*lf)->last = NULL;
        free(aux);
    }else{
        aux = (*lf)->last;
        aux->ant->prox = NULL;
        (*lf)->last = (*lf)->last->ant;
        free(aux);
    }
}

void RemoveInicio(Extremos **lf){
    FilaD *aux;
    if(EhVazia(*lf)){
        puts("VAZIA JA");
    }else if( (*lf)->first == (*lf)->last){
        aux = (*lf)->first;
        (*lf)->first = (*lf)->last = NULL;
        free(aux);
    }else{
        aux = (*lf)->first;
        aux->prox->ant = NULL;
        (*lf)->first = (*lf)->first->prox;
        free(aux);
    }
}

void MostraLast(Extremos *lf){
    if(EhVazia(lf)){
        puts("VAZIA");
    }else{
        printf("O ULTIMO EH %d\n", lf->last->info);
    }
}

void MostraFirst(Extremos *lf){
    if(EhVazia(lf)){
        puts("VAZIA");
    }else{
        printf("O PRIMEIRO EH %d\n", lf->first->info);
    }
}

void LiberaMemoria(Extremos **lf){
    while(!(EhVazia(*lf))){
        RemoveInicio(lf);
    }
    free(*lf);
}