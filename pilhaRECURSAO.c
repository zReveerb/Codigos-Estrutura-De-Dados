#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
    struct pilha *prox;
    int info;
}Pilha;

void percorreInverso(Pilha **pilha);
void percorre(Pilha **pilha);
int PilhaVazia(Pilha *pilha);
void push(Pilha **pilha, int elem);
void pop(Pilha **pilha);
void CriaPilha(Pilha **pilha);
void VerTopo(Pilha *pilha);
void Libera(Pilha **pilha);
int main()
{
    Pilha *pilha;
    CriaPilha(&pilha);
    int elem,escolha, sair = 1;
    while(sair){
        printf("Digite\n1-PUSH\n2-POP\n3-VER TOPO\n4-PERCORRE INICIO\n5-PERCORRE DO FINAL\n6-SAIR\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Digite o elemento do push:");
                scanf("%d", &elem);
                push(&pilha, elem);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                VerTopo(pilha);
                break;
            case 6:
                sair = 0;
                break;
            case 4:
                percorre(&pilha);
                break;
            case 5:
                percorreInverso(&pilha);
                break;
        }
    }
    Libera(&pilha);
    return 0;
}


void percorreInverso(Pilha **pilha){
    if(PilhaVazia(*pilha)){
        return;
    }
    else{
        percorreInverso(&(*pilha)->prox);
        printf("Elemento: %d\n", (*pilha)->info);
    }
}

void percorre(Pilha **pilha){
    if(PilhaVazia(*pilha)){
        return;
    }
    else{
        
        printf("Elemento: %d\n", ((*pilha)->info));
        percorre(&(*pilha)->prox);
    }
}

void CriaPilha(Pilha **pilha){
    *pilha = NULL;
}

void push(Pilha **pilha, int elem){
    Pilha *aux;
    aux = (Pilha*)malloc(sizeof(Pilha));
    aux->info = elem;
    if(PilhaVazia(*pilha)){
        aux->prox = NULL;
        *pilha = aux;
        return;
    }
    aux->prox = *pilha;
    *pilha = aux;
}

void pop(Pilha **pilha){
    Pilha *aux;
    if(PilhaVazia(*pilha)){
        printf("PILHA VAZIA\n");
        return;
    }
    aux = *pilha;
    *pilha = (*pilha)->prox;
    free(aux);
}

void VerTopo(Pilha *pilha){
    if(PilhaVazia(pilha)){
        printf("PILHA VAZIA!\n");
    }
    else{
        printf("TOPO = %d\n", pilha->info);
    }
}

void Libera(Pilha **pilha){
    while(!(PilhaVazia(*pilha))){
        pop(pilha);
    }
}

int PilhaVazia(Pilha *pilha){
    if(pilha == NULL){
        return 1;
    }
    return 0;
}