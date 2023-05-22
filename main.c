#include "arvore.c"
#include "menus.c"


int main () {
    unsigned int option;
    long long unsigned int codigoABuscar;
    PRODUTO novoProduto;
    NO_DE_ARVORE * elementoBuscado;
    NO_DE_ARVORE * raiz = NULL;

    do {
        option = menuPrincipal();

        switch (option) {
            // Cadastrar novo produto
            case 1:
                novoProduto = coletarDadosDoProduto();
                raiz = inserirProduto(raiz, novoProduto);
                break;

            // Remover produto
            case 2:
                break;

            // Buscar produto
            case 3:
                printf("\nDigite o código a ser buscado: ");
                scanf("%lu", &codigoABuscar);
                getchar();
                elementoBuscado = buscarElemento(raiz, codigoABuscar);
                if (elementoBuscado == NULL) {
                    printf("\nProduto não encontrado\n\n");

                } else {
                    printf("\nElemento encontrado\n");
                    exibirProduto(elementoBuscado->produto);
                    printf("\n");
                }

                break;

            // Mostrar todos os produtos
            case 4:
                exibirTodosProdutos(raiz);
                printf("\n");
                break;

            // Limpar/reinicializar árvore
            case 5:
                raiz = limparSubarvore(raiz);
                break;

            // Imprime pré-fixo
            case 6:
                imprimePrefixa(raiz);
                printf("\n");
                break;

            // Imprime infixo
            case 7:
                imprimeInfixa(raiz);
                printf("\n");
                break;

            // Imprime pós-fixo
            case 8:
                imprimePosfixa(raiz);
                printf("\n");
                break;

            // Altura da árvore
            case 9:
                if (raiz != NULL) {
                    printf("\nAltura da árvore: %li\n\n", verificarAltura(raiz));
                } else {
                    printf("\nA arvore ainda não foi inicializada\n");
                }
                break;

            // Importar de arquivo
            case 10:
                raiz = dadosDoArquivo(raiz);
                break;

            // Exportar para arquivo
            case 11:
                if (raiz != NULL) {
                    dadosParaArquivo(raiz);
                } else {
                    printf("\nA arvore ainda não foi inicializada\n");
                }
                break;

            // Sair
            case 0:
                break;
        }


    } while (option != 0);


    return 0;
}
