#include <stdio.h>
void troca(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("*** Funcao ***\n");
	printf("A=%d B=%d\n",a,b);
}

//__________________________________________

void trocaRef(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("*** Na Funcao ***\n");
	printf("A=%d B=%d\n", *a, *b);
}

//__________________________________________

int main(){
	int a,b;
	printf("Entre com dois valores:");
	scanf("%d%d",&a,&b);
	trocaRef(&a, &b);
	printf("*** Main ***\nA=%d B=%d",a,b);
	return 0;
}
