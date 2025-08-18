/*Codigo de Listas Heterogeneas para a disciplina Estrutura de Dados*/
//Criado por Heitor Gabriel 18/08/25

#include <stdlib.h>
#include <stdio.h>
#define RET 1
#define CIC 2
#define TRI 3

typedef struct ponto{
    int x;
    int y;
}Ponto;
typedef struct lista {
	struct lista *prox;
	int ID;
	void *info;
} Lista;

typedef struct ret {
	int base;
	int altura;
} Ret;

typedef struct cic {
	Ponto centro;
	float raio;
} Cic;

typedef struct tri {
	Ponto p1;
	Ponto p2;
	Ponto p3;
} Tri;

int EhVazia(Lista *l);

void AdicionaTrianguloFinal(Lista **l, Ponto p1w, Ponto p2w, Ponto p3w);
void AdicionaTrianguloInicio(Lista **l, Ponto p1w, Ponto p2w, Ponto p3w);

void AdicionaCirculoFinal(Lista **l, Ponto center, float raiow);
void AdicionaCirculoInicio(Lista **l, Ponto center, float raiow);


void AdicionaRetanguloInicio(Lista **l, int basew, int alturaw);
void AdicionaRetanguloFinal(Lista **l, int basew, int alturaw);

void RemoveInicio(Lista **l);
void RemoveFinal(Lista **l);
void LiberaTudo(Lista **l);
void MostrarTudo(Lista *l);
int main()
{
	Lista *l;
	l = NULL;
	int escolha = 0, escolha2,escolha3;
	int base,altura, x,y;
	Ponto ponto, ponto1, ponto2;
	float raio;
	while(escolha != 4) {
		printf("Digite\n1-Inserir\n2-Remover\n3-MOSTRAR\n4-SAIR\n");
		scanf("%d", &escolha);
		if(escolha == 1) {
			printf("Digite\n1-INICIO\n2-FINAL\n");
			scanf("%d", &escolha3);
			if(escolha3 == 1) {
				printf("Digite\n1- Para RETANGULO\n2- Para CIRCULO\n 3- Para TRIANGULO\n");
				scanf("%d", &escolha2);
				switch(escolha2) {
				case 1:
					printf("Digite a base:");
					scanf("%d", &base);
					printf("Digite a altura:");
					scanf("%d", &altura);
					AdicionaRetanguloInicio(&l, base, altura);
					break;
				case 2:
					printf("Digite o ponto x y : ");
					scanf("%d %d", &x, &y);
					printf("Digite o raio: ");
					scanf("%f", &raio);
					ponto.x = x;
					ponto.y = y;
					AdicionaCirculoInicio(&l, ponto,raio);
					break;
				case 3:
					printf("Digite o ponto1 x y : ");
					scanf("%d %d", &x, &y);
					ponto.x = x;
					ponto.y = y;
					printf("Digite o ponto2 x y : ");
					scanf("%d %d", &x, &y);
					ponto1.x = x;
					ponto1.y = y;
					printf("Digite o ponto3 x y : ");
					scanf("%d %d", &x, &y);
					ponto2.x = x;
					ponto2.y = y;
					
					AdicionaTrianguloInicio(&l, ponto,ponto1,ponto2);
					break;
				}
			}
				if(escolha3 == 2) {
					printf("Digite\n1- Para RETANGULO\n2- Para CIRCULO\n 3- Para TRIANGULO\n");
    				scanf("%d", &escolha2);
    				switch(escolha2) {
    				case 1:
    					printf("Digite a base:");
    					scanf("%d", &base);
    					printf("Digite a altura:");
    					scanf("%d", &altura);
    					AdicionaRetanguloFinal(&l, base, altura);
    					break;
    				case 2:
    					printf("Digite o ponto x y : ");
    					scanf("%d %d", &x, &y);
    					printf("Digite o raio: ");
    					scanf("%f", &raio);
    					ponto.x = x;
    					ponto.y = y;
    					AdicionaCirculoFinal(&l, ponto,raio);
    					break;
    				case 3:
    					printf("Digite o ponto1 x y : ");
    					scanf("%d %d", &x, &y);
    					ponto.x = x;
    					ponto.y = y;
    					printf("Digite o ponto2 x y : ");
    					scanf("%d %d", &x, &y);
    					ponto1.x = x;
    					ponto1.y = y;
    					printf("Digite o ponto3 x y : ");
    					scanf("%d %d", &x, &y);
    					ponto2.x = x;
    					ponto2.y = y;
    					
    					AdicionaTrianguloFinal(&l, ponto,ponto1,ponto2);
    					break;
    				}
				}
			}if(escolha == 2){
			    printf("Digite\n1-INICIO\n2-FINAL");
			    scanf("%d", &escolha2);
			    if(escolha2 == 1){
			        RemoveInicio(&l);
			    }else if(escolha2 == 2){
			        RemoveFinal(&l);
			    }
			}
			if(escolha == 3){
			    MostrarTudo(l);
			}
		}
	LiberaTudo(&l); 
	
    return 0;
}

void AdicionaRetanguloInicio(Lista **l, int basew, int alturaw) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("ERRO DE ALOCACAO!");
		exit(1);
	}
	Ret *retangulo;
	retangulo = (Ret*)malloc(sizeof(Ret));
	if(!retangulo) {
		puts("ERRO DE ALOCACAO!");
		exit(1);
	}
	retangulo->altura = alturaw;
	retangulo->base = basew;

	aux->ID = RET;
	aux->info = retangulo;
	if(EhVazia(*l)) {
		aux->prox = NULL;
		*l = aux;
	}
	else {
		aux->prox = *l;
		*l = aux;
	}
}

void AdicionaCirculoInicio(Lista **l, Ponto center, float raiow) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("ERRO DE ALOCACAO!");
		exit(1);
	}
	Cic *circulo;
	circulo = (Cic*)malloc(sizeof(Cic));
	if(!circulo) {
		puts("ERRO DE ALOCACAO!");
		exit(1);
	}
	circulo->centro = center;
	circulo->raio = raiow;

	aux->ID = CIC;
	aux->info = circulo;
	if(EhVazia(*l)) {
		aux->prox = NULL;
		*l = aux;
	}
	else {
		aux->prox = *l;
		*l = aux;
	}
}

void AdicionaTrianguloInicio(Lista **l, Ponto p1w, Ponto p2w, Ponto p3w) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("Erro de alocacao de memoria!");
		exit(1);
	}
	Tri *triangulo;
	triangulo = (Tri*)malloc(sizeof(Tri));
	triangulo->p1 = p1w;
	triangulo->p2 = p2w;
	triangulo->p3 = p3w;

	aux->ID = TRI;

	aux->info = triangulo;

	if(EhVazia(*l)) {
		aux->prox = NULL;
		*l = aux;
	}
	else {
		aux->prox = *l;
		*l = aux;
	}
}

void AdicionaRetanguloFinal(Lista **l, int basew, int alturaw) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("ERRO DE ALOCACAO");
		exit(1);
	}
	Ret *retangulo;
	retangulo = (Ret*)malloc(sizeof(Ret));
	if(!retangulo) {
		puts("ERRO DE ALOCACAO");
		exit(1);
	}
	retangulo->base = basew;
	retangulo->altura = alturaw;
	aux->prox = NULL;
	aux->ID = RET;
	aux->info = retangulo;

	if(EhVazia(*l)) {
		*l = aux;
	}
	else {
		Lista *percorre;
		for(percorre = *l; percorre->prox != NULL; percorre = percorre->prox);
		percorre->prox = aux;

	}

}

void AdicionaCirculoFinal(Lista **l, Ponto center, float raiow) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("ERRO DE ALOCACAO DE MEMORIA!");
		exit(1);
	}
	Cic *circulo;
	circulo = (Cic*)malloc(sizeof(Cic));
	if(!circulo) {
		puts("ERRO ERRO ERRO");
		exit(1);
	}
	circulo->centro = center;
	circulo->raio = raiow;

	aux->prox = NULL;
	aux->ID = CIC;
	aux->info = circulo;

	if(EhVazia(*l)) {
		*l = aux;
	} else {
		Lista *percorre;
		for(percorre = *l; percorre->prox != NULL; percorre = percorre->prox);
		percorre->prox = aux;
	}
}

void AdicionaTrianguloFinal(Lista **l, Ponto p1w, Ponto p2w, Ponto p3w) {
	Lista *aux;
	aux = (Lista*)malloc(sizeof(Lista));
	if(!aux) {
		puts("ERRO DE ALOCACAO DE MEMORIA!");
		exit(1);
	}
	Tri *triangulo;
	triangulo = (Tri*)malloc(sizeof(Tri));
	if(!triangulo) {
		puts("ERRO DE ALOCACAO DE MEMORIA!");
		exit(1);
	}
	triangulo->p1 = p1w;
	triangulo->p2 = p2w;
	triangulo->p3 = p3w;

	aux->prox = NULL;
	aux->ID = TRI;
	aux->info = triangulo;

	if(EhVazia(*l)) {
		*l = aux;
	} else {
		Lista *percorre;
		for(percorre = *l; percorre->prox != NULL; percorre = percorre->prox);
		percorre->prox = aux;
	}
}

void RemoveInicio(Lista **l) {
	if(EhVazia(*l)) {
		puts("Ja vazia");
		return;
	}
	Lista *aux;
	aux = *l;
	switch(aux->ID){
	    case RET:
	    case CIC:
	    case TRI:
	        free(aux->info);
	        break;
	    default:
	        puts("INVALIDO!");
	        break;
	}
	*l = (*l)->prox;
	free(aux);
}

void RemoveFinal(Lista **l) {
	if(EhVazia(*l)) {
		puts("Ja vazia");
		return;
	}
	Lista *aux;
	if((*l)->prox == NULL) {
		aux = *l;
		switch(aux->ID){
	    case RET:
	    case CIC:
	    case TRI:
	        free(aux->info);
	        break;
	    default:
	        puts("INVALIDO!");
	        break;
	    }
	    free(aux);
		*l = NULL;
		return;
	}
	Lista *percorre;

	for(percorre = *l; percorre->prox->prox != NULL; percorre = percorre->prox);
	aux = percorre->prox;
	switch(aux->ID){
	    case RET:
	    case CIC:
	    case TRI:
	        free(aux->info);
	        break;
	    default:
	        puts("INVALIDO!");
	        break;
	}
	
	percorre->prox = NULL;
	free(aux);
}

int EhVazia(Lista *l) {
	return (!l);
}

void MostrarTudo(Lista *l) {
	if(EhVazia(l)) {
		puts("VAZIA");
		return;
	}
	else {
		while(l != NULL) {
			switch(l->ID) {
			case CIC:
				Cic *c = l->info;
				printf("CENTRO DO CIRCULO = (%d,%d)\n", c->centro.x, c->centro.y);
				printf("RAIO DO CIRCULO = %.2f\n", c->raio);
				break;
			case TRI:
				Tri *t = l->info;
				printf("PONTO 1 = (%d,%d)\nPONTO 2 = (%d,%d)\nPONTO 3 = (%d,%d)\n",t->p1.x, t->p1.y,t->p2.x, t->p2.y, t->p3.x, t->p3.y);
				break;
			case RET:
				Ret *r = l->info;
				printf("BASE = %d\nALTURA = %d\n", r->base, r->altura);
				break;
			}
			l = l->prox;
		}
	}
}

void LiberaTudo(Lista **l){
    if(EhVazia(*l)){
        return;
    }else{
        while(*l != NULL){
            RemoveInicio(l);
        }
    }
}