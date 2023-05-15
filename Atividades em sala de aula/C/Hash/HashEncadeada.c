#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
//-----------------------
int funcaoHash(int k){
	// key ou chave vai ser o primeiro caractere do nome
	return k%65; // 65? é o código ASCII do A
}
//-----------------------
int insereHash(tlista tabHash[],tdado x){
    int map = funcaoHash(x.nome[0]);
	insereOrdenado(&tabHash[map],x);	
	return map;	
}
//-------------------------
void printHash(tlista vet[], int n){
	int i;
	for(i=0;i<n;i++){
	   if(vet[i].head!=NULL){ // nao esta vazia	
		printf("[%d]->",i);
		printList(vet[i]);
		printf("\n");
	 }// fim if
	}// fim for
}
//-------------------------
float buscaHash(tlista tabHash[],tdado x){
	// int map = funcaoHash(x.nome[0]);
	// map possui a posicao da lista de nomes 
	// agora implemente e use a funcao buscaList para percorrer a lista dos nom
}
//--------------------------

int menu(){
	int op;
	printf("*** IFSULDEMINAS - Campus Machado ***\n");
	printf("*** Linked Hash *** \n");
	printf("1-Inserir\n");
	printf("2-Buscar\n");
	printf("3-Remover\n");
	printf("4-Carregar\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//-----------------------------------------
int main() 
{ 
   int op, r;
   tdado x;
   tlista tabHash[26]; // cada posicao tem uma lista que ira guardar uma inicial de nome
   inicializa(tabHash,26);
   do{
   	printHash(tabHash,26);
   	op = menu();
   	switch(op){
   		case 1: printf("Dados: Nome:");
   				fflush(stdin); gets(x.nome);
   				x.nome[0] = toupper(x.nome[0]);
   				printf("Idade:");
   				scanf("%d",&x.idade);
   				printf("Media:");
   				scanf("%f",&x.media);
   				r=insereHash(tabHash, x);
   				printf("Inserido na posicao :%d\n",r);
   			break;
   		case 0:
		break;   	
	}// fim switch
   	getch();
   	system("cls");
   }while(op!=0);
}
