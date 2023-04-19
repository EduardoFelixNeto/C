#include <stdio.h>
#include <stdlib.h>
#define MAX_VETOR 5 

/*
typedef struct Vetor { 
    int dados[MAX_VETOR];
    int inicio, fim;
}Tipo_Vetor;
*/

typedef struct Vetor { 
    int*dados;
    int inicio, fim, elemT;
}Tipo_Vetor; 

int insere_vetor(Tipo_Vetor *V, int dado) {      
    if(V->fim <= MAX_VETOR)       
    {                
        V->dados[V->fim] = dado;                
        (V->fim)++;                 
    return 1;       
    }       
    else           
        return 0; 
}

int acha_vetor(Tipo_Vetor *V, int dado, int *indice){       
    int i, achou = 0;       
    for(i = 0; i < V->fim; i++)       
    {              
        if(V->dados[i] == dado)               
        {                       
            *indice = i;                       
            achou = 1;               
        }       
    }        
    if(achou) 
        return 1;       
    return 0; 
} 

int exclui_vetor(Tipo_Vetor *V, int indice) {       
    int i;     
    if((indice >= 0) && (indice < MAX_VETOR))     
    {             
        for(i = indice; i <  V->fim-1; i++)                    
            V->dados[i] = V->dados[i+1];             
        (V->fim)--;             
        return 1;     
    }     
    return 0; 
} 

int imprime_vetor(Tipo_Vetor *V){
    int i;
    
    for(i=0;i<MAX_VETOR;i++){
        printf("%d ",V->dados[i]);
    }
}

int main(void){
    
    int q1[5] = {10,20,30,40,50};
    int i,num,pos,flag;
    Tipo_Vetor vet;
    
    
    vet.elemT = 5;
    vet.inicio = 0;
    vet.fim = 0;
    
    vet.dados = (int*) malloc(sizeof(int)*vet.elemT);
    
    for(i=0;i<MAX_VETOR;i++){
        insere_vetor(&vet,q1[i]);
    }
    
    imprime_vetor(&vet);
    
    vet.dados[4] = 60;
    
    printf("\n\n");
    
    imprime_vetor(&vet);
    
    printf("\n\n");
    
    printf("Digite um número: ");
    scanf("%d",&num);
    
    vet.dados[0] = num;
    
    printf("\n\n");
    
    imprime_vetor(&vet);
    
    printf("\n\n");
    
    printf("Qual número deseja saber a posição: ");
    scanf("%d",&pos);
    
    printf("\n\n");
    
    for(i=0;i<MAX_VETOR;i++){
        if(vet.dados[i]==pos){
            printf("O número %d está na posição %d",pos,i);
            flag = 1;
            break;
        }
        else
        flag = 0;
            continue;
    }
    if(flag==0){
        printf("Número desejado não encontrado");
    }
}