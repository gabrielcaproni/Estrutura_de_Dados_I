#include <stdio.h>
long int memo[100];
long int cont = 0;
void mostraVetor(int v[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%d |", v[i]);
		printf("\n");
}

long int fiboMemo(int n){
	cont++;
	//printf("fib(%d) | ", n);
	//mostraVetor(memo, n); getch();
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(memo[n] != -1) // verificando se ja calculou 
		return memo[n];// retorna direto
	memo[n] = fibo(n - 1) + fibo(n - 2);// calcula e armazena 
	return memo[n];// depois retorna 
}

int fibo(int n){
	int r;
	cont ++;
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	r= fibo(n-1)+fibo(n-2);	
	return r;
}

int main(){
	double ini,fim, trec;
	int n,i;
	long long res;
	printf("Termo:");
	scanf("%d",&n);
	//Inicializar o vetor de memorização
	for(i = 0; i <= n; i++)
		memo[i] = -1;
		
	ini = clock();
	for(i = 0; i <= 40; i++){
		printf("Termo %d da sequencia de Fibonacci= %d \n", i, fibo(i));
	}
	fim = clock();
	trec = (fim-ini) / 1000; 
	printf("Tempo:%.3lf\n", trec);
	
	ini = clock();
	for(i = 0; i <= 40; i++){
		printf("Termo %d da sequencia de Fibonacci= %d \n", i, fiboMemo(i));
	}
	fim = clock();
	trec = (fim-ini) / 1000; 
	printf("Tempo:%.3lf\n", trec);
	
	return 0;
}
