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

fila *pegaFila(fila *f, tree *l){
    if(f == NULL){printf("Fila vazia!"); return NULL;}
    fila *p;
    while (p->before != NULL)
    {
        l = insertIn(l, p->value);
        p = p->before;
    }
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

void ordemCrescente(tree *l){
    int menor, i=1;
    tree *p;
    if(l == NULL){printf("Empty tree!\n"); return NULL;}
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