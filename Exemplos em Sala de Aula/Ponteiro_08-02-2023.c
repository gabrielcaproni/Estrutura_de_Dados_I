#include <stdio.h>
int main(){
	int a, b=20;
	int *ponteiro_a;
	printf("Entre com um valor para A:");
	scanf("%d",&a);
	ponteiro_a = &a; // apontamento
	printf("Conteudo do apontamento =  %d\n",*ponteiro_a);
	printf("Conteudo de A =  %d\n",a);
	printf("---------------------------------\n");
	printf("Endereco de A =  %x\n",&a);
	printf("Conteudo do ponteiro pt_a =  %x\n",ponteiro_a);
	printf("---------------------------------\n");
	printf("Endereco do ponteiro pt_a =  %x\n",&ponteiro_a);
    *ponteiro_a = 15;
    printf("Conteudo do apontamento =  %d\n",*ponteiro_a);
	printf("Conteudo de A =  %d\n",a);
	printf("---------------------------------\n");
    
	return 0;
}
