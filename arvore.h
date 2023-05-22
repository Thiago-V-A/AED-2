#include "produto.c"
#ifndef AED_2_ARVORE_H
#define AED_2_ARVORE_H

typedef struct NO_DE_ARVORE{
    PRODUTO produto;
    struct NO_DE_ARVORE* direita;
    struct NO_DE_ARVORE* esquerda;
}NO_DE_ARVORE;

typedef struct ELEMENTO_DE_FILA {
    NO_DE_ARVORE * noDeArvore;
    struct ELEMENTO_DE_FILA * proximo;
} ELEMENTO_DE_FILA;

NO_DE_ARVORE * inserirProduto(NO_DE_ARVORE* raiz, PRODUTO produto);

void exibirTodosProdutos(NO_DE_ARVORE* raiz);

NO_DE_ARVORE * balancearSubarvore(NO_DE_ARVORE *subarvore);

long int verificarAltura(NO_DE_ARVORE *subarvore);
int calcularFatorDeBalanceamento(NO_DE_ARVORE *subarvore);

NO_DE_ARVORE * rotacao_E(NO_DE_ARVORE *subarvore);
NO_DE_ARVORE * rotacao_D(NO_DE_ARVORE *subarvore);

void imprimePrefixa(NO_DE_ARVORE *noDeArvore);
void imprimeInfixa(NO_DE_ARVORE *raiz);
void imprimePosfixa(NO_DE_ARVORE *raiz);

NO_DE_ARVORE * buscarElemento(NO_DE_ARVORE * raiz, unsigned long long int codigo);
NO_DE_ARVORE * limparSubarvore(NO_DE_ARVORE * subarvore);

void adicionarAFila(ELEMENTO_DE_FILA * cabecaDaFila, NO_DE_ARVORE * noDeArvore);
void dadosParaArquivo(NO_DE_ARVORE * raiz);
NO_DE_ARVORE * dadosDoArquivo(NO_DE_ARVORE * raiz);

#endif //AED_2_ARVORE_H
