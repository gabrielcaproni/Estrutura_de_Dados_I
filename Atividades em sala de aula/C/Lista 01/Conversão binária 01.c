#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int topo;
    int elem[MAX];
} tpilha;

void inicializa_pilha(tpilha *p) {
    p->topo = -1;
}

int pilha_vazia(tpilha *p) {
    return (p->topo == -1);
}

int pilha_cheia(tpilha *p) {
    return (p->topo == MAX - 1);
}

int push(tpilha *p, int x) {
    if (pilha_cheia(p)) {
        return 0; // pilha cheia
    }
    p->topo++;
    p->elem[p->topo] = x;
    return 1; // inserção realizada com sucesso
}

int pop(tpilha *p) {
    if (pilha_vazia(p)) {
        return -1; // pilha vazia
    }
    int x = p->elem[p->topo];
    p->topo--;
    return x;
}

void converte_base(int n, int base) {
    tpilha p;
    inicializa_pilha(&p);
    printf("O numero %d na base %d: ", n, base);
    while (n > 0) {
        push(&p, n % base);
        n /= base;
    }
    while (!pilha_vazia(&p)) {
        int x = pop(&p);
        if (x < 10) {
            printf("%d", x);
        } else {
            printf("%c", x - 10 + 'A');
        }
    }
    printf("\n");
}

int main() {
    int n, base;
    printf("Digite um numero decimal: ");
    scanf("%d", &n);
    printf("Digite uma base de 2 a 8: ");
    scanf("%d", &base);
    converte_base(n, base);
    return 0;
}
