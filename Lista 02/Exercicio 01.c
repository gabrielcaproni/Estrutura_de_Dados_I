#include <stdio.h>

int pesquisa(No* lista, int valor) {
    No* atual = lista;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}
