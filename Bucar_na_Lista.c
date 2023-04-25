#include <stdio.h>

typedef struct listItem {
        int value;
        struct listItem *next;
    }lista;

int main(void){


    lista n1,n2,n3;

    lista *listPointer = &n1;

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    int achei = 0;

    while(listPointer != NULL){
        if(listPointer->value == 200){
            printf("Achei %d\n",listPointer->value);
            achei=1;
            break;
        }
        listPointer = listPointer->next;
    }
    if(achei==0)
        printf("Não Achei");

}