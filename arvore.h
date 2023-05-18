typedef struct produto{
    int codigo;
    float preco;
    int estoque;
    char nome[100];
}produto;

typedef struct Arvore{
    produto p;
    struct Arvore* direita;
    struct Arvore* esquerda;
}Arvore;

void menu();
Arvore* criarNo(produto Produto);
Arvore* inserirProduto(Arvore* raiz, produto Produto);
void exibirProdutos(Arvore* raiz);
Arvore* fbArvore(Arvore *arvore);
int altura(Arvore *arvore);
int fatorB(Arvore *arvore);
Arvore* rotacao_E(Arvore *arvore);
Arvore* rotacao_D(Arvore *arvore);

/*



FUNÇÕES NECESSÁRIAS 
Arvore* RemoverProduto(Arvore* arvore, int c); // Remoção do produto da árvore
void buscarProduto(Arvore* arvore, int c); // Buscar os produtos na arvore
void posfixo(Arvore* arvore); // Apresenta a sequência na ordem posfixa
void infixo(Arvore* arvore); // Apresenta a sequência na ordem infixa
void prefixo(Arvore* arvore); // Apresenta a sequência na ordem prefixa
void altura(Arvore* arvore);



*/
