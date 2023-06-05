#include<stdio.h>
int fat(int n){
	int r;
	//caso base 
	if(n == 0){
		return 1;
	}
	r = n* fat(n-1);
	return r;
}		
int main(){
	int valor;
	printf("Valor :");
	scanf("%d",&valor);
	printf("Fatorial:%.2d",fat(valor));
	return 0;
	}

