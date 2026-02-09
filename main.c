#include <stdio.h>
#include "lista_livros.h"
#include "pilha_historico.h"
#include "utils.h"

int main()
{
    No* biblioteca = NULL;
    //NoHistorico* historico = NULL;

    Livro l1 = {123, "Algoritmos", "Cormen", 2009, 1};
    Livro l2 = {456, "Estruturas de Dados", "Sedgewick", 2011, 1};

    biblioteca = inserirLivro(biblioteca, l1);
    biblioteca = inserirLivro(biblioteca, l2);

    listarLivros(biblioteca);
    liberarLista(biblioteca);

    return 0;
}
