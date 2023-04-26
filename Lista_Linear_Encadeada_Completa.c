#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

void insertEnd(listItem *init, int info) {
    listItem *newListItem;
    newListItem = itemCreate();
    newListItem->data = info;
    newListItem->next = NULL;

    listItem *lastItem = init;
    while(lastItem->next != NULL) {
        lastItem = lastItem->next;
    }
    lastItem->next = newListItem;
}

void printList(listItem *listPointer){
    while(listPointer != NULL){
        printf("%d ",listPointer->data);
        listPointer = listPointer->next;
    }
    printf("\n");
}

void findItem(listItem *listPointer){

    int info;

    printf("Qual valor você deseja encontrar? ");
    scanf("%d", &info);

    int achei = 0;

    while(listPointer != NULL){
        if(listPointer->data == info){
            printf("Achei %d\n",listPointer->data);
            achei=1;
            break;
        }
        listPointer = listPointer->next;
    }
    if(achei==0)
        printf("Não Achei");
}


void removeItem(listItem *listPointer){
    int info;

    printf("Qual valor você deseja remover? ");
    scanf("%d", &info);

    listItem *prev = NULL;
    listItem *curr = listPointer;

    while(curr != NULL){
        if(curr->data == info){
            if(prev == NULL){
                listPointer = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            printf("Valor %d removido com sucesso.\n", info);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Valor %d não encontrado.\n",info);
}

int main(void){

    setlocale(LC_ALL, "Portuguese");
    listItem *listInit;
    listInit = itemCreate();
    int info;
    for(int i = 0;i < 3; i++){
        printf("Entre com o valor do novo nó: ");
        scanf("%d",&info);
        insertStart(listInit,info);
    }
    printList(listInit);
    findItem(listInit);
    removeItem(listInit);
    printList(listInit);

    printf("Entre com o valor do novo nó: ");
    scanf("%d",&info);
    insertEnd(listInit,info);

    printList(listInit);

    return 0;

}