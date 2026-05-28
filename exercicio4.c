#include <stdio.h>
#include <stdlib.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

// Função para inserir antes de um alvo
void inserirAntes(struct NoDuplo **head, int id_alvo, int novo_id) {

    struct NoDuplo *atual = *head;

    // Procurar o alvo
    while (atual != NULL && atual->dado != id_alvo) {
        atual = atual->proximo;
    }

    // Se não encontrou
    if (atual == NULL) {
        printf("ID alvo nao encontrado.\n");
        return;
    }

    // Criar novo nó
    struct NoDuplo *novo = malloc(sizeof(struct NoDuplo));

    novo->dado = novo_id;

    // Ligação do novo nó
    novo->proximo = atual;
    novo->anterior = atual->anterior;

    // Ajustar nó anterior do alvo
    if (atual->anterior != NULL) {
        atual->anterior->proximo = novo;
    } else {
        // Atualiza head se inserir no início
        *head = novo;
    }

    // Ajustar alvo
    atual->anterior = novo;
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
    n1->dado = 100;
    n2->dado = 500;
    n3->dado = 900;

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

    // Inserindo antes do 500
    inserirAntes(&head, 500, 300);

    printf("Lista depois:\n");
    imprimirLista(head);

    return 0;
}