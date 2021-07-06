#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct end {
	char nome[100];
	char rua[100];
	char cidade[100];
	char estado[100];
	unsigned long int cep;
	struct end *prox;
};
typedef struct end end;
struct end* cria_lista(void);
void insere(end *p);
void apaga(end *p);
void imprime(end *p);
void grava_txt(end *p);
void le_txt(end *p);
void grava_bin(end *p);
void le_bin(end *p);
void limpa(end *p);
int menu(void);

void ler_string(char palavra[100], int tamanho);

int main()
{
	end *head;
	int escolha;

	head = cria_lista();
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere(head);
			break;
		case 2:
			apaga(head);
			break;
		case 3:
			imprime(head);
			break;
		case 4:
		grava_txt(head);
		break;
		case 5:
		limpa(head);
		head = cria_lista();
		le_txt(head);
		break;
		case 6:
		grava_bin(head);
		break;
		case 7:
		limpa(head);
		head = cria_lista();
		le_bin(head);
		break;
		case 8:
		limpa(head);
		head = cria_lista();
		break;
		case 9:
		exit(0);
		break;
		}
	}
	return 0;
}

struct end* cria_lista(void)
{
	end *start;
	start = (end*)malloc(sizeof(end));
	start->prox = NULL;
	
	return start;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Mostrar lista\n");
		printf("\t 4. Gravar em arquivo txt\n");
		printf("\t 5. Le arquivo txt\n");
		printf("\t 6. Gravar em arquivo bin\n");
		printf("\t 7. Le arquivo bin\n");
		printf("\t 8. Limpa lista\n");
		printf("\t 9. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 9);
	getchar();
	return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}

}

void insere(end *p)
{
	end *busca, *nova;
	nova = (end *)malloc(sizeof(end));
	printf("\t Nome: ");
	ler_string(nova->nome, 100);
	printf("\t Rua: ");
	ler_string(nova->rua, 100);
	printf("\t Cidade: ");
	ler_string(nova->cidade, 100);
	printf("\t Estado: ");
	ler_string(nova->estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &nova->cep);
	
	for(busca = p; busca->prox != NULL && strcmp(busca->prox->nome,nova->nome)<0; busca= busca->prox);
	nova->prox = busca->prox;
	busca->prox = nova;
}


void apaga(end *p)
{
	end *i, *j;
	char nome[30];
	printf("Digite o nome que deseja apagar: ");
	scanf("%[^\n]s", nome);
	for(i=p,j=p->prox; j != NULL; i=i->prox,j=j->prox){
		if(strcmp(nome,j->nome)==0){
			i->prox = j->prox;
			free(j);
		}
	}
}

void imprime(end *p)
{
	end *i;

	for (i = p->prox; i ; i=i->prox){

			printf("\t Nome: %s\n", i->nome);
			printf("\t Rua: %s\n", i->rua);
			printf("\t Cidade: %s\n", i->cidade);
			printf("\t Estado: %s\n", i->estado);
			printf("\t CEP: %lu\n", i->cep);
		}
}
void grava_txt(end *p){
	FILE *arquivo;
	arquivo = fopen("database.txt", "w");
	end *i;
	for(i=p->prox; i!= NULL; i=i->prox){
			fprintf(arquivo,"%s\n", i->nome);
			fprintf(arquivo,"%s\n", i->rua);
			fprintf(arquivo,"%s\n", i->cidade);
			fprintf(arquivo,"%s\n", i->estado);
			fprintf(arquivo,"%lu\n", i->cep);
}
fclose(arquivo);
}
void le_txt(end *p){
	FILE *arquivo;
	arquivo = fopen("database.txt", "r");
	end *i,*nova;
	char lixo;
	
	nova = (end*)malloc(sizeof(end));
	fscanf(arquivo, "%[^\n]s", nova->nome);
	fscanf(arquivo, "%c", &lixo);
	while(!feof(arquivo)){
	fscanf(arquivo, "%[^\n]s", nova->rua);
	fscanf(arquivo, "%c", &lixo);
	fscanf(arquivo, "%[^\n]s", nova->cidade);
	fscanf(arquivo, "%c", &lixo);
	fscanf(arquivo, "%[^\n]s", nova->estado);
	fscanf(arquivo, "%c", &lixo);
	fscanf(arquivo, "%lu", &nova->cep);
	fscanf(arquivo, "%c", &lixo);
	for(i=p; i->prox != NULL; i=i->prox);
	i->prox = nova;
	nova->prox = NULL;
	nova = (end*)malloc(sizeof(end));
	fscanf(arquivo, "%[^\n]s", nova->nome);
	fscanf(arquivo, "%c", &lixo);
}
	fclose(arquivo);
}
void grava_bin(end *p){
	FILE *arquivo;
	arquivo = fopen("database.dat", "wb");
	end *i;
	for(i=p->prox; i!= NULL; i=i->prox){
			fwrite(i->nome,sizeof(char),100,arquivo);
			fwrite(i->rua,sizeof(char),100,arquivo);
			fwrite(i->cidade,sizeof(char),100,arquivo);
			fwrite(i->estado,sizeof(char),100,arquivo);
			fwrite(&i->cep,sizeof(unsigned long int),1,arquivo);
}
fclose(arquivo);
}
void le_bin(end *p){
	FILE *arquivo;
	arquivo = fopen("database.dat", "rb");
	end *i,*nova;
	
	nova = (end*)malloc(sizeof(end));
	fread(nova->nome,sizeof(char),100,arquivo);
	while(!feof(arquivo)){
	fread(nova->rua,sizeof(char),100,arquivo);
	fread(nova->cidade,sizeof(char),100,arquivo);
	fread(nova->estado,sizeof(char),100,arquivo);
	fread(&nova->cep,sizeof(unsigned long int),1,arquivo);

	for(i=p; i->prox != NULL; i=i->prox);
	i->prox = nova;
	nova->prox = NULL;
	nova = (end*)malloc(sizeof(end));
	fread(nova->nome,sizeof(char),100,arquivo);
}
	fclose(arquivo);
}
void limpa(end *p){
	
	end *morta;

	while(p!=NULL){
	morta = p;
	p = p->prox;
	free(morta);
}	
}
