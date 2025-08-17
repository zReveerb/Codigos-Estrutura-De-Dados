//Feito por Heitor Gabriel
// 13 de Agosto de 2025
//Implementação de listas duplamente encadeadas com ponteiro de ponteiro

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
void InsereOrdenado(Lista **l, int dado);
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
                printf("\nDigite\n1- Inserir Inicio\n2- Inserir Final\n3- Inserir Ordenado\n");
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
                    case 3:
                        InsereOrdenado(&l, elemento);
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
    aux->prox = NULL;
    
    if(EhVazia(*l)){
        aux->ant = NULL;
        *l = aux;
        return;
    }
    
    Lista *temp;
    for(temp = *l; temp->prox != NULL; temp = temp->prox);
    temp->prox = aux;
    aux->ant = temp;
}

void InsereInicio(Lista **l, int dado){
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    if(!aux){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    aux->info = dado;
    aux->ant = NULL;
    if(EhVazia(*l)){
        aux->prox = NULL;
        *l = aux;
        return;
    }
    aux->prox = *l;
    (*l)->ant = aux;
    *l = aux;
    
}

void InsereOrdenado(Lista **l, int dado){
    if(EhVazia(*l)){
        InsereInicio(l, dado);
        return;
    }
    if((*l)->prox == NULL){
        if(dado <= (*l)->info){
            InsereInicio(l, dado);
            return;
        }
        else{
            InsereFim(l, dado);
            return;
        }
    }
    Lista *aux, *temp;
    aux = (Lista*)malloc(sizeof(Lista));
    if(!aux){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    aux->info = dado;
    

    for(temp = *l; temp->prox != NULL; temp = temp->prox){
        if(temp->info >= aux->info){
            if(temp->ant == NULL){
                aux->prox = temp;
                temp->ant = aux;
                aux->ant = temp->ant;
                *l = aux;
                return;
            }
            else{
                aux->prox = temp;
                temp->ant->prox = aux;
                aux->ant = temp->ant;
                temp->ant = aux;
                
                return;
            }
        }
    }
    if(temp->info >= aux->info){
        aux->prox = temp;
        temp->ant->prox = aux;
        aux->ant = temp->ant;
        temp->ant = aux;
        
    }
    else{
        InsereFim(l, dado);
    }
}

void MostrarOrdem(Lista *l){
    if(EhVazia(l)){
        printf("LISTA VAZIA!\n");
    }
    Lista *temp;
    int contador = 0;
    for(temp = l; temp != NULL; temp = temp->prox){
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
    for(temp = l; temp->prox != NULL; temp = temp->prox){
        contador++;
    }
    while(temp != NULL){
        printf("Elemento [%d] = %d\n", contador--, temp->info);
        temp = temp->ant;
    }
}

void RemoveFinal(Lista **l){
    Lista *percorre;
    if(EhVazia(*l)){
        printf("LISTA JA VAZIA\n");
        return;
    }
    if((*l)->prox == NULL){
        percorre = *l;
        *l = NULL;
        free(percorre);
        return;
    }
    
    for(percorre = *l; percorre->prox != NULL; percorre = percorre->prox);
    
    percorre->ant->prox = NULL;
    percorre->ant = NULL;
    free(percorre);
}

void RemoveInicio(Lista **l){
    if(EhVazia(*l)){
        printf("Lista ja vazia\n");
        return;
    }
    Lista *aux;
    if((*l)->prox == NULL){
        aux = *l;
        *l = NULL;
        free(aux);
        return;
    }
    aux = *l;
    (*l)->prox->ant = NULL;
    *l = (*l)->prox;
    free(aux);
}