#include <stdio.h>

int quantidadeChamadas = 0;

int h(int m, int n) {
    quantidadeChamadas++;
    if (n == 1) 
        return m + 1;
    if (m == 1) 
        return n + 1;
    
   return h(m, n - 1) + h(m - 1, n);
}

int main() {
    int resultado = h(3, 3);
    printf("O retorno para h(3, 3) é: %d\n", resultado);
    printf("A função foi chamada %d vezes\n", quantidadeChamadas);
    return 0;
}

