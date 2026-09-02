// avalia.h - Interface do avaliador de expressões em notação pré-fixa
//
// Disciplina: Algoritmos e Estrutura de Dados 2 (CI1056) - UFPR

#ifndef AVALIA_H
#define AVALIA_H

// Tamanho máximo (em caracteres) de um único token da expressão
#define TAMANHO_MAXIMO_ITEM 64

// proximo_item - Lê o próximo token da entrada padrão (stdin).
//
// Retorna um ponteiro para uma string alocada dinamicamente com o token lido,
// ou NULL caso a entrada tenha chegado ao fim (EOF).
// O chamador é responsável por liberar a memória com free().
char *proximo_item(void);

// avalia - Avalia recursivamente uma expressão em notação pré-fixa.
//
// Lê tokens da entrada via proximo_item(). Se o token for um número,
// retorna seu valor. Se for um operador (+, -, *, /), chama avalia()
// recursivamente duas vezes para obter os operandos e retorna o resultado.
// Retorna NAN em caso de entrada inválida ou vazia.
double avalia(void);

#endif // AVALIA_H
