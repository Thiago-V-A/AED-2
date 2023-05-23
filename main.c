#include "arvore.c"
#include "menus.c"

#define enter_para_retornar() {printf("\nPressione ENTER para retornar ou sair."); getchar(); }

#ifdef __linux__
#define clear_screen() system("clear")
#endif

#ifdef _WIN32
#define clear_screen() system("cls")
#endif

int main () {
    unsigned int option;
    long long unsigned int codigoABuscar, codigoARemover;

    PRODUTO novoProduto;
    NO_DE_ARVORE * elementoBuscado;
    NO_DE_ARVORE * elementoRemovido;
    NO_DE_ARVORE * raiz = NULL;

    do {
        clear_screen();
        option = menuPrincipal();

        switch (option) {
            // Cadastrar novo produto
            case 1:
                novoProduto = coletarDadosDoProduto();
                raiz = inserirProduto(raiz, novoProduto);
                break;

            // Remover produto
            case 2:
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%llu", &codigoARemover);
                getchar();
                removerProduto(raiz, codigoARemover);
                break;

            // Buscar produto
            case 3:
                printf("\nDigite o codigo a ser buscado: ");
                scanf("%llu", &codigoABuscar);
                getchar();
                elementoBuscado = buscarElemento(raiz, codigoABuscar);
                if (elementoBuscado == NULL) {
                    printf("\nProduto nao encontrado\n\n");

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
                    printf("\nAltura da arvore: %li\n\n", verificarAltura(raiz));
                } else {
                    printf("\nA arvore ainda nao foi inicializada\n");
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

            case 12:
                if (raiz != NULL) {
                    raiz = removerPorLista(raiz);
                } else {
                    printf("\nA arvore ainda não foi inicializada\n");
                }
                break;

            // Sair
            case 0:
                break;
        }

        enter_para_retornar();

    } while (option != 0);


    return 0;
}
