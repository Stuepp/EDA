#include <stdio.h>
#include "dec.h"

int main(void){
    tree *l, *knot;
    l = knot = NULL;
    int v, c=1;

    while(c != 0){
        printf("0 : out\n1 : inserIn\n2 : serachFor\n");
        scanf("%i", &c);

        switch (c)
        {
        case 1:
            printf("Inser a number:\n");
            scanf("%i", &v);
            l = insertIn(l, v);
            break;
        case 2:
            printf("Inser the knot you are looking for:\n");
            scanf("%i", &v);
            knot = searchFor(l, v);
            //talvez tenha um jeito de melhorar os if else?
            if(knot == NULL){}
            else if(knot->left == NULL && knot->right != NULL){
                printf("The knot info:\nKnot value: %i\nKnot left: null\nKnot right: %i\n", knot->value, knot->right->value);                
            }
            else if(knot->right == NULL && knot->left != NULL){
                printf("The knot info:\nKnot value: %i\nKnot left: %i\nKnot right: null\n", knot->value, knot->left->value);
            }
            else if(knot->left == NULL && knot->right == NULL){
                printf("The knot info:\nKnot value: %i\nKnot left: null\nKnot right: null\n", knot->value);
            }else{
                printf("The knot info:\nKnot value: %i\nKnot left: %i\nKnot right: %i\n", knot->value, knot->left->value, knot->right->value);
            }
            break;
        case 3:
            printf("altura: %i\n", treeHeigh(l, 0));
            knot =  profundidade(l);
            printf("knot: %i\n", knot->value);
        default:
            break;
        }
    }
}