typedef struct cell nodo;
struct cell{
    int value;
    nodo *next;
};

nodo * mergeSort(nodo *l);
nodo * merge(nodo *left, nodo *right);
nodo * split(nodo *l);
nodo *cadastro_de_serie(nodo *lista);
nodo *insere_novo(nodo *lista,int valor);
void imprime_lista(nodo *l);