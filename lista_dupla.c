#include <stdio.h>
#include <stdlib.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

// Função para buscar CPF e mostrar vizinhos
void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo) {

    struct NoDuplo *atual = head;

    while (atual != NULL) {

        // Encontrou o CPF
        if (atual->dado == cpf_alvo) {

            printf("O cidadão %d está na fila.\n", atual->dado);

            // Pessoa na frente
            if (atual->anterior != NULL) {
                printf("Na frente dele está o %d\n",
                       atual->anterior->dado);
            } else {
                printf("Ele está no início da fila.\n");
            }

            // Pessoa atrás
            if (atual->proximo != NULL) {
                printf("Atrás dele está o %d\n",
                       atual->proximo->dado);
            } else {
                printf("Ele está no final da fila.\n");
            }

            return;
        }

        atual = atual->proximo;
    }

    printf("CPF não encontrado na fila.\n");
}

int main() {

    // Criando nós
    struct NoDuplo *n1 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n2 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n3 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n4 = malloc(sizeof(struct NoDuplo));

    // Valores (CPF fictício)
    n1->dado = 111;
    n2->dado = 222;
    n3->dado = 333;
    n4->dado = 444;

    // Ligando nós
    n1->anterior = NULL;
    n1->proximo = n2;

    n2->anterior = n1;
    n2->proximo = n3;

    n3->anterior = n2;
    n3->proximo = n4;

    n4->anterior = n3;
    n4->proximo = NULL;

    // Busca
    buscarComVizinhos(n1, 333);

    // Liberando memória
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}