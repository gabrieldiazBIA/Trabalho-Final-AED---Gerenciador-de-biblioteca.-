#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha_historico.h"

NoHistorico* push(NoHistorico* topo, Historico h) {
    NoHistorico* novo = (NoHistorico*)malloc(sizeof(NoHistorico));
    if (!novo) return topo;

    novo->dado = h;
    novo->prox = topo;
    return novo;
}

NoHistorico* pop(NoHistorico* topo) {
    if (!topo) return NULL;
    NoHistorico* temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

const char* operacaoToString(Operacao op) {
    switch (op) {
        case OP_CADASTRO:   return "cadastro";
        case OP_REMOCAO:    return "remocao";
        case OP_EMPRESTIMO: return "emprestimo";
        case OP_DEVOLUCAO:  return "devolucao";
        default:            return "desconhecida";
    }
}

void mostrarHistorico(const NoHistorico* topo) {
    if (!topo) {
        printf("\nHistorico vazio.\n");
        return;
    }

    printf("\n=== HISTORICO (mais recente primeiro) ===\n");
    while (topo) {
        char buf[32];
        struct tm* tm_info = localtime(&topo->dado.quando);
        if (tm_info) strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", tm_info);
        else snprintf(buf, sizeof(buf), "sem-data");

        printf("ISBN: %d | %s | %s\n",
               topo->dado.isbn,
               operacaoToString(topo->dado.op),
               buf);

        topo = topo->prox;
    }
}

void liberarHistorico(NoHistorico* topo) {
    while (topo) {
        NoHistorico* temp = topo;
        topo = topo->prox;
        free(temp);
    }
}
