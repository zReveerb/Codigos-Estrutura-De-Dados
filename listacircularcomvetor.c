#include <stdlib.h>
#include <stdio.h>
#define TAM 10

typedef struct lista{
    int dados[TAM];
    int i;
    int f;
}Lista;

void CriaLista(Lista *lista);
int EhVazia(Lista lista);
int EhCheia(Lista lista);
void MostrarOrdem(Lista lista);
void MostrarInverso(Lista lista);
void InsereInicio(Lista *lista, int elem);
void InsereFim(Lista *lista, int elem);
void RemoveInicio(Lista *lista);
void RemoveFim(Lista *lista);

int main()
{
    Lista lista;
    CriaLista(&lista);
    
    int sair = 0, escolha, elemento;
    
    while(!sair){
        printf("Digite\n1- Inserir no Inicio\n2- Inserir no Fim\n3- Remover no Inicio\n4- Remover no Final\n5- Mostrar do Inicio\n6- Mostrar do Final\n7- Sair\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Digite o elemento o qual deseja inserir: ");
                scanf("%d", &elemento);
                InsereInicio(&lista, elemento);
                break;
            case 2:
                printf("Digite o elemento o qual deseja inserir: ");
                scanf("%d", &elemento);
                InsereFim(&lista, elemento);
                break;
            case 3:
                RemoveInicio(&lista);
                break;
            case 4:
                RemoveFim(&lista);
                break;
            case 5:
                MostrarOrdem(lista);
                break;
            case 6:
                MostrarInverso(lista);
                break;
            case 7:
                sair += 1;
                break;
                
        }
        
    }

    return 0;
}

void CriaLista(Lista *lista){
    lista->i = -1;
    lista->f = -1;
}

int EhVazia(Lista lista){
    if(lista.i == -1 && lista.f == -1)  {
        return 1;
    }
    return 0;
}

int EhCheia(Lista lista){
    if((lista.i == 0 && lista.f == TAM-1) || lista.i - 1 == lista.f){ // Caso Inicio 0 Final 9 (cheio) e Caso Inicio 3 Final 2 (Cheio tambem)
        return 1;
    }
    return 0;
}

void InsereFim(Lista *lista, int elem){
    if(EhVazia(*lista)){
        lista->i += 1;
        lista->f += 1;
        lista->dados[lista->i] = elem;
        return;
    }
    if(EhCheia(*lista)){
        printf("Lista Cheia!\n");
        return;
    }
    if(TAM-1 == lista->f){  //Se o final for o TAM-1, final volta para 0
        lista->f = 0;
        lista->dados[lista->f] = elem;
        return;
    }
    else{
        lista->f += 1;  //Caso nao seja, adiciona no fim normalmente
        lista->dados[lista->f] = elem;
    }
    
}

void InsereInicio(Lista *lista, int elem){
    if(EhVazia(*lista)){
        lista->i += 1;
        lista->f += 1;
        lista->dados[lista->i] = elem;
        return;
    }
    if(EhCheia(*lista)){
        printf("Lista Cheia!\n");
        return;
    }
    if(lista->i == 0){
        lista->i = TAM-1;                   //Caso eu queira inserir no inicio e o inicio é o elemento[0]
        lista->dados[lista->i] = elem;      //Agora o inicio é o elemento[TAM-1] (ultimo indice)
        return;
        
    }
    lista->i -= 1;                          //Caso não seja, adiciona no anterior normalmente e faz com que ele
    lista->dados[lista->i] = elem;          //Seja o novo inicio
    
    
}

void RemoveInicio(Lista *lista){
    if(EhVazia(*lista)){
        lista->i = -1;
        lista->f = -1;
        printf("LISTA VAZIA\n");
        
        return;
    }
    if(lista->i == lista->f){
        lista->i = lista->f = -1;
        return;
    }
    if(lista->i == TAM-1){
        lista->i = 0;
        return;
    }
    else{
        (lista->i)++;
    }
}

void RemoveFim(Lista *lista){
    if(EhVazia(*lista)){
        lista->i = -1;
        lista->f = -1;
        printf("LISTA VAZIA\n");
        return;
    }
    if(lista->i == lista->f){
        lista->i = lista->f = -1;
        return;
    }
    
    if(lista->f == 0){
        lista->f = TAM-1;
        return;
    }
    else{
        (lista->f)--;
    }
}

void MostrarOrdem(Lista lista){
    if(EhVazia(lista)){
        printf("Lista Vazia!\n");
        return;
    }
    int percorre = lista.i;
    int contador = 0;
    
    while(percorre != lista.f){
        if(percorre == TAM-1){
            printf("Elemento[%d] = %d\n", contador++, lista.dados[percorre]);
            percorre = 0;
        }
        else{
            printf("Elemento[%d] = %d\n", contador++, lista.dados[percorre]);
            percorre++;
        }
    }
    printf("Elemento[%d] = %d\n", contador++, lista.dados[percorre]);
}

void MostrarInverso(Lista lista){
    if(EhVazia(lista)){
        printf("Lista Vazia!\n");
        return;
    }
    int percorre = lista.f;
    while(percorre != lista.i){
        if(percorre == 0){
            printf("Elemento = %d\n", lista.dados[percorre]);
            percorre = TAM-1;
        }
        else{
            printf("Elemento = %d\n", lista.dados[percorre]);
            percorre--;
        }
    }
    printf("Elemento = %d\n", lista.dados[percorre]);
}