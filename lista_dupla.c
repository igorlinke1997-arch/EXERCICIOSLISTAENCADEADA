#include <stdio.h>
#include <stdlib.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

void imprimirIdaEVolta(struct NoDuplo *head) {
    struct NoDuplo *atual = head;

    printf("Ida: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);

        if (atual->proximo == NULL) {
            break;
        }

        atual = atual->proximo;
    }

    printf("\nVolta: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->anterior;
    }

    printf("\n");
}

int main() {
    struct NoDuplo *n1 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n2 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n3 = malloc(sizeof(struct NoDuplo));
    struct NoDuplo *n4 = malloc(sizeof(struct NoDuplo));

    n1->dado = 10;
    n2->dado = 20;
    n3->dado = 30;
    n4->dado = 40;

    n1->anterior = NULL;
    n1->proximo = n2;

    n2->anterior = n1;
    n2->proximo = n3;

    n3->anterior = n2;
    n3->proximo = n4;

    n4->anterior = n3;
    n4->proximo = NULL;

    imprimirIdaEVolta(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}