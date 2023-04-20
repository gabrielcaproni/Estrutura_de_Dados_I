// Verificar se o elemento existe na fila circular

int existe_elemento(tfila *f, tdado x) {
    int i = f->ini;
    int n = f->qtd;
    while (n > 0) {
        if (f->elem[i] == x) {
            return 1;
        }
        i = (i + 1) % MAX;
        n--;
    }
    return 0;
}

// Retorna o local onde o mesmo se encontra na fila linear de uma implementa��o din�mica

int posicao_valor(tfila *f, tdado x) {
    int pos = 1;
    tno *aux = f->ini;
    while (aux != NULL) {
        if (aux->dado == x) {
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1; // valor n�o encontrado na fila
}

// Apresentar o ultimo elemento da fila

int posicao_valor(tfila *f, tdado x) {
    int pos = 1;
    tno *aux = f->ini;
    while (aux != NULL) {
        if (aux->dado == x) {
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1; // valor n�o encontrado na fila
}

// Quantidade de elementos existentes na fila

int tamanho_fila(tfila *f) {
    int tamanho = 0;
    tno *aux = f->ini;
    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

// N�meros inteiros e se est� em ordem crescente

int verificaOrdemCrescente(Fila *fila) {
    int valorAnterior = INT_MIN; // menor valor poss�vel para um inteiro
    No *noAtual = fila->inicio;
    while (noAtual != NULL) {
        if (noAtual->dado < valorAnterior) {
            return 0; // a fila n�o est� em ordem crescente
        }
        valorAnterior = noAtual->dado;
        noAtual = noAtual->prox;
    }
    return 1; // a fila est� em ordem crescente
}

// Topo da pilha da estrutura encadeada

void mostrarTopo(Pilha *pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        printf("Pilha vazia\n");
    } else {
        printf("Topo da pilha: %d\n", pilha->topo->dado);
    }
}

// Retorne 1 caso a pilha estatica esteja cheia

int isFull(Pilha *pilha) {
    if (pilha->topo == MAX - 1) {
        return 1; // pilha est� cheia
    } else {
        return 0; // pilha n�o est� cheia
    }
}
