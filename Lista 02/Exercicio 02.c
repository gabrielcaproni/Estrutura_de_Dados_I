#include <stdio.h>

int verificarOrdemCrescente(No* inicio) {
    if (inicio == NULL || inicio->prox == NULL) {
        return 1;
    }

    No* atual = inicio;
    while (atual->prox != NULL) {
        if (atual->dado > atual->prox->dado) {
            return 0;  
        }
        atual = atual->prox;
    }

    return 1;  
}
