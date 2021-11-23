typedef struct cell list;
struct list
{
    int value;
    list *next;
};

list *insere_novo(list *lista,int valor);
list * split(list *l);
list *novaOrdem(list *l);
list *segundaOrdem(list *ln);