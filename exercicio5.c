#include <stdio.h>
#include <stdlib.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

// Função para remover CPF
void removerCpf(struct NoDuplo **head, int cpf_alvo) {

    struct NoDuplo *atual = *head;

    // Procurar CPF
    while (atual != NULL && atual->dado != cpf_alvo) {
        atual = atual->proximo;
    }

    // CPF não encontrado
    if (atual == NULL) {
        printf("CPF nao encontrado.\n");
        return;
    }

    // Ajustar nó anterior
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        // Remove o primeiro nó
        *head = atual->proximo;
    }

    // Ajustar nó próximo
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    printf("CPF %d removido.\n", atual->dado);

    free(atual);
}

// Função para imprimir lista
void imprimirLista(struct NoDuplo *head) {

    struct NoDuplo *atual = head;

    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");
}

int main() {

    // Criando nós
    struct NoDuplo *n1 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n2 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n3 = malloc(sizeof(struct NoDuplo));

    // Valores
    n1->dado = 111;
    n2->dado = 222;
    n3->dado = 333;

    // Ligação
    n1->anterior = NULL;
    n1->proximo = n2;

    n2->anterior = n1;
    n2->proximo = n3;

    n3->anterior = n2;
    n3->proximo = NULL;

    struct NoDuplo *head = n1;

    printf("Lista antes:\n");
    imprimirLista(head);

    // Remove CPF 222
    removerCpf(&head, 222);

    printf("Lista depois:\n");
    imprimirLista(head);

    return 0;
}