#include <stdio.h>
void f1(int n){
    if (n == 0)
        printf(" fim");
    else
    {
        f1(n-1);
        printf(" %d ",n);
        Sleep(300);
    }
}// fim f

void f2(int n){
    if (n == 0)
        printf(" fim ");
    else
    {
        printf(" %d ",n);
        Sleep(300);
        f2(n-1);
}
}// fim f

int main(){
	int valor;
	printf("Valor:");
	scanf("%d",&valor);
	printf("F1:");
	f1(valor);
	printf("\n");
	printf("F2:");
	f2(valor);
	return 0;
}

