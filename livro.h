#ifndef LIVRO_H 
#define LIVRO_H

typedef struct {
    int isbn;
    char titulo[100];
    char autor[100];
    int ano;
    int disponivel; // 1 = disponível, 0 = emprestado
} Livro;

#endif