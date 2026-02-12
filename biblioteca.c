#include <time.h>
#include "biblioteca.h"

static void registrar(Biblioteca* b, int isbn, Operacao op) {
    if (!b) return;
    Historico h;
    h.isbn = isbn;
    h.op = op;
    h.quando = time(NULL);
    b->historico = push(b->historico, h);
}

void bibliotecaInit(Biblioteca* b) {
    b->livros = NULL;
    b->historico = NULL;
}

void bibliotecaFree(Biblioteca* b) {
    if (!b) return;
    liberarLista(b->livros);
    liberarHistorico(b->historico);
    b->livros = NULL;
    b->historico = NULL;
}

int bibliotecaCadastrar(Biblioteca* b, Livro livro) {
    if (!b) return 0;
    int r = inserirLivro(&b->livros, livro);
    if (r == 1) registrar(b, livro.isbn, OP_CADASTRO);
    return r; // 1 ok, 0 erro, -1 duplicado
}

int bibliotecaRemover(Biblioteca* b, int isbn) {
    if (!b) return 0;
    Livro removido;
    int ok = removerLivro(&b->livros, isbn, &removido);
    if (ok) registrar(b, isbn, OP_REMOCAO);
    return ok;
}

No* bibliotecaBuscar(Biblioteca* b, int isbn) {
    if (!b) return NULL;
    return buscarLivro(b->livros, isbn);
}

int bibliotecaEmprestar(Biblioteca* b, int isbn) {
    if (!b) return 0;
    No* n = buscarLivro(b->livros, isbn);
    if (!n) return 0;
    if (!n->livro.disponivel) return -1; // já emprestado

    n->livro.disponivel = 0;
    registrar(b, isbn, OP_EMPRESTIMO);
    return 1;
}

int bibliotecaDevolver(Biblioteca* b, int isbn) {
    if (!b) return 0;
    No* n = buscarLivro(b->livros, isbn);
    if (!n) return 0;
    if (n->livro.disponivel) return -1; // já está disponível

    n->livro.disponivel = 1;
    registrar(b, isbn, OP_DEVOLUCAO);
    return 1;
}

void bibliotecaListar(const Biblioteca* b) {
    if (!b) return;
    listarLivros(b->livros);
}

void bibliotecaOrdenarTitulo(Biblioteca* b) {
    if (!b) return;
    ordenarPorTitulo(&b->livros);
}

void bibliotecaOrdenarAno(Biblioteca* b) {
    if (!b) return;
    ordenarPorAno(&b->livros);
}

void bibliotecaMostrarHistorico(const Biblioteca* b) {
    if (!b) return;
    mostrarHistorico(b->historico);
}
