#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(){
	char nome[100];
	int codigo, op, estoque;
	float preco;
    noarv* arvore = NULL;
    do{  
        menu();
        scanf("%d",&op);
        switch (op) {
        case 1:
            printf("Insira o codigo do produto:\n");
            scanf("%d", &codigo);
            printf("Insira a quantidade do produto a ser adicionada:\n");
            scanf("%d", &estoque);
            getchar();
            printf("Insira o nome do produto:\n");
			fgets(nome, 100, stdin);
            printf("Insira o preco do produto a ser cadastrado:\n");
            scanf("%f", &preco);
            
            produto novoProduto;
            novoProduto.codigo = codigo;
            strcpy(novoProduto.nome, nome);
            novoProduto.preco = preco;
            novoProduto.estoque = estoque;
            
            arvore = inserirProduto(arvore, novoProduto);
            
            break;

        case 2: 
            break;
            
        case 3: 
            break;

		case 4:
			printf("Aqui estao os produtos cadastrados:\n");
			printf("--------------------\n");
			exibirProdutos(arvore);
			break;
		
        case 7: 
            printf("\nObrigado por usar nosso programa\n");
            break;
            
        default:
            printf("\nVoce digitou uma opcao invalida, por favor, escolha uma das opcoes:\n");
            break;  
        }
        
        
    }while (op!=7);
    return 0;
}

