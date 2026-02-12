# Gerenciador de Biblioteca (AED I)

## Funcionalidades
- Cadastro de livros (ISBN unico)
- Listagem e busca por ISBN
- Emprestimo e devolucao (controle de disponibilidade)
- Remocao de livro
- Ordenacao por titulo e por ano
- Historico de operacoes (pilha: mais recente primeiro)

## Estruturas utilizadas
- Lista encadeada simples: armazenamento dos livros
- Pilha encadeada: historico de operacoes
- Busca linear por ISBN
- Ordenacao por insertion sort na lista

## Como compilar
gcc -Wall -Wextra -O2 main.c biblioteca.c lista_livros.c pilha_historico.c utils.c -o biblioteca

## Como usar
Execute `./biblioteca` e utilize o menu.
