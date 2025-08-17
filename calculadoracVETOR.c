#include <stdlib.h>
#include <stdio.h>
#define TAM 10

typedef struct pilha{
    float info[TAM];
    int ctr;
}Pilha;


void push(Pilha *pilha, float elem);
float pop(Pilha *pilha);
void cria(Pilha *pilha);
void operacao(Pilha *pilha, char op);
int PilhaVazia(Pilha *pilha);
int PilhaCheia(Pilha *pilha);
void result(Pilha *pilha);

int main()
{
    Pilha pilha;
    cria(&pilha);
    
    char escolha;
    float num;
    
    printf("BEM VINDO A CALCULADORA! DIGITE 's' para sair!\n");
    
    do{
        scanf(" %c", &escolha);
        if(escolha == '+' || escolha == '-' || escolha == '/' || escolha == '*'){
            operacao(&pilha, escolha);
        }
        else if(escolha == 's'){
            result(&pilha);
            break;
        }
        else{
            ungetc(escolha, stdin);
            scanf("%f", &num);
            push(&pilha, num);
        }
    }while(1);
    cria(&pilha);
    return 0;
}

void push(Pilha *pilha, float elem){
    if(PilhaCheia(pilha)){
        printf("PILHA CHEIA!\n");
        return;
    }
    (pilha->ctr)++;
    pilha->info[pilha->ctr] = elem;
}

float pop(Pilha *pilha){
    if(PilhaVazia(pilha)){
        return 0;
    }
    return pilha->info[(pilha->ctr)--];
}
void operacao(Pilha *pilha, char op){
    if(PilhaVazia(pilha)){
        printf("VAZIO\n");
        return;
    }
    float v1,v2;
    v2 = pop(pilha);
    if(PilhaVazia(pilha)){
        printf("SEM OPERANDOS O SUFICIENTE!");
        push(pilha,v2);
        return;
    }
    v1 = pop(pilha);
    
    switch(op){
        case '+':
            push(pilha,v1+v2);
            break;
        case '-':
            push(pilha, v1-v2);
            break;
        case '*':
            push(pilha, v1*v2);
            break;
        case '/':
            if(v2 == 0){
                puts("DIVISAO POR ZERO!");
                exit(1);
            }
            push(pilha,v1/v2);
            break;
    }
}

void cria(Pilha *pilha){
    pilha->ctr = -1;
}

int PilhaVazia(Pilha *pilha){
    if(pilha->ctr == -1){
        return 1;
    }
    return 0;
}

int PilhaCheia(Pilha *pilha){
    if(pilha->ctr == TAM-1){
        return 1;
    }
    return 0;
}

void result(Pilha *pilha){
    if(PilhaVazia(pilha)){
        printf("VAZIO!\n");
    }
    else{
        printf("RESULTADO = %.2f\n", pilha->info[pilha->ctr]);
    }
}