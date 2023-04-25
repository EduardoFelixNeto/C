#include <stdio.h>

typedef struct listItem {
        int value;
        struct listItem *next;
    }lista;

int main(void){


    lista n1,n2,n3;

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    n1.next = &n2;
    n2.next = &n3;

    printf("%d\n",n1.value);
    printf("%d\n",n1.next->value);
    printf("%d\n",n2.next->value);

}