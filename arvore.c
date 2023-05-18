#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menu(){ 
      printf("1 - Cadastrar novo produto\n");
      printf("2 - Remove produto\n");
      printf("3 - Buscar produto na arvore\n");
      printf("4 - Mostrar todos os produtos\n");
      printf("5 - Remover todos os produtos da árvore\n");
      printf("7 - Sair\n");
      printf("Entre com a opcao desejada: \n");
}

noarv* criarNo(produto Produto){
    noarv* novoNo = (noarv*)malloc(sizeof(noarv));
    novoNo->p = Produto;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

noarv* inserirProduto(noarv* raiz, produto Produto){
    if (raiz == NULL)
        return criarNo(Produto);

    if (Produto.codigo < raiz->p.codigo)
		raiz->esquerda = inserirProduto(raiz->esquerda, Produto);
		
    else if (Produto.codigo > raiz->p.codigo)
		raiz->direita = inserirProduto(raiz->direita, Produto);
    
    return raiz;
}

void exibirProdutos(noarv* raiz){
    if (raiz != NULL) {
        exibirProdutos(raiz->esquerda);
        printf("Codigo: %d\n", raiz->p.codigo);
        printf("Nome: %s", raiz->p.nome);
        printf("Preco: %.2f\n", raiz->p.preco);
        printf("Quantidade: %d\n", raiz->p.estoque);
        printf("--------------------\n");
        exibirProdutos(raiz->direita);
    }
}

noarv * limparArvore(noarv* raiz) {
  if (raiz->esquerda != NULL) {
    raiz->esquerda =  limparArvore(raiz->esquerda);
  }
  if (raiz->direita != NULL) {
    raiz->direita = limparArvore(raiz->direita);
  }
  free(raiz);
  return NULL;
}
