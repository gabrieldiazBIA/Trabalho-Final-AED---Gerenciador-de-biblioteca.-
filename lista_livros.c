#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_livros.h"

static int cmpTitulo(const Livro* a, const Livro* b) {
    return strcmp(a->titulo, b->titulo);
}

static int cmpAno(const Livro* a, const Livro* b) {
    if (a->ano != b->ano) return (a->ano < b->ano) ? -1 : 1;
    // desempate por titulo
    return strcmp(a->titulo, b->titulo);
}

No* buscarLivro(No* lista, int isbn) {
    while (lista) {
        if (lista->livro.isbn == isbn) return lista;
        lista = lista->prox;
    }
    return NULL;
}

int inserirLivro(No** lista, Livro livro) {
    if (!lista) return 0;

    // impedir ISBN duplicado
    if (buscarLivro(*lista, livro.isbn)) return -1;

    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return 0;

    novo->livro = livro;
    novo->prox = *lista;
    *lista = novo;
    return 1;
}

int removerLivro(No** lista, int isbn, Livro* removido) {
    if (!lista || !*lista) return 0;

    No* atual = *lista;
    No* anterior = NULL;

    while (atual && atual->livro.isbn != isbn) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) return 0;

    if (removido) *removido = atual->livro;

    if (!anterior) *lista = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
    return 1;
}

void listarLivros(const No* lista) {
    if (!lista) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\n=== LISTA DE LIVROS ===\n");
    while (lista) {
        printf("ISBN: %d\n", lista->livro.isbn);
        printf("Titulo: %s\n", lista->livro.titulo);
        printf("Autor: %s\n", lista->livro.autor);
        printf("Ano: %d\n", lista->livro.ano);
        printf("Disponivel: %s\n", lista->livro.disponivel ? "sim" : "nao");
        printf("-----------------------\n");
        lista = lista->prox;
    }
}

void liberarLista(No* lista) {
    while (lista) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// insertion sort: insere nós num novo "sorted"
static void inserirOrdenado(No** sorted, No* node, int (*cmp)(const Livro*, const Livro*)) {
    if (!*sorted || cmp(&node->livro, &(*sorted)->livro) <= 0) {
        node->prox = *sorted;
        *sorted = node;
        return;
    }

    No* cur = *sorted;
    while (cur->prox && cmp(&node->livro, &cur->prox->livro) > 0) {
        cur = cur->prox;
    }
    node->prox = cur->prox;
    cur->prox = node;
}

static void ordenar(No** lista, int (*cmp)(const Livro*, const Livro*)) {
    if (!lista || !*lista) return;

    No* sorted = NULL;
    No* cur = *lista;

    while (cur) {
        No* next = cur->prox;
        cur->prox = NULL;
        inserirOrdenado(&sorted, cur, cmp);
        cur = next;
    }

    *lista = sorted;
}

void ordenarPorTitulo(No** lista) {
    ordenar(lista, cmpTitulo);
}

void ordenarPorAno(No** lista) {
    ordenar(lista, cmpAno);
}
