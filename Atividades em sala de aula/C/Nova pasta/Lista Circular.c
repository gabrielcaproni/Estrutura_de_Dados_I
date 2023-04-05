#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char processo[40];
	int tempo;
}tdado;

typedef struct no{
	tdado dado;
	struct no *prox;
}tno;

typedef struct{
	tno *ini,*fim;
	int tamanho;
}tfila;
//--------------------------
void inicializa(tfila *f){
	f->ini = NULL;
	f->fim = NULL;
	f->tamanho=0;
}
//--------------------------
int enqueue(tfila *f, tdado x){
	
	tno *novo = malloc(sizeof(tno)); 	
	novo->dado = x;
	novo->prox = NULL;
	if(f->ini==NULL){//Vazia
		f->ini = novo;
		}else{
			f->fim->prox = novo;//Encadeando o novo
		}
		
		f->fim = novo;
		f->tamanho++;
		return 1;
	
 	
}
//---------------------------
tdado dequeue(tfila *f){
	tdado removido = f->ini->dado; // Guardando o dado
	tno *aux = f->ini; // Guardando para liberar memoria
	f->ini = f->ini->prox; // Deslocando o ponteiro
	if(f->ini == NULL) // Era o último 
		f->fim = NULL;
	free(aux); // Liberando área de memória
	f->tamanho--;
	return removido;
	
}
//------------------------------
int isEmpty(tfila f){
	if(f.ini == NULL){
		return 1;
		printf("A fila esta vazia! ");
		}else{
			return 0;
		}
		
}
//--------------------------
void mostra(tfila f){
	while(f.ini!=NULL){
		printf("%s : %d | ->", f.ini->dado.processo, f.ini->dado.tempo);
	
	f.ini = f.ini->prox;// Deslocando
	}// Fim while
	printf("\n");
}
//----------------------------

tdado first(tfila f){
	return f.ini->dado;
}
//----------------------------

tdado last(tfila f){
	return f.fim->dado;
}
//----------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Fila Encadeada ****\n");
	printf("1-Enqueue (Inserir)\n");
	printf("2-Dequeue (Remover)\n");
	printf("3-Inicio e Fim\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------
int main(){
	tfila f1;
	tdado x;
	int op;
	inicializa(&f1);
	do{
		mostra(f1);
		op = menu();
		switch(op){
			case 1: printf("Entre com o processo e tempo:");
					fflush(stdin);
					gets(x.processo);
					scanf("%d",&x.tempo);
					enqueue(&f1,x);
			break;
			case 2: if(!isEmpty(f1)) {
				      x = dequeue(&f1);
				      printf("%s: %d\n", x.processo, x.tempo);
				     }
				     else
				       printf("Process Queue empty :(\n");
				break;
			case 3:if(!isEmpty(f1)){
					printf("Primeiro: %s", first(f1).processo, "Ultimo: %s", last(f1).processo);
			}	
				 break;	
			case 0: printf("Saindo .... ;)\n");	    
		}// fim switch
	    getch(); // system("pause");
	    system("cls");
	}while(op!=0);

	return 0;
}
