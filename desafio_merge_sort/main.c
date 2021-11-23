#include "declarations.h"
#include <stdio.h>

int main(void){
    nodo *lista;
    lista = NULL;
    
    printf("Insira uma lista:\n");
    lista = cadastro_de_serie(lista);
    imprime_lista(lista);
    printf("Ordena a lista:\n");
    lista = mergeSort(lista);
    printf("Lista ordenada\n");
    imprime_lista(lista);
}