//Alejandro da Silva Pereira M1
#include <stdio.h>
#include <stdlib.h>
struct lista{
	char c;
	struct lista *prox;
};
typedef struct lista lista;
void insere(lista  *p,char c);
void grava_arq(lista *p1,lista *p2,lista *p3,lista *p4,lista *p5,lista *p6,lista *p7,lista *p8,lista *p9,lista *p10);
int main( ){
FILE *arquivo;
int n;
char lixo,letra;
struct lista *head1,*head2,*head3,*head4,*head5,*head6,*head7,*head8,*head9,*head10;

head1 = (lista *)malloc(sizeof(lista ));
head2 = (lista *)malloc(sizeof(lista ));
head3 = (lista *)malloc(sizeof(lista ));
head4 = (lista *)malloc(sizeof(lista ));
head5 = (lista *)malloc(sizeof(lista ));
head6 = (lista *)malloc(sizeof(lista ));
head7 = (lista *)malloc(sizeof(lista ));
head8 = (lista *)malloc(sizeof(lista ));
head9 = (lista *)malloc(sizeof(lista ));
head10 = (lista *)malloc(sizeof(lista));

head1->prox = NULL;
head2->prox = NULL;
head3->prox = NULL;
head4->prox = NULL;
head5->prox = NULL;
head6->prox = NULL;
head7->prox = NULL;
head8->prox = NULL;
head9->prox = NULL;
head10->prox = NULL;

arquivo = fopen("numeros.txt", "r");
	fscanf(arquivo,"%d",&n);
	fscanf(arquivo,"%c",&lixo);
while(!feof(arquivo)){
	switch(n){
	case 1:
	fscanf(arquivo,"%c",&letra);
	insere(head1,letra);
	break;
	case 2:
	fscanf(arquivo,"%c",&letra);
	insere(head2,letra);
	break;
	case 3:
	fscanf(arquivo,"%c",&letra);
	insere(head3,letra);
	break;
	case 4:
	fscanf(arquivo,"%c",&letra);
	insere(head4,letra);
	break;
	case 5:
	fscanf(arquivo,"%c",&letra);
	insere(head5,letra);
	break;
	case 6:
	fscanf(arquivo,"%c",&letra);
	insere(head6,letra);
	break;
	case 7:
	fscanf(arquivo,"%c",&letra);
	insere(head7,letra);
	break;
	case 8:
	fscanf(arquivo,"%c",&letra);
	insere(head8,letra);
	break;
	case 9:
	fscanf(arquivo,"%c",&letra);
	insere(head9,letra);
	break;
	case 10:
	fscanf(arquivo,"%c",&letra);
	insere(head10,letra);
	break;
}
	fscanf(arquivo,"%d",&n);
	fscanf(arquivo,"%c",&lixo);
}
fclose(arquivo);	
grava_arq(head1,head2,head3,head4,head5,head6,head7,head8,head9,head10);
	return 0;
}
void insere(lista *p, char c){
	lista *busca, *nova;
	for(busca=p; busca->prox != NULL; busca=busca->prox);
	nova = (lista*)malloc(sizeof(lista));
	busca->prox = nova;
	nova->prox= NULL;
	nova->c = c;
}
void grava_arq(lista *p1,lista *p2,lista *p3,lista *p4,lista *p5,lista *p6,lista *p7,lista *p8,lista *p9,lista *p10){
	FILE *arquivo;
	lista *busca;
	arquivo =fopen("saida.txt", "w");
	fprintf(arquivo,"Lista 1 " ); 
	for(busca= p1->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
fprintf(arquivo,"\n");
	fprintf(arquivo,"Lista 2 "); 
	for(busca= p2->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
	fprintf(arquivo,"\n");
	fprintf(arquivo,"Lista 3 "); 
	for(busca= p3->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
		fprintf(arquivo,"Lista 4 "); 
	for(busca= p4->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 5 "); 
	for(busca= p5->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 6 "); 
	for(busca= p6->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 7 "); 
	for(busca= p7->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 8 "); 
	for(busca= p8->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 9 "); 
	for(busca= p9->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
		fprintf(arquivo,"\n");
			fprintf(arquivo,"Lista 10 "); 
	for(busca = p10->prox; busca!= NULL; busca=busca->prox){
	fprintf(arquivo,"%c ", busca->c);
}
	fclose(arquivo);
}
