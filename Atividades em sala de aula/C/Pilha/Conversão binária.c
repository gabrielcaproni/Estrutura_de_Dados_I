#include <stdio.h>
#include "bibliotecaPilha.h"

void converteDecimal(int dec, int base){
	tPilha p;
	inicializa(&p);
	
	while (dec > 0){
		
		push(&p, dec%base);
		dec = dec / base;
	} //fim while
	
	mostrarPilha(p);
}

int main(){
	int decimal, base;
	printf("valor para conversão de base: ");
	scanf("%d",&decimal);
	printf("Base 2-8");
	scanf("%d", &base);
	converteDecimal(decimal, base);
	return 0;
}
