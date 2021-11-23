#include "decs.h"
#include <stdlib.h>

list *insere_novo(list *lista,int valor){//oks
    list *novo, *p;
    novo = (list*)malloc(sizeof(list));
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

list * split(list *l){//teoricamente ok
    list *x, *y, *antx;
    //printf("oi0\n");
    if(l == NULL || l ->next == NULL) return l;
    x = l;
    y = l;
    //printf("oi1\n");
    while( y != NULL && y->next != NULL){//verificar
        antx = x;
        x = x->next;
        y = y->next;
        //printf("top toperson topper\n");
        if(y != NULL) {y = y->next;}
    }
    //printf("oi2\n");
    antx->next = NULL;

    //printf("l\n");
    //imprime_lista(l);
    //printf("p\n");
    //imprime_lista(x);
    return x;
}

list *novaOrdem(list *l){//metade jogada para frente
    list *x, *p;
    x = split(l);
    p = x;
    while(p->next != NULL){
        p = p->next;
    }
    p = l;
    return x;
}
list *segundaOrdem(list *ln){//divide em quatro
    list *quarto1, *quarto2, *quarto3, *quarto4, *p, *q;
    quarto1 = split(split(ln));
    p = quarto1;
    q = ln;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    quarto2 = split(split(q));
    p = quarto2;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    quarto3 = split(split(q));
    p = quarto2;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    quarto4 = q;
}