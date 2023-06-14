#include <stdio.h>

int qtd = 0;

int fibonacci(int x){
	int n;
	
	if(x == 0){
		qtd++;
		return 0;
	}
	if(x == 1){
		qtd++;
		return 1;
	}
	n = fibonacci(x - 1) + fibonacci(x - 2);
	qtd++;
	return n;
	
}

int main(){
	int n, res, i;
	for(i = 0; i < n; i++){
	scanf("%d", &n);
	res = fibonacci(n);
	printf("fibo(%d) = %d ", n, qtd - 1);
	printf("calls = %d\n", res);
	}
	return 0;
}
