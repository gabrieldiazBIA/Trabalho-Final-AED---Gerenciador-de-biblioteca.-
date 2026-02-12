#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "lista_livros.h"
#include "pilha_historico.h"

typedef struct {
    No* livros;
    NoHistorico* historico;
} Biblioteca;

void bibliotecaInit(Biblioteca* b);
void bibliotecaFree(Biblioteca* b);

// operações
int bibliotecaCadastrar(Biblioteca* b, Livro livro);
int bibliotecaRemover(Biblioteca* b, int isbn);
int bibliotecaEmprestar(Biblioteca* b, int isbn);
int bibliotecaDevolver(Biblioteca* b, int isbn);

No* bibliotecaBuscar(Biblioteca* b, int isbn);
void bibliotecaListar(const Biblioteca* b);

void bibliotecaOrdenarTitulo(Biblioteca* b);
void bibliotecaOrdenarAno(Biblioteca* b);

void bibliotecaMostrarHistorico(const Biblioteca* b);

#endif
