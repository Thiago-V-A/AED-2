#include <stdio.h>
#include "produto.h"

PRODUTO coletarDadosDoProduto() {
    PRODUTO novoProduto;

    printf("Insira o codigo do produto:\n");
    scanf("%lu", &novoProduto.codigo);
    getchar();

    printf("Insira a quantidade do produto a ser adicionada:\n");
    scanf("%d", &novoProduto.estoque);
    getchar();

    printf("Insira o nome do produto:\n");
    scanf("%[^\n]", novoProduto.nome);
    getchar();

    printf("Insira o preco do produto a ser cadastrado:\n");
    scanf("%f", &novoProduto.preco);
    getchar();

    return novoProduto;
}

void exibirProduto(PRODUTO produto) {
    printf("Codigo: %d\n", produto.codigo);
    printf("Nome: %s", produto.nome);
    printf("Preco: %.2f\n", produto.preco);
    printf("Quantidade: %d\n", produto.estoque);
}
