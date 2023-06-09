#include "menus.h"
#include <stdio.h>


unsigned int menuPrincipal(){
    unsigned int option;
    printf("MENU PRINCIPAL\n\n");

    printf("1 - Cadastrar novo PRODUTO\n");
    printf("2 - Remove PRODUTO\n");
    printf("3 - Buscar PRODUTO na arvore\n");
    printf("4 - Mostrar todos os produtos\n");
    printf("5 - Limpar/reinicializar arvore\n");
    printf("6 - Imprime pré-fixo (códigos)\n");
    printf("7 - Imprime sufixo (códigos)\n");
    printf("8 - Imprime pós-fixo (códigos)\n");
    printf("9 - Imprime altura da árvore\n");
    printf("10 - Importar árvore de arquivo\n");
    printf("11 - Exportar árvore para arquivo\n");
    printf("12 - Excluir produtos a partir de uma lista\n");
    printf("0 - Sair\n\n");
    printf("Entre com a opcao desejada: ");
    scanf("%u", &option);
    getchar();

    // Caso a opção seja inválida, continua pedindo uma entrada ao usuário
    while ((option < 0) || (option > 12)) {
        printf("\nEntre com uma opção válida: ");
        scanf("%u", &option);
        getchar();
    }

    return option;
}