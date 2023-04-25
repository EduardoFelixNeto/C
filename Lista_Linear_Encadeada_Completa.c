#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int data;
    struct item *next;

} listItem;

listItem *itemCreate() {
    listItem *p;

    p = (listItem *)malloc(sizeof(listItem));
    p->next = NULL;
    if(!p) {
        printf("Problema ao criar/alocar novo item");
        exit(0);
    }
    return p;
}

void insertStart(listItem *init, int info) {
    listItem *newListItem;
    newListItem = itemCreate();
    newListItem->data = info;
    newListItem->next = init->next;
    init->next = newListItem;
}

void printList(listItem *listPointer){
    while(listPointer != NULL){
        printf("%d ",listPointer->data);
        listPointer = listPointer->next;
    }
    printf("\n");
}

int main(void){
    listItem *listInit;
    listInit = itemCreate();
    int info;
    for(int i = 0;i < 3; i++){
        printf("Entre com o valor do novo nó: ");
        scanf("%d",&info);
        insertStart(listInit,info);
    }
    printList(listInit);
    return 0;

}