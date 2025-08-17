#include <stdio.h>
#define TAM 3

typedef struct pilha{
    int dado[TAM];
    int ctr;
}Pilha;

void CriaPilha(Pilha *pilha);
void push(Pilha *pilha, int elemento);
void pop(Pilha *pilha);
void VerTopo(Pilha pilha);
int PilhaCheia(Pilha pilha);
int PilhaVazia(Pilha pilha);

int main()
{
    Pilha pilha;
    CriaPilha(&pilha);
    int elem,escolha, sair = 1;
    while(sair){
        printf("Digite\n1-PUSH\n2-POP\n3-VER TOPO\n4-SAIR\n");
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
            case 4:
                sair = 0;
                break;
        }
    }
    return 0;
}

void CriaPilha(Pilha *pilha){
    pilha->ctr = -1;
}

void push(Pilha *pilha, int elemento){
    if(PilhaCheia(*pilha)){
        printf("Pilha CHEIA!\n");
        return;
    }
    else{
        pilha->ctr += 1;
        pilha->dado[pilha->ctr] = elemento;
    }
}

void pop(Pilha *pilha){
    if(PilhaVazia(*pilha)){
        printf("PILHA JA VAZIA\n");
        return;
    }
    else{
        pilha->ctr--;
    }
}

void VerTopo(Pilha pilha){
    if(PilhaVazia(pilha)){
        printf("PILHA VAZIA\n");
    }
    else{
        printf("TOPO = %d\n", pilha.dado[pilha.ctr]);
    }
}

int PilhaVazia(Pilha pilha){
    if(pilha.ctr == -1){
        return 1;
    }
    return 0;
}
int PilhaCheia(Pilha pilha){
    if(pilha.ctr == TAM-1){
        return 1;
    }
    return 0;
}