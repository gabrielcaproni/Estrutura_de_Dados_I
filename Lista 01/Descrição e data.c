#include <stdio.h>
#include "BibliotecaDescricaoData.h"

int menu(){
	int op;
	printf("*** Menu de Opcoes *** \n");
	printf("1 - Inserir evento \n");
	printf("2 - Desfazer evento \n");
	printf("0 - Sair\n");
	printf("Qual a Opcao desejada: \n");
	scanf("%d", &op);
	return op;
	
}

void main(){
	tPilha p1;
	inicializa(&p1);
	tdado dado;
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: 
				printf("Entre com a data: \n");
				fflush(stdin);
				gets(dado.data);
				printf("Entre com a descricao: \n");
				fflush(stdin);
				gets(dado.descricao);
				if(push(&p1, dado) == 1){
					printf("Os dados foram inseridos com sucesso. \n");
					getch();
					system("cls");
				}else{
					printf("Pilha cheia!; os dados nao foram inseridos. \n");
					getch();
					system("cls");
				}
				break;
			
			case 2: 
				if(!isEmpty(p1)){
					dado = pop(&p1);
					printf("Evento removido: \n");
					printf("%s", dado.data);
					printf("%s", dado.descricao);
					getch();
					system("cls");
				}else{
					printf("Nao foi possivel remover pois a pilha esta vazia. \n");
				}
				break;
			
			case 3: 
				printf("Saindo... \n");
				getch();
				break;
			
			default:
				printf("Opcao invalida ! \n");
				break;
		}
	}while(op != 0);
}
