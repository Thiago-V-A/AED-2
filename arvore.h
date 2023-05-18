typedef struct produto{
    int codigo;
    float preco;
    int estoque;
    char nome[100];
}produto;

typedef struct noarv{
    produto p;
    struct noarv* direita;
    struct noarv* esquerda;
}noarv;

void menu();
noarv* criarNo(produto Produto);
noarv* inserirProduto(noarv* raiz, produto Produto);
void exibirProdutos(noarv* raiz);

noarv * limparArvore (noarv* raiz);
/*



FUNÇÕES NECESSÁRIAS 
noarv* RemoverProduto(noarv* arvore, int c); // Remoção do produto da árvore
void buscarProduto(noarv* arvore, int c); // Buscar os produtos na arvore
void posfixo(noarv* arvore); // Apresenta a sequência na ordem posfixa
void infixo(noarv* arvore); // Apresenta a sequência na ordem infixa
void prefixo(noarv* arvore); // Apresenta a sequência na ordem prefixa
void altura(noarv* arvore);


FUNÇÕES PARA O BALANCEAMENTO FB(FATOR DE BALANCEAMENTO FB = ALT_ESQ - ALT_DIR)
No *rotacionarEsquerda();
No *rotacionarDireita();
No *balancemento();
No *atualizarAltura();
No *limpaArvore();



*/
