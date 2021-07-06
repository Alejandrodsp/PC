#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct end {
	char nome[100];
	char rua[100];
	char cidade[100];
	char estado[100];
	unsigned long int cep;
	struct end *prox;
} *info;
typedef struct end celula;
end *cria_lista(void);
void insere(void);
void apaga(void);
int busca_pelo_nome(char nome[100]);
void apaga_pelo_nome(void);
void imprime(void);
void grava_arq_texto(void);
void le_arq_texto(void);
void grava_arq_binario(void);
void le_arq_binario(void);
int menu(void);
int livre(void);
void ler_string(char palavra[100], int tamanho);


int main()
{
	int escolha;
	celula *ini;

	ini = cria_lista();
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere();
			break;
		case 2:
			apaga();
			break;
		case 3:
			apaga_pelo_nome();
			break;
		case 4:
			imprime();
			break;
		case 5: 
			grava_arq_texto();
			break;
		case 6: 
			le_arq_texto();
			break;
		case 7: 
			grava_arq_binario();
			break;
		case 8: 
			le_arq_binario();
			break;
		case 9:
			exit(0);
			break;
		}
	}
	return 0;
}
celula cria_lista(void)
{
	end *head;
	head = (end *)malloc(sizeof(end));
	head->prox=NULL;
	return head;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome pela posicao\n");
		printf("\t 3. Excluir um nome pelo nome\n");
		printf("\t 4. Listar o arquivo\n");
		printf("\t 5. Gravar arquivo texto\n");
		printf("\t 6. Ler arquivo texto\n");
		printf("\t 7. Gravar arquivo binario\n");
		printf("\t 8. Ler arquivo binario\n");
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

void insere(void)
{
	int posicao;

	posicao = livre();
	if (posicao == -1) {
		printf("\nEstrutura Cheia!!");
		return;
	}

	printf("-- Registro %d:\n", posicao);
	printf("\t Nome: ");
	ler_string(info[posicao].nome, 100);
	printf("\t Rua: ");
	ler_string(info[posicao].rua, 100);
	printf("\t Cidade: ");
	ler_string(info[posicao].cidade, 100);
	printf("\t Estado: ");
	ler_string(info[posicao].estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &info[posicao].cep);
}

int livre(void)
{
	int i;
	for (i = 0; info[i].nome[0] && i < MAX; i++) ;
	if (i == MAX)
		return -1;
	return i;
}

void apaga(void)
{
	int posicao;

	printf("Número do Registro: ");
	scanf("%d", &posicao);

	if (posicao >= 0 && posicao < MAX)
		info[posicao].nome[0] = '\0';
}

int busca_pelo_nome(char nome[100]) {
	int i;
	for (i = 0; i < MAX; i++) {
		if (strcmp(nome, info[i].nome) == 0) {
			return i;
		}
	}
	return -1;
}

void apaga_pelo_nome(void)
{
	int posicao;
	char nome[100], resposta;

	printf("Nome: ");
	ler_string(nome, 100);

	posicao = busca_pelo_nome(nome);

	if (posicao == -1)
		printf("Nome não encontrado.\n");
	else {
		printf("Você quer mesmo remover %s? (S/N)\n", nome);
		scanf("%c", &resposta);
		if (resposta == 'S' || resposta == 's') {
			info[posicao].nome[0]='\0';
			printf("Nome removido.\n");
		} else {
			printf("Nome não removido.\n");
		}
	}
}

void imprime(void)
{
	int i;

	for (i = 0; i < MAX; i++)
		if (info[i].nome[0] != '\0') {
			printf("-- Registro %d:\n", i);
			printf("\t Nome: %s", info[i].nome);
			printf("\t Rua: %s", info[i].rua);
			printf("\t Cidade: %s", info[i].cidade);
			printf("\t Estado: %s\n", info[i].estado);
			printf("\t CEP: %lu\n", info[i].cep);
		}
}


void grava_arq_texto(void)
{
	int i;
	FILE *arquivo;

	arquivo=fopen("database.txt", "w");
	for (i = 0; i < MAX; i++)
		if (info[i].nome[0] != '\0') {
			fprintf(arquivo,"%d\n", i);
			fprintf(arquivo,"%s\n", info[i].nome);
			fprintf(arquivo,"%s\n", info[i].rua);
			fprintf(arquivo,"%s\n", info[i].cidade);
			fprintf(arquivo,"%s\n", info[i].estado);
			fprintf(arquivo,"%lu\n", info[i].cep);
		}
	fclose(arquivo);
}

void le_arq_texto(void)
{
	int i;
	char lixo;
	FILE *arquivo;

	arquivo=fopen("database.txt", "r");
	cria_lista();
	
	while(!feof(arquivo)) {
		fscanf(arquivo,"%d", &i);
		fscanf(arquivo,"%c", &lixo);
		fscanf(arquivo,"%[^\n]s", info[i].nome);
		fscanf(arquivo,"%c", &lixo);
		fscanf(arquivo,"%[^\n]s", info[i].rua);
		fscanf(arquivo,"%c", &lixo);
		fscanf(arquivo,"%[^\n]s", info[i].cidade);
		fscanf(arquivo,"%c", &lixo);
		fscanf(arquivo,"%[^\n]s", info[i].estado);
		fscanf(arquivo,"%c", &lixo);
		fscanf(arquivo,"%lu", &info[i].cep);
		fscanf(arquivo,"%c", &lixo);
	}
	
	fclose(arquivo);
}

void grava_arq_binario(void)
{
	int i;
	FILE *arquivo;

	arquivo=fopen("database.dat", "wb");
	//fwrite(info, sizeof(struct end), MAX, arquivo);

  	for (i = 0; i < MAX; i++)
		if (info[i].nome[0] != '\0') {
			fwrite(&i, sizeof(int), 1, arquivo);
			fwrite(&info[i], sizeof(struct end), 1, arquivo);
			//fwrite(info[i].nome, sizeof(char), 100, arquivo);
			//fwrite(info[i].rua, sizeof(char), 100, arquivo);
			//fwrite(info[i].cidade, sizeof(char), 100, arquivo);
			//fwrite(info[i].estado, sizeof(char), 100, arquivo);
			//fwrite(&info[i].cep, sizeof(unsigned long int), 1, arquivo);
		}

	fclose(arquivo);
}

void le_arq_binario(void)
{
	int i;
	FILE *arquivo;

	arquivo=fopen("database.dat", "rb");
	cria_lista();
	
	//fread(info, sizeof(struct end), MAX, arquivo);
	
	while(!feof(arquivo)) {
			fread(&i, sizeof(int), 1, arquivo);
			fread(&info[i], sizeof(struct end), 1, arquivo);
			//fread(info[i].nome, sizeof(char), 100, arquivo);
			//fread(info[i].rua, sizeof(char), 100, arquivo);
			//fread(info[i].cidade, sizeof(char), 100, arquivo);
			//fread(info[i].estado, sizeof(char), 100, arquivo);
			//fread(&info[i].cep, sizeof(unsigned long int), 1, arquivo);
		}
	
	fclose(arquivo);
}
