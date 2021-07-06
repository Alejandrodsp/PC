#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista {
	char nome[50];
	int idade;
	int telefone;
	char data[20];
	char horario[20];
	struct lista *prox;	
};
typedef struct lista lista;
void inserir(lista *p);
void excluir(lista *p);
void editar(lista *p);
void pesquisar(lista *p);
void listar(lista *p);
void ler(lista *p);
void salvar(lista *p);
int main( ){
int op;
lista *head;
head = (lista *)malloc(sizeof(lista));
head->prox = NULL;
ler(head);
	for(;;){
	printf("\tCLINICA DR. STEPHEN STRANGE\n");
	printf("\n1)Cadastrar uma nova consulta\n");
	printf("2)Excluir uma consulta\n");
	printf("3)Editar consulta\n");
	printf("4)Pesquisar consulta por nome\n");
	printf("5)Listar consultas por dia\n");
	printf("6)Sair\n");
	scanf("%d", &op);
	switch (op){
		case 1:
		inserir(head);
		break;
		case 2:
		excluir(head);
		break;
		case 3:
		editar(head);
		break;
		case 4:
		pesquisar(head);
		break;
		case 5:
		listar(head);
		break;
		case 6:
		salvar(head);
		exit(0);
		break;
		default:
		printf("Opcao invalida\n");
		break;
	}	
}
	return 0;
}
void inserir(lista *p){
	lista *nova, *busca;
	
	for(busca = p; busca->prox != NULL; busca = busca->prox);
	
	nova = (lista *)malloc(sizeof(lista));
	busca->prox = nova;
	nova->prox = NULL;
	printf("         CADASTRO\n");
	getchar();
	printf("\nNome completo do paciente: ");
	scanf("%[^\n]s", nova->nome);
	printf("Idade: ");
	scanf("%d", &nova->idade);
	printf("Telefone: ");
	scanf("%d", &nova->telefone);
	printf("Data: ");
	scanf("%s", nova->data);
	printf("Horario da consulta: ");
	scanf("%s", nova->horario);
}
void excluir(lista *p){
	lista *anterior, *atual;
	char *busca;
	int entrou=0;
	busca = (char *) malloc(sizeof(char)*50);
	printf("Digite o nome que deseja apagar: ");
	getchar();
	scanf("%[^\n]s", busca);
	for(anterior = p, atual = p->prox ; atual ; anterior = anterior->prox, atual = atual->prox){
	if(strcmp(atual->nome,busca)== 0){
	anterior->prox = atual->prox;
	free(atual);
	printf("Consulta excluida com sucesso!\n");
	entrou++;
	}
}

if(entrou==0){
	printf("Nenhum registro de consulta com este nome foi encontrado!\n");
}
}
void editar(lista *p){
	char *busca;
	lista *procurar;
	int entrou=0;
	
	busca = (char *)malloc(sizeof(char)*50);
	printf("Informe o nome do paciente que deseja editar: ");
	getchar();
	scanf("%[^\n]s", busca);
	
	for(procurar = p->prox; procurar != NULL; procurar = procurar->prox){
	if(strcmp(busca, procurar->nome)==0){
	printf("     EDITAR CONSULTA\n");
	printf("Informe a nova data da consulta: ");
	scanf("%s", procurar->data);
	printf("Informe o novo horario da consulta: ");
	scanf("%s", procurar->horario);
	entrou++;
}
}

if(entrou==0){
	printf("Nenhum registro de consulta com este nome foi encontrado!\n");
	}
	
	
}
void pesquisar(lista *p){
	lista *procurar;
	char *busca;
	int entrou=0;
	busca = (char *) malloc(sizeof(char)*50);
	printf("Digite o nome que deseja pesuisar: ");
	getchar();
	scanf("%[^\n]s", busca);
	for(procurar = p->prox ; procurar != NULL ;procurar = procurar->prox){
	if(strcmp(procurar->nome,busca)== 0){
	printf("Consulta encontrada!");
	printf("\nNome: %s\n", procurar->nome);
	printf("Idade: %d\n", procurar->idade);
	printf("Telefone: %d\n", procurar->telefone);
	printf("Data: %s\n", procurar->data);
	printf("Horario: %s\n", procurar->horario);
	entrou++;
	}
}
if(entrou==0){
	printf("Nenhum registro de consulta com este nome foi encontrado!\n");
}
}
void listar(lista *p){
	char *dia;
	lista *procurar;
	
	dia = (char *)malloc(sizeof(char)*20);
	printf("Informe o dia: ");
	scanf("%s", dia);
	printf("Consultas do dia %s\n", dia);
	for(procurar = p->prox; procurar != NULL; procurar = procurar->prox){
	if(strcmp(dia, procurar->data)==0){
	printf("\nNome: %s\n", procurar->nome);
	printf("Idade: %d\n", procurar->idade);
	printf("Telefone: %d\n", procurar->telefone);
	printf("Data: %s\n", procurar->data);
	printf("Horario: %s\n", procurar->horario);
}
}
}	
void ler(lista *p){
	FILE *arquivo;
	lista *nova, *busca;
	char l[50];
	arquivo = fopen("database.bak", "r");
	while(fscanf(arquivo,"%[^\n]s", l) == 1){
		for(busca = p;busca->prox!=NULL;busca = busca->prox);
		nova = (lista *) malloc (sizeof(lista));
		strcpy(nova->nome, l);
		fscanf(arquivo, "%d", &nova->idade);
		fscanf(arquivo, "%d", &nova->telefone);
		fscanf(arquivo, "%s", nova->data);
		fscanf(arquivo, "%s", nova->horario);
		nova->prox = NULL;
		busca->prox = nova;
	}

	fclose(arquivo);
}
void salvar(lista *p){
	FILE *arquivo;
	arquivo = fopen("database.bak", "w");
	lista *procurar;
	for(procurar = p->prox ; procurar!= NULL; procurar= procurar->prox){
	fprintf(arquivo,"%s\n", procurar->nome);
	fprintf(arquivo,"%d\n", procurar->idade);
	fprintf(arquivo,"%d\n", procurar->telefone);
	fprintf(arquivo,"%s\n", procurar->data);
	fprintf(arquivo,"%s\n", procurar->horario);	
	}

}
