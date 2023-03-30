#include <stdio.h>
typedef struct{
	int x; // coordenadas lab
	int y;
} tdado;
typedef struct no{
	tdado dado;
	struct no *prox;
}tno;
typedef struct pilha{
	tno *topo;
}tPilha;
//---------------------------------
void inicializa(tPilha *p){
	p->topo = NULL;
}
//---------------------------------
int push(tPilha *p, tdado novoDado){
	tno *novo;
	novo = malloc(sizeof(tno));
	if(novo==NULL)
	   return 0;
	novo->dado = novoDado;// atribui o valor
	novo->prox = p->topo; // proximo é quem era o topo
	p->topo = novo;  
	return 1; 
}
//-----------------------------------
tdado pop(tPilha *p){
	tdado removido = p->topo->dado;
	tno *aux = p->topo; // guardar endereço para liberar memoria
	p->topo = p->topo->prox; // movendo topo para no de baixo
	free(aux); // libera area de memoria
	return removido;
}   
//-------------------------
int isEmpty(tPilha p){
	if(p.topo==NULL)
			return 1;
	else
			return 0;		
	//return p.topo==NULL?1:0;
}
//-------------------------
