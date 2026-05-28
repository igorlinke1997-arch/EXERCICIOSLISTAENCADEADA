#include <stdio.h>
#include <stdlib.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

// Função para verificar integridade da lista
int verificarIntegridade(struct NoDuplo *head) {

    struct NoDuplo *atual = head;

    // Percorre a lista
    while (atual != NULL && atual->proximo != NULL) {

        // Verifica se o próximo nó aponta corretamente para o atual
        if (atual->proximo->anterior != atual) {
            return 0; // Lista quebrada
        }

        atual = atual->proximo;
    }

    return 1; // Lista íntegra
}

int main() {

    // Criando nós
    struct NoDuplo *n1 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n2 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n3 = malloc(sizeof(struct NoDuplo));

    // Valores
    n1->dado = 10;
    n2->dado = 20;
    n3->dado = 30;

    // Ligando nós corretamente
    n1->anterior = NULL;
    n1->proximo = n2;

    n2->anterior = n1;
    n2->proximo = n3;

    n3->anterior = n2;
    n3->proximo = NULL;

    // Teste lista correta
    if (verificarIntegridade(n1)) {
        printf("Lista integra!\n");
    } else {
        printf("Lista quebrada!\n");
    }

    // Quebrando a ligação propositalmente
    n3->anterior = NULL;

    // Teste lista quebrada
    if (verificarIntegridade(n1)) {
        printf("Lista integra!\n");
    } else {
        printf("Lista quebrada!\n");
    }

    // Liberando memória
    free(n1);
    free(n2);
    free(n3);

    return 0;
}