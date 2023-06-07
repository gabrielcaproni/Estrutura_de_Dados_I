#include<stdio.h>

int pot(int base, int exp){
	int r;
	printf("pot(%d, %d) \n",base, exp); getch();
	if(exp == 0){
		printf("%d^%d = 1 \n", base, exp); getch();
		return 1;
	}
	r = base * pot(base, exp - 1);
	printf("%d^%d = %d \n", base,exp,r);getch();
	return r;	
}	
	int main(){
	int base, exp;
	printf("Base e Expoente: ");
	scanf("%d%d",&base, &exp);
	printf("Potência: %d^%d = %d",base, exp, pot(base, exp));
	return 0;
} 

