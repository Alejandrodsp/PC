#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct cel {
	char login[30];
	char senha[30];
	struct cel *prox;
};
typedef struct cel celula;
void inserir(celula * p);
void listar(celula * p);
void salvar_txt(celula * p);
void ler_de_txt(celula * p);
void salvar_bin(celula * p);
void ler_de_bin(celula * p);
void buscar(celula * p);
void excluir(celula * p);
void modificar_senha(celula *p);
int main( ) {
celula *head;
int op;

head = (celula *)malloc(sizeof(celula));
head->prox = NULL;

for(;;){
printf("         MENU\n");
printf("1)Inserir\n");
printf("2)Listar\n");
printf("3)Salvar em arquivo texto\n");
printf("4)Ler de arquivo texto\n");
printf("5)Salvar em arquivo binario\n");
printf("6)Ler de arquivo binario\n");
printf("7)Buscar por login\n");
printf("8)Excluir por login\n");
printf("9)Modificar a senha\n");
printf("10)Sair\n");	
scanf("%d", &op);
switch (op){
	case 1:
	inserir(head);
	break;
	case 2:
	listar(head);
	break;
	case 3:
	salvar_txt(head);
	break;
	case 4:
	ler_de_txt(head);
	break;
	case 5:
	salvar_bin(head);
	break;
	case 6:
	ler_de_bin(head);
	break;
	case 7:
	buscar(head);
	break;
	case 8:
	excluir(head);
	break;
	case 9:
	modificar_senha(head);
	break;
	case 10:
	exit(0);
	break;	
}
}
	
	return 0;
}
void inserir(celula * p){
	celula *busca, *nova;
	
	for(busca = p ; busca->prox != NULL; busca = busca->prox);
	
	nova = (celula *)malloc(sizeof(celula));
	busca->prox = nova;
	nova->prox = NULL;
	printf("Informe o login: ");
	scanf("%s", nova->login);
	printf("Informe a senha: ");
	scanf("%s", nova->senha);
}

void listar( celula * p){
	celula *listar;
	for(listar = p->prox; listar != NULL; listar = listar->prox){
		printf("Login: %s\n", listar->login);
		printf("Senha: %s\n", listar->senha);
		printf("\n");
	}
}
void salvar_txt(celula * p){
	celula *listar;
	FILE *arquivo;
	arquivo = fopen("database.txt", "w");
	for(listar = p->prox; listar != NULL; listar = listar->prox){
		fprintf(arquivo, "%s\n", listar->login);
		fprintf(arquivo, "%s\n", listar->senha);
	}
	fclose(arquivo);
}	
void ler_de_txt(celula * p){
	FILE *arquivo;
	celula *nova, *busca;
	char l[30];
	arquivo = fopen("database.txt", "r");
	while(fscanf(arquivo,"%s", l) == 1){
		for(busca = p;busca->prox!=NULL;busca = busca->prox);
		nova = (celula *) malloc (sizeof(celula));
		strcpy(nova->login, l);
		fscanf(arquivo, "%s", nova->senha);
		nova->prox = NULL;
		busca->prox = nova;
	}

	fclose(arquivo);
}
void salvar_bin(celula * p){
	celula *listar;
	FILE *arquivo;
	arquivo = fopen("database.dat", "wb");
	for(listar = p->prox; listar != NULL; listar = listar->prox){
		fwrite(listar->login, sizeof(char), 30, arquivo);
		fwrite(listar->senha, sizeof(char), 30, arquivo);
	}
	fclose(arquivo);
}

void ler_de_bin(celula * p){
	FILE *arquivo;
	celula *nova, *busca;
	char l[30];
	arquivo = fopen("database.dat", "rb");
	while(fread(l, sizeof(char), 30, arquivo) == 30){
		for(busca = p;busca->prox!=NULL;busca = busca->prox);
		
		
		nova = (celula *) malloc (sizeof(celula));
		strcpy(nova->login, l);
		fread(nova->senha, sizeof(char), 30, arquivo);
		nova->prox = NULL;
		busca->prox = nova;
	}

	fclose(arquivo);
}
void buscar(celula * p){
	celula *pesquisa;
	char *busca;
	busca = (char *) malloc (sizeof(char)*30);
	printf("Digite o login que deseja buscar: ");
	scanf("%s", busca);
	for(pesquisa = p->prox; pesquisa != NULL ; pesquisa = pesquisa->prox){
		if(strcmp(pesquisa->login, busca)==0){
	printf("Login encontrado!\n");
	printf("Login: %s\n", pesquisa->login);
	printf("Senha: %s\n", pesquisa->senha);
}
}
}
void excluir(celula *p){
	int entrou=0;
	celula *busca, *anterior, *propria;
	busca = (celula *) malloc(sizeof(celula));
	printf("Informe o login que deseja excluir: ");
	scanf("%s", busca->login);
	
for(anterior = p, propria = p->prox ; propria ; anterior = anterior->prox, propria = propria->prox){
if(strcmp(propria->login, busca->login)== 0){
anterior->prox = propria->prox;
free(propria);
entrou++;
printf("Login excluido com sucesso\n");
}
	}

	if(entrou==0){
		printf("Login nao encontrado!\n");
	}	
}
void modificar_senha(celula *p){
	celula *busca, *encontrar;
	char confirmacao[30];
	
	busca = (celula *) malloc(sizeof(celula));
	printf("Informe o login que modificar a senha: ");
	scanf("%s", busca->login);
	
	for(encontrar = p->prox; strcmp(busca->login, encontrar->login)!= 0; encontrar = encontrar->prox);
	
	printf("Digite a senha atual: ");
	scanf("%s", confirmacao);
	if(strcmp(confirmacao, encontrar->senha)==0){
	printf("Digite a nova senha: ");
	scanf("%s", encontrar->senha);
	printf("Senha modificada com sucesso!\n");
}
else {
	printf("Senha atual incorreta!\n");
}		
}

