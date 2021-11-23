typedef struct cell tree;
struct cell
{
    int value;
    tree *left;
    tree *right;
};

tree *insertIn(tree *l, int v);
tree *searchFor(tree *l, int v);
tree *busca_comPai(tree *r, int chave, tree **pai);
tree *cutRoot(tree *l, int v);
int noDeep(tree *l, int v, int cont);
int treeHeigh(tree *l, int cont);
int Highdif(tree *l, int v);
tree *balancedInsert(tree *l, int v);
tree *balancedCut(tree *l, int v);
void maiorValor(tree *l);
void ordemCrescente(tree *l);
tree *profundidade(tree *r);