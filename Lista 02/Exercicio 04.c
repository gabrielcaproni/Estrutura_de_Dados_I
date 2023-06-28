#include <stdio.h>

int somaRecursiva(int arr[], int size){
	
	if(size == 0)
		return 0;
	
	size--;
	return arr[size] + somaRecursiva(arr, size);
}

int main(){
	int array[20], i, resultado;

	for(i = 0; i < 20; i++)
		array[i] = i;
	

	resultado = somaRecursiva(array, 20);
	printf("Soma: %d", resultado);
}

