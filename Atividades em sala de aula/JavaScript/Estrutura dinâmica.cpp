#include<stdio.h>

typedef int tdado;

typedef struct no{
	tdado dado;
	struct no *prox;
}tno;

typedef struct pilha {
	tno *topo;
}tPilha;
