#include<stdio.h>
#define MAX 10 

typedef int tdado;

typedef struct{
	
	tdado pilha[MAX];	
	int topo;
	
}tPilha;

//______________________________

void inicializa (tPilha *p){
		p->topo = -1;
		
}

int push(tPilha *p, tdado dado){
	if(p->topo == MAX-1)// cheio
	return 0;
	p->topo++;
	p->pilha[p->topo] = dado;
	return 1;
}
 
int main(){
	
	tPilha p1;
	printf("Topo:%d\n", p1.topo);
	inicializa(&p1);
	printf("Topo depois de inicializar:%d\n", p1.topo);
	return 0;
	
}
