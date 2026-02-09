#ifndef LIVRO_H 
#define LIVRO_H

#define TAM_TITULO 100
#define TAM_AUTOR 100

typedef struct {
    int isbn;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int disponivel; // 1 = disponível, 0 = emprestado
} Livro;

#endif