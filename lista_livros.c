#include <stdio.h>
#include <stdlib.h>
#include "lista_livros.h"

No* inserirLivro(No* lista, Livro livro) {
    No* novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return lista;
    }
    
    novo->livro = livro;
    novo->prox = lista;
    return novo;
}

No* removerLivro(No* lista, int isbn) {
    //implementação futura
    return lista;
}

No* buscarLivro(No* lista, int isbn) {
    //implementação futura
    return NULL;
}

void listarLivros(No* lista) {
    if (lista == NULL) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    No* atual = lista;

    printf("\n=== LISTA DE LIVROS ====\n");

    while (atual != NULL) {
        printf("ISBN: %d\n", atual->livro.isbn);
        printf("Titulo: %s\n", atual -> livro.titulo);
        printf("Autor: %s\n", atual->livro.autor);
        printf("Ano: %d\n", atual->livro.ano);
        printf("Disponivel: %s\n", atual->livro.disponivel ? "sim" : "Nao");
        printf("-----------------------\n");
        atual = atual->prox;
    }
}

void liberarLista(No* lista) {
    No* atual = lista;
    No* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
}