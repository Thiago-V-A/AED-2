#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menu(){ 
      printf("1 - Cadastrar novo produto\n");
      printf("2 - Remove produto\n");
      printf("3 - Buscar produto na arvore\n");
      printf("4 - Mostrar todos os produtos\n");
      printf("5 - Limpar/reinicializar arvore\n");
      printf("7 - Sair\n");
      printf("Entre com a opcao desejada: \n");
}

Arvore* criarNo(produto Produto){
    Arvore* novoNo = (Arvore*)malloc(sizeof(Arvore));
    novoNo->p = Produto;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

Arvore* inserirProduto(Arvore* raiz, produto Produto){
    if (!raiz)
        return criarNo(Produto);

    else{
		if (Produto.codigo < raiz->p.codigo)
			raiz->esquerda = inserirProduto(raiz->esquerda, Produto);
		
		else if (Produto.codigo > raiz->p.codigo)
			raiz->direita = inserirProduto(raiz->direita, Produto);
	
	}
	raiz = fbArvore(raiz);
    return raiz;
	
}

void exibirProdutos(Arvore* raiz){
    if (raiz != NULL) {
        
        printf("Codigo: %d\n", raiz->p.codigo);
        printf("Nome: %s", raiz->p.nome);
        printf("Preco: %.2f\n", raiz->p.preco);
        printf("Quantidade: %d\n", raiz->p.estoque);
        printf("--------------------\n");
        exibirProdutos(raiz->esquerda);
        exibirProdutos(raiz->direita);
    }
}

int altura(Arvore *arvore){ 
    if(!arvore)
        return -1;
        
    int altura_esq = altura(arvore->esquerda), altura_dir = altura(arvore->direita);
    if(altura_esq > altura_dir)
        return altura_esq + 1;
    else
        return altura_dir + 1;
}

int fatorB(Arvore *arvore){
    return altura(arvore->direita) - altura(arvore->esquerda);
}

Arvore* rotacao_E(Arvore *arvore){
    Arvore *tmp = arvore->direita;
    arvore->direita = tmp->esquerda;
    tmp->esquerda = arvore;
    return tmp;
}

Arvore* rotacao_D(Arvore *arvore){
    Arvore *tmp = arvore->esquerda;
    arvore->esquerda = tmp->direita;
    tmp->direita = arvore;
    return tmp;
}

Arvore* fbArvore(Arvore *arvore){

    int fb = fatorB(arvore); 
    int fbAux;

    if(fb<-1){
		fbAux = fatorB(arvore->esquerda);
        if(fbAux > 0)
            arvore->esquerda =  rotacao_E(arvore->esquerda);
        arvore = rotacao_D(arvore);
        
    }else if (fb > 1){
		fbAux = fatorB(arvore->direita);
        if(fbAux < 0)
            arvore->direita = rotacao_D(arvore->direita);
        arvore = rotacao_E(arvore);
    }
    
    return arvore;
}
