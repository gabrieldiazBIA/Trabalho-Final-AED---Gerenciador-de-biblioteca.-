#ifndef LISTA_LIVROS_H
#define LISTA_LIVROS_H

#include "livro.h"

typedef struct No {
    Livro livro;
    struct No* prox;
} No; 

//Operações da lista
No* inserirLivro(No* lista, Livro livro);
No* removerLivro(No* lista, int isbn);
No* buscarLivro(No* lista, int isbn);
void listarLivros(No* lista);
void liberarLista(No* lista);

#endif