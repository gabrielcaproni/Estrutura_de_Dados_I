#include <stdio.h>

void removerElementosPares(No** inicio) {
    if (*inicio == NULL) {
        return;
    }

    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado % 2 == 0) {
            if (anterior == NULL) {
                *inicio = atual->prox;
                free(atual);
                atual = *inicio;
            } else {    
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

