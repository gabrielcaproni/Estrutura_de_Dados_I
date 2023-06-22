#include <stdio.h>
long int cont = 0;
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
	ini = clock();
	res= fibo(n);
	fim = clock();
	trec = (fim-ini) / 1000; 
	printf("Termo %d da sequencia de Fibonacci=%d \n", n, res);
	printf("Tempo:%.3lf\n", trec);
	printf("Chamadas: %ld \n", cont);
	return 0;
}
