#include <stdio.h>
#include <stdlib.h>
struct lista {
        int numero;
        struct lista *prox;
};
typedef struct lista lista;
void insere(lista *p);
void listar(lista *p);
int main( ){
int op;
lista *head;
head = (lista *)malloc(sizeof(lista));
head->prox = NULL;
head->numero = 0;
for(;;){
        printf("1)Inserir\n");
        printf("2)Mostrar lista\n");
        printf("3)Sair\n");
        scanf("%d", &op);
        switch(op){
                case 1:
                insere(head);
                break;
                case 2:
                listar(head);
                break;
                case 3:
                exit(0);
                break;
        }        
        }
        
        

        
        return 0;
}
void insere(lista *p){
        lista *nova, *onde_colocar;
        if(p->prox == NULL){
                nova = (lista *)malloc (sizeof(lista));
                p->prox = nova;
                nova->prox = NULL;
                printf("Digite um numero: ");
                scanf("%d", &nova->numero);
        }
        else{
                nova = (lista *)malloc (sizeof(lista));
                printf("Digite um numero: ");
                scanf("%d", &nova->numero);
        for (onde_colocar = p; onde_colocar->prox != NULL &&
onde_colocar->prox->numero < nova->numero; onde_colocar = onde_colocar->prox);
                nova->prox = onde_colocar->prox;
                onde_colocar->prox = nova;
        }



}
void listar(lista *p){
        lista *listar;

        for(listar=p->prox; listar!=NULL; listar=listar->prox){
                printf("%d ",listar->numero);
        }
        printf("\n");
}
