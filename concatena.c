#include <stdio.h>
#include <stdlib.h>
struct lista1{
	int x;
	struct lista1 *prox;
};
struct lista2{
	int x;
	struct lista2 *prox;
};
struct lista3{
	int x;
	struct lista3 *prox;
};
void insere1(struct lista1 *p);
void insere2(struct lista2 *p);
struct lista3 concatena(struct lista1 **p, struct lista2 **q, struct lista3 **r);
int main( ){
	struct lista1 *head1;
	struct lista2 *head2;
	struct lista3 *head3;
	int op;
	
head1= (struct lista1*)malloc(sizeof(struct lista1));
head2= (struct lista2*)malloc(sizeof(struct lista2));
head3= (struct lista3*)malloc(sizeof(struct lista3));
head1->prox = NULL;
head2->prox = NULL;
head3->prox = NULL;
for(;;){
	scanf("%d", &op);
	switch (op){
	case 1:
	insere1(head1);
	break;
	case 2:
	insere2(head2);
	break;
	case 3:
	concatena(&head1,&head2,&head3);
	break;
	case 4:
	
	break;
	
}
}

	
	return 0;
}
void insere1(struct lista1 *p){
	struct lista1 *busca, *nova;
	
	for(busca = p; busca->prox != NULL; busca= busca->prox);
	nova = (struct lista1 *)malloc(sizeof(struct lista1));
	busca->prox = nova;
	nova->prox = NULL;
	scanf("%d", &nova->x);
	
	
}
void insere2(struct lista2 *p){
	struct lista2 *busca, *nova;
	
	for(busca = p; busca->prox != NULL; busca= busca->prox);
	nova = (struct lista2 *)malloc(sizeof(struct lista2));
	busca->prox = nova;
	nova->prox = NULL;
	scanf("%d", &nova->x);	
}
struct lista3 concatena(struct lista1 **p, struct lista2 **q, struct lista3 **r){
	struct lista1 *busca_fim,*inicio;
	struct lista2 *junta;
	struct lista3 *concatena;
	junta = *q;
	inicio = *p;
	for(busca_fim = *p; busca_fim != NULL; busca_fim= busca_fim->prox);
	
	(*busca_fim).prox = junta;
	concatena = inicio;
	return *concatena;
	
}
