#include "produto.c"
#ifndef AED_2_ARVORE_H
#define AED_2_ARVORE_H

typedef struct NO_DE_ARVORE{
    PRODUTO produto;
    struct NO_DE_ARVORE* direita;
    struct NO_DE_ARVORE* esquerda;
}NO_DE_ARVORE;

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

NO_DE_ARVORE * buscarElemento(NO_DE_ARVORE * raiz, long unsigned int codigo);
NO_DE_ARVORE * limparSubarvore(NO_DE_ARVORE * subarvore);

#endif //AED_2_ARVORE_H
