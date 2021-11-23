typedef struct cell fila;
struct fila
{
    char value;
    fila *next;
};

fila *pegaFila(fila *fG, fila *fM);
fila *insereM(fila *fG, fila *fM);