#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    struct pilha *prox;
    float info;
}Pilha;

int PilhaVazia(Pilha *pilha);
void push (Pilha **pilha, float elem);
float pop(Pilha **pilha);
void operacao(Pilha **pilha, char op);
void CriaPilha(Pilha **pilha);
void resultado(Pilha *pilha);
void Libera (Pilha **pilha);

int main()
{
    char op;
    float num;
    Pilha *pilha;
    CriaPilha(&pilha);
    printf("Bem vindo a calculadora pos fixada! digite 's' para sair!\n");
    do{
        scanf(" %c", &op);
        
        if(op == '+' || op == '-' || op == '*' || op == '/'){
            operacao(&pilha,op);
        }
        else if(op == 's'){
            resultado(pilha);
            Libera(&pilha);
            break;
        }
        else{
            ungetc(op,stdin);
            scanf("%f", &num);
            push(&pilha, num);
        }
    }while(1);

    return 0;
}

int PilhaVazia(Pilha *pilha){
    if(!pilha){
        return 1;
    }
    return 0;
}

void push(Pilha **pilha, float elem){
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

float pop(Pilha **pilha){
    Pilha *aux;
    aux = *pilha;
    if(PilhaVazia(*pilha)){
        return 0;
    }
    float valor = (*pilha)->info;
    *pilha = (*pilha)->prox;
    free(aux);
    return valor;
}

void operacao(Pilha **pilha, char op){
    float v1, v2;
    if(PilhaVazia(*pilha) || PilhaVazia((*pilha)->prox)){
        printf("FALTAM OPERANDOS PARA ESTA OPERACAO!\n");
        return;
    }
    v2 = pop(pilha);
    v1 = pop(pilha);
    
    switch(op){
        case '+':
            push(pilha,v1+v2);
            break;
        case '-':
            push(pilha, v1-v2);
            break;
        case '*':
            push(pilha,v1*v2);
            break;
        case '/':
            if(v2 == 0){
                printf("DIVISAO POR ZERO!\n");
                Libera(pilha);
                exit(1);
            }
            push(pilha,v1/v2);
            break;
        }
    }
    
void CriaPilha(Pilha **pilha){
    *pilha = NULL;
}

void resultado(Pilha *pilha){
    if(PilhaVazia(pilha)){
        printf("VAZIO\n");
    }
    else{
        printf("RESULTADO = %.2f\n", pilha->info);
    }
}

void Libera(Pilha **pilha){
    while(!(PilhaVazia(*pilha))){
        pop(pilha);
    }
}

    
