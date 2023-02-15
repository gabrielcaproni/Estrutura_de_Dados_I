#include <stdio.h>
#include "bibliotecaPilha.h"

int menu(){
	int op;
	printf("*** Estrutura de Dados I - Pilha Estatica ****\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");
	printf("3-Peek (Olhar Topo)\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}

//______________________________

int main(){
	
	tPilha p1;
	inicializa(&p1);
	tdado dado;
	int op;
	do{
		mostrarPilha(p1);
		op = menu();
		switch(op){
			
			case 1: 
				printf("Dado para a pilha: ");
				scanf("%d", &dado);
				if(push(&p1, dado) == 1){
					printf("Inserido com sucesso\n");
					mostrarPilha(p1);
					}else {
					 	printf("Pilha cheia - stack OverFlow\n");
						mostrarPilha(p1);
				}
				break;
			
			case 2: 
				if(!isEmpty(p1)){
					dado = pop(&p1);
					printf("Dado removido: %d\n", dado);
				}else{
					printf("Pilha vazia\n");
				}
				break;
			case 3: 
				if(!isEmpty(p1)){
					printf("Topo da pilha: %d\n", peek(p1));
				}else{
					printf("A pilha esta vazia\n");
				}
				break;
			case 0: 
				printf("Saindo...\n");
				break;
			default: 
				printf("Opcao ivalida !!!");
				break;
		}
		getch();
		system("cls");
	}while(op != 0);
	
	return 0;
	
}






