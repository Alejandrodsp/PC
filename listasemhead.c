#include <stdio.h>
#include <stdlib.h>
struct lista{
	int n;
	struct lista *prox;
};
typedef struct lista lista;
struct lista * inserir(lista *p);
struct lista * apagar(lista * p);
void mostrar(lista *p);
void grava_txt(lista *p);
struct lista * le_txt(lista *p);
int main( ){
lista *head=NULL;
int op;
for(;;){
	printf("1)Inserir\n");
	printf("2)Apagar\n");
	printf("3)Mostrar\n");
	printf("4)Sair\n");
	scanf("%d", &op);
	switch (op){
		case 1:
		head = inserir(head);
		break;
		case 2:
		head = apagar(head);
		break;
		case 3:
		mostrar(head);
		break;
		case 4:
		exit(0);
		break;
		case 5:
		grava_txt(head);
		break;
		case 6:
		head = le_txt(head);
		break;
	}
	
}
	
	return 0;
}
struct lista* inserir(lista *l){
lista *busca, *nova;
nova = (lista*)malloc(sizeof(lista));
printf("Digite um numero: ");
scanf("%d", &nova->n);
if(l == NULL){
	l = nova;
	nova->prox = NULL;
}
else if(nova->n < l->n){
	nova->prox = l;
	l = nova;
}
else{
	for(busca = l ; busca->prox != NULL && busca->prox->n < nova->n; busca = busca->prox);
	nova->prox = busca->prox;
	busca->prox = nova;
	
}
return l;
}

void mostrar(lista *p){
	lista *i;
	for(i=p; i != NULL;i=i->prox){
	 printf("%d\n", i->n);
	}
}
struct lista* apagar( lista *l){
	int x;
	lista *i,*j;
	printf("Digite o numero que deseja apagar: ");
	scanf("%d", &x);
	if(l == NULL){
		return l;
	}
	if(l->n == x){
	i = l;
	l = l->prox;
	free(i);
}
else{
	for(i=l, j=l->prox; i != NULL && j != NULL; i=i->prox,j=j->prox){
	if(j->n == x){
		i->prox = j->prox;
		free(j);
	}
}
	
}
return l;	
}
void grava_txt(lista *p){
	FILE *arquivo;
	lista *i;
	arquivo = fopen("numeros.txt", "w");
	for(i=p;i!=NULL;i=i->prox){
		fprintf(arquivo, "%d\n",i->n);
	}
	
fclose(arquivo);	
}
struct lista* le_txt(lista *p){
	
	FILE *arquivo;
	lista *i,*nova;
	arquivo = fopen("numeros.txt", "r");
	nova = (lista*)malloc(sizeof(lista));	
	fscanf(arquivo,"%d", &nova->n);
	while(!feof(arquivo)){
	for(i=p;i!= NULL;i=i->prox);
	i->prox = nova;
	nova->prox=NULL;
	nova = (lista*)malloc(sizeof(lista));	
	fscanf(arquivo,"%d", &nova->n);
}
	
fclose(arquivo);	
return p;
}
