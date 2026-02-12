#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "utils.h"

void mostrarMenu(void) {
    printf("\n========== GERENCIADOR DE BIBLIOTECA ==========\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Buscar por ISBN\n");
    printf("4. Emprestar livro\n");
    printf("5. Devolver livro\n");
    printf("6. Remover livro\n");
    printf("7. Ordenar por titulo\n");
    printf("8. Ordenar por ano\n");
    printf("9. Mostrar historico\n");
    printf("0. Sair\n");
    printf("==============================================\n");
}

int lerInteiro(const char* prompt, int* out) {
    char buf[128];

    while (1) {
        if (prompt) printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin)) return 0;

        // remover \n
        buf[strcspn(buf, "\n")] = '\0';

        // rejeitar vazio
        if (buf[0] == '\0') {
            printf("Entrada vazia. Tente novamente.\n");
            continue;
        }

        errno = 0;
        char* end = NULL;
        long val = strtol(buf, &end, 10);

        // valida conversão
        if (errno != 0 || end == buf || *end != '\0') {
            printf("Valor invalido. Digite um numero inteiro.\n");
            continue;
        }

        // cabe em int?
        if (val < -2147483648L || val > 2147483647L) {
            printf("Numero fora do intervalo de int.\n");
            continue;
        }

        *out = (int)val;
        return 1;
    }
}

void lerString(const char* prompt, char* out, size_t tam) {
    char buf[1024];

    while (1) {
        if (prompt) printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin)) {
            // se EOF, devolve string vazia
            out[0] = '\0';
            return;
        }

        // remover \n
        buf[strcspn(buf, "\n")] = '\0';

        if (buf[0] == '\0') {
            printf("Texto vazio. Tente novamente.\n");
            continue;
        }

        // copiar com limite
        strncpy(out, buf, tam - 1);
        out[tam - 1] = '\0';
        return;
    }
}
