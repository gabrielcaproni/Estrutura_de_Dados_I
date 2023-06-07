#include<stdio.h>
int fat(int n){
	int r;
	printf("fat(%d)\n", n); getch(); 
	if(n == 0){
		printf("1");
		return 1;
	}
	r = n * fat(n-1);
	printf("fat(%d) = %d \n * ", n, r);getch();
	return r;
}		
int main(){
	int valor;
	printf("Valor :");
	scanf("%d",&valor);
	printf("Fatorial:%.2d",fat(valor));
	return 0;
	}

