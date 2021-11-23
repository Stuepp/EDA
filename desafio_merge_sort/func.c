#include "declarations.h"
#include <stdio.h>
#include <stdlib.h>

nodo * mergeSort(nodo *l){//teoricamente ok
    nodo *left, *right, *middle;
    if(l == NULL || l->next == NULL) return l;
    middle = split(l);
    printf("\noi\n");
    left = mergeSort(l);//algum problema acontecendo aqui?
    printf("\noi\n");
    right = mergeSort(middle);
    l = merge(left, right);

    return (l);
}

nodo * merge(nodo *left, nodo *right){//acredito aqui estar a falha
    printf("\noi\n");
    nodo *l, *r, *p;
    l = left;
    r = right;
    while (l != NULL && r != NULL)//fazer isso direito
    {
        while(l->value > l->next->value && l->next != NULL){
            l = l->next;
        }
        while(r->value > r->next->value && r->next != NULL){
            r = r->next;
        }
        if(l < r){

        }
        if(r < l){

        }
    }

    return left;
}

nodo * split(nodo *l){//teoricamente ok
    nodo *x, *y, *antx;
    printf("oi0\n");
    if(l == NULL || l ->next == NULL) return l;
    x = l;
    y = l;
    printf("oi1\n");
    while( y != NULL && y->next != NULL){//verificar
        antx = x;
        x = x->next;
        y = y->next;
        printf("top toperson topper\n");
        if(y != NULL) {y = y->next;}
    }
    printf("oi2\n");
    antx->next = NULL;

    printf("l\n");
    imprime_lista(l);
    printf("p\n");
    imprime_lista(x);
    return x;
}

nodo *cadastro_de_serie(nodo *lista){//cadastra uma serie de nodos.ok
    int continuar = 1;
    int valor;
    while (continuar != 0)
    {
        printf("Digite o valor da moeda:\n");
        scanf("%i", &valor);
        lista = insere_novo(lista, valor);
        printf("Deseja conitnuar?\nN - 0\nY - 1\n");
        scanf("%i", &continuar);
    }
    return lista;
}

nodo *insere_novo(nodo *lista,int valor){//oks
    nodo *novo, *p;
    novo = (nodo*)malloc(sizeof(nodo));
    p = lista;
    novo->value = valor;
    novo->next = NULL;
    if(p != NULL){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = novo;
    }else{//se a lista for vazia
        lista = novo;
    }
    return lista;
}

void imprime_lista(nodo *l){//oks
    if(l == NULL){printf("Lista vazia!\n");}
    else{
        while (l != NULL)
        {
            printf("Valor: %i\n", l->value);
            l = l->next;
        }
    }
}