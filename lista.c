#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista {
char nome[30];
int matricula;
struct lista *prox;	
};
typedef struct lista lista;
void adicionar(lista *p);
void listar(lista *p);
void excluir(lista *p);
void ordenar(lista *p);
void salvar_txt(lista *p);
void salvar_bin(lista *p);
void ler_txt(lista *p);
void ler_bin(lista *p);
int main( ){
int op;	
lista *head;
head = (lista *)malloc(sizeof(lista));
head->prox = NULL;
for(;;){
	printf("MENU\n");
	printf("1)Adicionar\n");
	printf("2)Listar\n");
	printf("3)Excluir\n");
	printf("4)Ordenar\n");
	printf("5)Salvar em txt\n");
	printf("6)Salvar em bin\n");
	printf("7)Ler txt\n");
	printf("8)Ler bin\n");
	printf("9)Sair\n");
	scanf("%d", &op);
switch (op){
case 1:
adicionar(head);
break;
case 2:
listar(head);
break;
case 3:
excluir(head);
break;
case 4:
ordenar(head);
break;
case 5:
salvar_txt(head);
break;
case 6:
salvar_bin(head);
break;
case 7:
ler_txt(head);
break;
case 8:
ler_bin(head);
break;
case 9:
 exit(0);
break;		
}		
}	
	return 0;
}
void adicionar(lista *p){
	lista *busca, *nova;
	
for(busca = p; busca->prox != NULL; busca = busca->prox);	
	
nova = (lista *) malloc(sizeof(lista));	
busca->prox = nova;
nova->prox = NULL;	
printf("Digite o nome: ");
scanf("%s", nova->nome);	
printf("Digite a matricula: ");
scanf("%d", &nova->matricula);		
}
void listar(lista *p){
	int registro=1;
	lista *listar;
	
	for(listar = p->prox; listar != NULL ; listar = listar->prox){
		printf("Registro %d\n", registro);
		printf("Nome: %s\n", listar->nome);
		printf("Matricula: %d\n", listar->matricula);
		registro++;
	}
}
void excluir(lista *p){
	lista *atual, *anterior;
	char *busca;
	busca = (char *)malloc(sizeof(char)*30);
	printf("Informe o nome que deseja excluir: ");
	scanf("%s", busca);
	for(anterior = p , atual = p->prox; atual ; anterior = anterior->prox, atual = atual->prox){
		if(strcmp(atual->nome, busca)==0){
			printf("Nome excluido com sucesso!\n");
			anterior->prox = atual->prox;
			free(atual);
		}
	}	
	}
void ordenar(lista *p){
	lista *fixa, *varrer;
	char aux[30];
	int auxMatricula;
	
for(fixa = p->prox; fixa->prox != NULL ; fixa = fixa->prox){	
for(varrer = fixa->prox; varrer!= NULL ; varrer = varrer->prox){	
	if(fixa->nome[0]>varrer->nome[0]){
	auxMatricula = varrer->matricula;
	varrer->matricula= fixa->matricula;
	fixa->matricula = auxMatricula;	
	strcpy(aux, varrer->nome);
	strcpy(varrer->nome, fixa->nome);
	strcpy(fixa->nome, aux);
}	
}
}
}	
void salvar_txt(lista *p){
	lista *varrer;
	FILE *arquivo;
	arquivo = fopen("lista.txt","w");

	for(varrer= p->prox; varrer != NULL; varrer = varrer->prox){
		fprintf(arquivo,"%s\n",varrer->nome);
		fprintf(arquivo,"%d\n",varrer->matricula);	
	}
	fclose(arquivo);
}	
void salvar_bin(lista *p){
	lista *varrer;
	FILE *arquivo;
	arquivo = fopen("lista.dat","wb");

	for(varrer= p->prox; varrer != NULL; varrer = varrer->prox){
		
		fwrite(varrer->nome,sizeof(char),30,arquivo);
		fwrite(&varrer->matricula,sizeof(int),1,arquivo);
	}
	fclose(arquivo);
}	
void ler_txt(lista *p){
	char n[30];
	lista *nova, *busca;
	FILE *arquivo;
	arquivo = fopen("lista.txt","r");

while(fscanf(arquivo, "%s", n)==1){
	for(busca = p; busca->prox != NULL; busca= busca->prox);
	nova = (lista*)malloc(sizeof(lista));
	strcpy(nova->nome,n);
	fscanf(arquivo, "%d", &nova->matricula);
	nova->prox = NULL;
	busca->prox = nova;
}		
fclose(arquivo);		
}
void ler_bin(lista *p){
	char n[30];
	lista *nova, *busca;
	FILE *arquivo;
	arquivo = fopen("lista.dat","rb");

while(fread(n,sizeof(char),30, arquivo)==30){
	for(busca = p; busca->prox != NULL; busca= busca->prox);
	nova = (lista*)malloc(sizeof(lista));
	strcpy(nova->nome,n);
	fread(&nova->matricula,sizeof(int),1, arquivo);
	nova->prox = NULL;
	busca->prox = nova;
}		
fclose(arquivo);		
}
