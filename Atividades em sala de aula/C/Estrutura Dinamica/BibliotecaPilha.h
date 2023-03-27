#include<stdio.h>
#include<stlib.h>

typedef struct{
	int x;
	int y;
}tdado;

typedef struct no{
	tdado dado;
	struct no *prox;
}tno;

typedef struct pilha {
	tno *topo;
}tPilha;

//---------------------------------------------

void inicializa(tPilha *p){
	p->topo = NULL;
}

//---------------------------------------------

int push(tPilha *p, tdado novoDado){
	tno *novo;
	novo = malloc(sizeof(tno));
	if(novo==NULL){
		return 0;
	}
	novo->dado = novoDado; // Atribui o valor 
	novo->prox = p->topo; // Proximo é quem era o topo
	p->topo = novo;
	return 1;
}

//---------------------------------------------

tdado pop(tPilha *p){
	tdado removido = p->topo->dado;
	tno *aux = p->topo; // Guardar endereço para liberar memória
	free(aux); // Libera area da memória
	return removido;
}

//---------------------------------------------

int isEmpty(tPilha p){
	if(p.topo==NULL){
		return 1;
	}else{
		return 0; 
		// Return p.topo==NULL?1:0;
	}
}
