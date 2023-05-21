#ifndef AED_2_PRODUTO_H
#define AED_2_PRODUTO_H

typedef struct PRODUTO{
    long unsigned int codigo;
    float preco;
    int estoque;
    char nome[500];
} PRODUTO;

PRODUTO coletarDadosDoProduto();
void exibirProduto();

#endif //AED_2_PRODUTO_H
