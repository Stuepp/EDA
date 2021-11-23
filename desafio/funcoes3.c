#include "decs.h"
#include <stdlib.h>

fila *pegaFila(fila *fG, fila *fM){
    if(fG == NULL){printf("Fila vazia!"); return NULL;}
    fila *p, *q;
    p = fG;
    while (p->next->value != 'J')
    {
        fM = sinsereM(p, fM);
        q = p->next;
        free(p);
        p = q;
    }
    p = p->next;
    free(p);
}

fila *insereM(fila *fG, fila *fM){
    fila *new;
    new = (filaM*)malloc(sizeof(filaM));
    new->value = fG->value;
    new ->next = fM;
    return new;
}