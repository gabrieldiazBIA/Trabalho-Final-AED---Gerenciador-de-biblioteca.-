#ifndef PILHA_HISTORICO_H
#define PILHA_HISTORICO_H

typedef struct {
    int isbn;
    char operacao[20]; //"emprestimo" ou "devolução"
} Historico;

typedef struct NoHistorico {
    Historico dado;
    struct NoHistorico* prox;
} NoHistorico;

//Operações da pilha
NoHistorico* push(NoHistorico* topo, Historico h);
NoHistorico* pop(NoHistorico* topo);
void mostrarHistorico(NoHistorico* topo);
void liberarHistorico(NoHistorico* topo);

#endif