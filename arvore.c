#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

NO_DE_ARVORE* inserirProduto(NO_DE_ARVORE* raiz, PRODUTO produto){
    // Insere, recursivamente, um novo produto na árvore AVL

    // Se a função alcançar NULL após ser apontada pelo nó anterior, cria um novo nó filho e o retorna para a função anterior;
    if (raiz == NULL) {
        NO_DE_ARVORE* novoNo = (NO_DE_ARVORE*)malloc(sizeof(NO_DE_ARVORE)); // aloca memoria para o nó da arvore
        novoNo->produto = produto;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
        // Se um novo nó é inserido, a função se encerra aqui e volta à cadeia recursiva
    }

    // Caso o nó já esteja preenchido
    // Se for menor, tenta adicionar ao filho da esquerda
    if (produto.codigo < raiz->produto.codigo)
        raiz->esquerda = inserirProduto(raiz->esquerda, produto);

    // Se maior, tenta adicionar ao filho da direita
    else if (produto.codigo > raiz->produto.codigo)
        raiz->direita = inserirProduto(raiz->direita, produto);

    // Caso necessário, balanceia a subárvore
    raiz = balancearSubarvore(raiz);
    return raiz;
}

long int verificarAltura(NO_DE_ARVORE *subarvore){
    if(subarvore == NULL) {
        return -1;
    }

    // Verifica, de forma recursiva, a altura das subárvores à esquerda e à direita
    int altura_esq = verificarAltura(subarvore->esquerda);
    int altura_dir = verificarAltura(subarvore->direita);

    // Utiliza o valor da subárvore (esquerda/direita) mais alta;
    if(altura_esq > altura_dir)
        return altura_esq + 1;
    else
        return altura_dir + 1;
}

int calcularFatorDeBalanceamento(NO_DE_ARVORE *subarvore){
    // Calcula o valor do fator de balancemento, descrito pela fórmula
    // (altura da subàrvore à direita) - (altura da subàrvore à esquerda)

    return verificarAltura(subarvore->direita) - verificarAltura(subarvore->esquerda);
}

NO_DE_ARVORE* rotacao_E(NO_DE_ARVORE *subarvore){
    NO_DE_ARVORE *tmp = subarvore->direita;
    subarvore->direita = tmp->esquerda;
    tmp->esquerda = subarvore;
    return tmp;
}

NO_DE_ARVORE* rotacao_D(NO_DE_ARVORE *subarvore){
    NO_DE_ARVORE *tmp = subarvore->esquerda;
    subarvore->esquerda = tmp->direita;
    tmp->direita = subarvore;
    return tmp;
}

NO_DE_ARVORE* balancearSubarvore(NO_DE_ARVORE *subarvore){
    // Calcula o fator de balanceamento da subárvore
    int fb = calcularFatorDeBalanceamento(subarvore);
    int fbAux;

    // Caso a subárvore à esquerda esteja desbalanceada
    if (fb < -1){
		fbAux = calcularFatorDeBalanceamento(subarvore->esquerda);
        if(fbAux > 0)
            subarvore->esquerda =  rotacao_E(subarvore->esquerda);
        subarvore = rotacao_D(subarvore);

    // Caso a subárvore à direita esteja desbalanceada
    } else if (fb > 1) {
		fbAux = calcularFatorDeBalanceamento(subarvore->direita);
        if(fbAux < 0)
            subarvore->direita = rotacao_D(subarvore->direita);
        subarvore = rotacao_E(subarvore);
    }
    
    return subarvore;
}

NO_DE_ARVORE * limparSubarvore(NO_DE_ARVORE * subarvore) {
    // Limpa a subárvore

    if (subarvore != NULL) {
        // Se houver uma subárvore filha à esquerda, chama a função recursivamente para ela até a última folha;
        if (subarvore->esquerda != NULL) {
            subarvore->esquerda =  limparSubarvore(subarvore->esquerda);
        }

        // Se houver uma subárvore filha à direita, chama a função recursivamente para ela até a última folha;
        if (subarvore->direita != NULL) {
            subarvore->direita = limparSubarvore(subarvore->direita);
        }

        // Libera o espaço em memória que estava sendo utilizado pelo nó
        free(subarvore);

        // Uma vez que o valor foi retirado, faz com que o ponteiro do nó pai, que chamou a função, aponte para NULL
        return NULL;

    } else {
        printf("Nenhum elemento encontrado na subarvore");
        return NULL;
    }
}

NO_DE_ARVORE* removerProduto(NO_DE_ARVORE* raiz, long unsigned int codigo){
    if(raiz == NULL){
        printf("\nProduto nao encontrado!\n\n");
        return NULL;
    }else{
        // procura o codigo para remover
        if(raiz->produto.codigo == codigo){
            // remove nos folhas(nos sem filho)
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("Produto com o codigo '%lu' foi removido com sucesso!\n\n", codigo);
                return NULL;
            }
        }else{
            if(codigo < raiz->produto.codigo){
                raiz->esquerda = removerProduto(raiz->esquerda, codigo);
            }else{
                raiz->direita = removerProduto(raiz->direita, codigo);
            }
            return raiz;
        }
    }
}


void exibirTodosProdutos(NO_DE_ARVORE* raiz){
    // Imprime todos os produtos cadastrados na árvore, de forma pré-fixa;

    if (raiz != NULL) {
        exibirProduto(raiz->produto);
        printf("--------------------\n\n");
        exibirTodosProdutos(raiz->esquerda);
        exibirTodosProdutos(raiz->direita);
    } else {
        printf("Subarvore vazia");
    }
}

// NO_DE_ARVORE * exibirTodosProdutos(NO_DE_ARVORE* raiz){
//     // Imprime todos os produtos cadastrados na árvore, de forma pré-fixa;
//     if (raiz != NULL){
//         exibirProduto(raiz->produto);
//         printf("--------------------\n\n");
//         exibirTodosProdutos(raiz->esquerda);
//         exibirTodosProdutos(raiz->direita);
//     }    
// }

void imprimePrefixa (NO_DE_ARVORE * noDeArvore) {
    if(noDeArvore == NULL){
        printf("Subarvore vazia");
    }else{
        // Imprime o código do produto
        printf("%i", noDeArvore->produto.codigo);

        // Chama a função para o filho à esquerda, se houver
        if (noDeArvore->esquerda != NULL) {
            printf(" ");
            imprimePrefixa(noDeArvore->esquerda);
        }

        // Chama a função para o filho à direita, se houver
        if (noDeArvore->direita != NULL) {
            printf(" ");
            imprimePrefixa(noDeArvore->direita);
        }
    }
}

void imprimeInfixa (NO_DE_ARVORE * noDeArvore) {
    if(noDeArvore == NULL){
        printf("Subarvore vazia");
    }else{
        // Chama a função para o filho à esquerda, se houver
        if (noDeArvore->esquerda != NULL) {
            imprimeInfixa(noDeArvore->esquerda);
            printf(" ");
        }

        // Imprime o código do produto
        printf("%lu", noDeArvore->produto.codigo);

        // Chama a função para o filho à direita, se houver
        if (noDeArvore->direita != NULL) {
            printf(" ");
            imprimeInfixa(noDeArvore->direita);
        }
    }
}

void imprimePosfixa (NO_DE_ARVORE * noDeArvore) {
   if(noDeArvore == NULL){
        printf("Subarvore vazia");
    }else{
        // Chama a função para o filho à esquerda, se houver
        if (noDeArvore->esquerda != NULL) {
            imprimePosfixa(noDeArvore->esquerda);
            printf(" ");
        }

        // Chama a função para o filho à direita, se houver
        if (noDeArvore->direita != NULL) {
            imprimePosfixa(noDeArvore->direita);
            printf(" ");
        }

        // Imprime o código do produto
        printf("%lu", noDeArvore->produto.codigo);
    } 
}

NO_DE_ARVORE * buscarElemento (NO_DE_ARVORE * raiz, long unsigned int codigo) {
    // Se a função percorrer as subárvores de forma recursiva até chegar à última folha sem encontrar, retorna NULL
    if (raiz == NULL) {
        return NULL;
    } else {
        // Se o produto for encontrado, retorna o endereço do nó que este ocupa na árvore
        if (raiz->produto.codigo == codigo) {
            return raiz;

        // Procura nas subárvores à esquerda, caso o código buscado seja menor que o do elemento atual
        } else if (codigo < raiz->produto.codigo) {
            return buscarElemento (raiz->esquerda, codigo);

        // Procura nas subárvores à direita, caso o código buscado seja maior que o do elemento atual
        } else {
            return buscarElemento (raiz->direita, codigo);
        }
    }
}
