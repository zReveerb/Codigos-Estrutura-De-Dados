//Feito por Heitor Gabriel
// 13 de Agosto de 2025
//Implementação de listas circulares duplamente encadeadas com ponteiro de ponteiro

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
    struct lista *ant;
}Lista;

void CriaLst(Lista **l);
int EhVazia(Lista *l);
void InsereFim(Lista **l, int dado);
void InsereInicio(Lista **l, int dado);
void MostrarOrdem(Lista *l);
void MostrarInverso(Lista *l);
void RemoveInicio(Lista **l);
void RemoveFinal(Lista **l);


int main()
{
    int parar = 0, elemento, escolha;
    Lista *l;
    CriaLst(&l);
    while(!parar){
        printf("Digite\n1- Inserir\n2- Remover\n3- Mostrar\n4- Sair\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("\nDigite\n1- Inserir Inicio\n2- Inserir Final\n");
                scanf("%d", &escolha);
                printf("Digite o elmento para adicionar: ");
                scanf("%d", &elemento);
                switch(escolha){
                    case 1:
                        InsereInicio(&l, elemento);
                        break;
                    case 2:
                        InsereFim(&l, elemento);
                        break;
            
                }
                break;
            case 2:
                printf("\nDigite\n1- Remover Inicio\n2- Remover Final\n");
                scanf("%d", &escolha);
                if(escolha == 1){
                    RemoveInicio(&l);
                }
                else{
                    RemoveFinal(&l);    
                }
                break;
            case 3:
                printf("\nDigite\n1- Mostrar do Inicio\n2- Mostrar do Final\n");
                scanf("%d", &escolha);
                if(escolha == 1){
                    MostrarOrdem(l);
                }
                else{
                    MostrarInverso(l);
                }
                break;
            case 4:
                parar++;
                break;
        }
    }

    return 0;
}

void CriaLst(Lista **l){
    *l = NULL;
}

int EhVazia(Lista *l){
    if(!l){
        return 1;
    }
    return 0;
}

void InsereFim(Lista **l, int dado){
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    if(!aux){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    aux->info = dado;
    
    
    if(EhVazia(*l)){
        aux->ant = aux;
        aux->prox = aux;
        *l = aux;
        return;
    }
    
    Lista *temp;
    temp = *l;
    aux->prox = temp;
    aux->ant = temp->ant;
    temp->ant->prox = aux;
    temp->ant = aux;
}

void InsereInicio(Lista **l, int dado){
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    if(!aux){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    aux->info = dado;
    if(EhVazia(*l)){
        aux->ant = aux;
        aux->prox = aux;
        *l = aux;
        return;
    }
    Lista *temp;
    temp = *l;
    aux->prox = temp;
    aux->ant = temp->ant;
    temp->ant->prox = aux;
    temp->ant = aux;
    *l = aux;
    
}


void MostrarOrdem(Lista *l){
    if(EhVazia(l)){
        printf("LISTA VAZIA!\n");
    }
    Lista *temp;
    int contador = 0;
    for(temp = l; temp != l || contador == 0; temp = temp->prox){
        printf("Elemento[%d] = %d\n", contador++, temp->info);
    }
}
void MostrarInverso(Lista *l){
    if(EhVazia(l)){
        printf("LISTA VAZIA!\n");
        return;
    }
    Lista *temp;
    int contador = 0;
    
    for(temp = l; temp != l || contador == 0; temp = temp->ant){
        printf("Elemento = %d\n", temp->ant->info);
        contador++;
    }
}

void RemoveFinal(Lista **l){
    Lista *aux;
    if(EhVazia(*l)){
        printf("LISTA JA VAZIA\n");
        return;
    }
    if((*l)->prox == *l){
        aux = *l;
        *l = NULL;
        free(aux);
        return;
    }
    Lista *temp = (*l)->ant;
    temp->ant->prox = temp->prox;
    temp->prox->ant = temp->ant;
    free(temp);
}

void RemoveInicio(Lista **l){
    if(EhVazia(*l)){
        printf("Lista ja vazia\n");
        return;
    }
    Lista *aux;
    if((*l)->prox == *l){
        aux = *l;
        *l = NULL;
        free(aux);
        return;
    }
    Lista *temp = *l;
    (*l)->prox->ant = (*l)->ant;
    (*l)->ant->prox = (*l)->prox;
    *l = (*l)->prox;
    free(temp);
    
}