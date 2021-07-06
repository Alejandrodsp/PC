#include <stdio.h>
#include <stdlib.h>
struct lista{
	int n;
	struct lista *prox;
};
typedef struct lista lista;
void start(lista *p);
void listar(lista *p);
int excluir(lista *p, int n);
int main( ){
lista *head;
int x;
head = (lista *)malloc(sizeof(lista));
head->prox = NULL;
start(head);
listar(head);
printf("Digite quantos numeros deseja excluir: ");
scanf("%d", &x);
if(excluir(head, x)==1){
	printf("Os %d numeros da lista foram removidos com sucesso!\n", x);
	listar(head);
}
else{
	printf("Nao foi possivel remover os numeros!\n");
	listar(head);
}
	
	return 0;
}
void start(lista *p){
lista *i, *nova;
int aux;
FILE *arquivo;
arquivo = fopen("numeros.txt", "r");
while(fscanf(arquivo, "%d", &aux)==1){
	
for(i=p; i->prox!= NULL; i=i->prox);

nova = (lista *)malloc(sizeof(lista));
i->prox = nova;
nova->prox = NULL;
nova->n = aux;
}
}
void listar(lista *p){
        lista *listar;

        for(listar=p->prox; listar!=NULL; listar=listar->prox){
                printf("%d ",listar->n);
        }
        printf("\n");
}	
int excluir(lista *p, int n){
	 int qtd_na_lista=0;
	 lista *i,*head,*aux;
	 int count=0;
	head = p;


        for(i=p->prox; i != NULL; i=i->prox){
                qtd_na_lista++;
        }
		if(qtd_na_lista >= n){
			for(i = p->prox; count<n; count++){
				aux = i;
				i = i->prox;
				free(aux);
			}
			head->prox=i;

			return 1;
		}
		else{
			return 0;
		}

}	
	
	
	
	
	
	
	
	
	
	


