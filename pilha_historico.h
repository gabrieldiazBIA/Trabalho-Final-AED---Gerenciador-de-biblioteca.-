#ifndef PILHA_HISTORICO_H
#define PILHA_HISTORICO_H

#include <time.h>

typedef enum {
    OP_CADASTRO,
    OP_REMOCAO,
    OP_EMPRESTIMO,
    OP_DEVOLUCAO
} Operacao;

typedef struct {
    int isbn;
    Operacao op;
    time_t quando; // timestamp (opcional, mas deixa mais "real")
} Historico;

typedef struct NoHistorico {
    Historico dado;
    struct NoHistorico* prox;
} NoHistorico;

NoHistorico* push(NoHistorico* topo, Historico h);
NoHistorico* pop(NoHistorico* topo);
void mostrarHistorico(const NoHistorico* topo);
void liberarHistorico(NoHistorico* topo);

const char* operacaoToString(Operacao op);

#endif
