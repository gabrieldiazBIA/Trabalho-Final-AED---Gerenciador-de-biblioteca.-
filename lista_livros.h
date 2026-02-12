#ifndef LISTA_LIVROS_H
#define LISTA_LIVROS_H

#include "livro.h"

typedef struct No {
    Livro livro;
    struct No* prox;
} No;

// CRUD base
int inserirLivro(No** lista, Livro livro);                 // 1 ok, 0 erro, -1 ISBN duplicado
int removerLivro(No** lista, int isbn, Livro* removido);   // 1 removeu, 0 nao achou
No* buscarLivro(No* lista, int isbn);

void listarLivros(const No* lista);
void liberarLista(No* lista);

// Ordenacao
void ordenarPorTitulo(No** lista);
void ordenarPorAno(No** lista);

#endif
