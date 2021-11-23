#include <stdio.h>
#include "dec.h"
#include <stdlib.h>

tree *insertIn(tree *l, int v){//ok
    tree *new;
    new = (tree*)malloc(sizeof(tree));
    if(l == NULL){
        new->value = v;
        new->left = new->right = NULL;
        return new;
    }
    if(l != NULL){
        if(v < l->value){
            l->left = insertIn(l->left, v);
        } else if(v > l->value){
            l->right = insertIn(l->right, v);
        }
    }
    return l;
}

tree *searchFor(tree *l, int v){
    if(l == NULL){printf("Empty tree or not in the tree!\n"); return NULL;}
    if(v == l->value){return l;}
    else{
        if(v < l->value){
            return searchFor(l->left, v);
        }
        if(v > l->value){
            return searchFor(l->right, v);
        }
    }
}

tree *busca_comPai(tree *r, int chave, tree **pai)
{
    if (r == NULL || r->value == chave)
        return r;
    else if (r->value > chave)
        *pai = r;
    return busca_comPai(r->left, chave, pai);
    *pai = r;
    return busca_comPai(r->right, chave, pai);
}

tree *cutRoot(tree *l, int v){//testar
    tree *p = NULL, *pai = NULL, *sucessor = NULL, *ramo = NULL, *pai_sucessor = NULL;
    p = busca_comPai(l, v, &pai);

    if(p->left == NULL && p->right != NULL){
        ramo = p->right;
    }
    else if(p->left != NULL && p->right == NULL){
        ramo = p->left;
    }
    else if(p->left != NULL & p->right != NULL){
        sucessor = p->right;
        pai_sucessor = p;
        while (sucessor->left != NULL)
        {
            pai_sucessor = sucessor;
            sucessor = sucessor->left;
        }
        sucessor->left = p->left;
        pai_sucessor->left = sucessor->right;
        sucessor->right = p->right;
        ramo = sucessor;
    }
    if(pai == NULL)
        l = ramo;
    else if(pai->left == p)
        pai->left = ramo;
    else if(pai->right)
        pai->right = ramo;
    free(p);
    return l;
}

int noDeep(tree *l, int v, int cont){//testar
    if(l == NULL){printf("Empty tree or not in the tree!\n"); return 0;}
    if(v == l->value){return cont;}
    else{
        if(v < l->value){return noDeep(l, v, cont++);}
        if(v > l->value){return noDeep(l, v, cont++);}
    }
}

int treeHeigh(tree *l, int cont){//melhorar
    int esq, dir;
    if(l == NULL){printf("Empty tree!\n"); return 0;}//impreimindo isso
    if(l->left == NULL && l->right == NULL){return cont;}
    else{
        esq = treeHeigh(l->left, cont++);
        dir = treeHeigh(l->right, cont++);
        if(esq > dir){
            return esq++;
        }else if(dir > esq){
            return dir++;
        }
    }
}
tree *profundidade(tree *r){
    if(r = NULL){printf("arvore vazia!\n"); return NULL;}
    tree *p = r;
    while (p->left == NULL && p->right == NULL)
    {
        if(treeHeigh(p->left, 0) > treeHeigh(p->right, 0)){
            p = p->left;
        }else{
            p = p->right;
        }
    }
    return p;
}

int Highdif(tree *l, int v){//testar
    tree *p;
    int diferenca = 0, esquerda, direita;;
    if(l == NULL){printf("Empty tree!\n"); return 0;}
    p = l;
    p = searchFor(p, v);
    esquerda = treeHeigh(p->left, v);
    direita = treeHeigh(p->right, v);
     
    diferenca = esquerda - direita;

    return diferenca;
}

tree *balancedInsert(tree *l, int v){//fazer
    int diferenca;
    if(l == NULL){printf("Empty tree!\n"); return NULL;}
    diferenca = Highdif(l , v);

}

tree *balancedCut(tree *l, int v){//fazer
    if(l == NULL){printf("Empty tree!\n"); return NULL;}
    cutRoot(l, v);
    if(Highdif(l, l->value) >= 2){

    }
}

void maiorValor(tree *l){//testar
    if(l == NULL){printf("Empty tree!\n");}
    while(l->right != NULL){
        l = l->right;
    }
    printf("maior: %i\n", l->value);
}

void ordemCrescente(tree *l){//verificar
    int menor, i=1;
    tree *p;
    if(l == NULL){printf("Empty tree!\n");}
    while (l->left != NULL)
    {
        l = l->left;
    }
    menor = l->value;
    printf("%i \n", menor);
    while (searchFor(l, menor+1) != NULL)
    {
        p = searchFor(l, menor+i);
        printf("%i \n", p->value);
        i++;
    }
    
}