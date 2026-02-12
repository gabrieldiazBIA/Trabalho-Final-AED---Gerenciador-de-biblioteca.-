#include <stdio.h>
#include "biblioteca.h"
#include "utils.h"

static void cadastrar(Biblioteca* b) {
    Livro livro;

    if (!lerInteiro("ISBN: ", &livro.isbn)) return;
    lerString("Titulo: ", livro.titulo, sizeof(livro.titulo));
    lerString("Autor: ", livro.autor, sizeof(livro.autor));
    if (!lerInteiro("Ano: ", &livro.ano)) return;

    livro.disponivel = 1;

    int r = bibliotecaCadastrar(b, livro);
    if (r == 1) {
        printf("Livro cadastrado com sucesso.\n");
    } else if (r == -1) {
        printf("Falha: ISBN ja cadastrado.\n");
    } else {
        printf("Falha: erro de memoria.\n");
    }
}

static void buscar(Biblioteca* b) {
    int isbn;
    if (!lerInteiro("ISBN para buscar: ", &isbn)) return;

    No* n = bibliotecaBuscar(b, isbn);
    if (!n) {
        printf("Nao encontrado.\n");
        return;
    }

    printf("\nEncontrado:\n");
    printf("ISBN: %d\n", n->livro.isbn);
    printf("Titulo: %s\n", n->livro.titulo);
    printf("Autor: %s\n", n->livro.autor);
    printf("Ano: %d\n", n->livro.ano);
    printf("Disponivel: %s\n", n->livro.disponivel ? "sim" : "nao");
}

static void emprestar(Biblioteca* b) {
    int isbn;
    if (!lerInteiro("ISBN para emprestar: ", &isbn)) return;

    int r = bibliotecaEmprestar(b, isbn);
    if (r == 1) printf("Emprestimo realizado.\n");
    else if (r == -1) printf("Falha: livro ja esta emprestado.\n");
    else printf("Falha: ISBN nao existe.\n");
}

static void devolver(Biblioteca* b) {
    int isbn;
    if (!lerInteiro("ISBN para devolver: ", &isbn)) return;

    int r = bibliotecaDevolver(b, isbn);
    if (r == 1) printf("Devolucao realizada.\n");
    else if (r == -1) printf("Falha: livro ja esta disponivel.\n");
    else printf("Falha: ISBN nao existe.\n");
}

static void remover(Biblioteca* b) {
    int isbn;
    if (!lerInteiro("ISBN para remover: ", &isbn)) return;

    int r = bibliotecaRemover(b, isbn);
    if (r == 1) printf("Livro removido.\n");
    else printf("Falha: ISBN nao existe.\n");
}

int main(void) {
    Biblioteca b;
    bibliotecaInit(&b);

    int opcao;

    while (1) {
        mostrarMenu();
        if (!lerInteiro("Escolha uma opcao: ", &opcao)) break;

        switch (opcao) {
            case 1: cadastrar(&b); break;
            case 2: bibliotecaListar(&b); break;
            case 3: buscar(&b); break;
            case 4: emprestar(&b); break;
            case 5: devolver(&b); break;
            case 6: remover(&b); break;
            case 7: bibliotecaOrdenarTitulo(&b); printf("Ordenado por titulo.\n"); break;
            case 8: bibliotecaOrdenarAno(&b); printf("Ordenado por ano.\n"); break;
            case 9: bibliotecaMostrarHistorico(&b); break;
            case 0:
                bibliotecaFree(&b);
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }

    bibliotecaFree(&b);
    return 0;
}
