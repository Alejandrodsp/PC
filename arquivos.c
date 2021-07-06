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
void salvar_txt(end *p);
void ler_txt(end *p);
void insere(end *p);
void listar(end *p);
void salvar_bin(end *p);
void ler_bin(end *p);
int main( ){
end *head;
head = (end *)malloc(sizeof(end));
head->prox = NULL;
int op;
for(;;){
	printf("1)Salvar txt\n");
	printf("2)Ler txt\n");
	printf("3)inserir\n");
	printf("4)Listar\n");
	printf("5)Salvar bin\n");
	printf("6)Ler bin\n");
	scanf("%d", &op);
	switch (op){
		case 1:
		salvar_txt(head);
		break;
		case 2:
		ler_txt(head);
		break;
		case 3:
		insere(head);
		break;
		case 4:
		listar(head);
		break;
		case 5:
		salvar_bin(head);
		break;
		case 6:
		ler_bin(head);
		break;
	}
}
	
	return 0;
}
void salvar_txt(end *p){
	end *i;
	FILE *arquivo;
	arquivo = fopen("database.txt", "w");
	
	for(i=p->prox; i!= NULL; i=i->prox){
	
		fprintf(arquivo,"%s\n",i->nome);
		fprintf(arquivo,"%s\n",i->rua);
		fprintf(arquivo,"%s\n",i->cidade);
		fprintf(arquivo,"%s\n",i->estado);
		fprintf(arquivo,"%lu\n",i->cep);
	
} 
	
fclose(arquivo);		
}
void ler_txt(end *p){
	end *i,*nova;
	char auxN[100];
	FILE *arquivo;
	arquivo = fopen("database.txt", "r");
	
	while(fscanf(arquivo, "%s", auxN)==1){
	
	for(i=p; i->prox!= NULL; i=i->prox);
	nova = (end *)malloc(sizeof(end));
	i->prox = nova;
	nova->prox = NULL;
	strcpy(nova->nome, auxN);
	fscanf(arquivo, "%s", nova->rua);
	fscanf(arquivo, "%s", nova->cidade);
	fscanf(arquivo, "%s", nova->estado);
	fscanf(arquivo, "%lu",&nova->cep);
	
}
	
fclose(arquivo);		
}
void insere(end *p){
	end *nova, *fim;

	for (fim = p; fim->prox != NULL; fim = fim->prox) ;

	nova = (end *) malloc(sizeof(end));

	printf("Nome: ");
	scanf("%s", nova->nome);
	printf("Rua: ");
	scanf("%s", nova->rua);
	printf("Cidade: ");
	scanf("%s", nova->cidade);
	printf("Estado: ");
	scanf("%s", nova->estado);
	printf("CEP: ");
	scanf("%lu", &nova->cep);
	fim->prox = nova;
	nova->prox = NULL;

}
void listar(end * p)
{
	end *i;

	for (i = p->prox; i != NULL; i = i->prox) {
		printf("\t Nome: %s\n", i->nome);
		printf("\t Rua: %s\n", i->rua);
		printf("\t Cidade: %s\n", i->cidade);
		printf("\t Estado: %s\n", i->estado);
		printf("\t CEP: %lu\n", i->cep);
	}
}
void salvar_bin(end *p){
	end *i;
	FILE *arquivo;
	arquivo = fopen("database.dat", "wb");
	
	for(i=p->prox; i!= NULL; i=i->prox){
	
		fwrite(i->nome,sizeof(char),100,arquivo);
		fwrite(i->rua,sizeof(char),100,arquivo);
		fwrite(i->cidade,sizeof(char),100,arquivo);
		fwrite(i->estado,sizeof(char),100,arquivo);
		fwrite(&i->cep,sizeof(unsigned long int),1,arquivo);
	
}
fclose(arquivo);
}
void ler_bin(end *p){
	end *i,*nova;
	char auxN[100];
	FILE *arquivo;
	arquivo = fopen("database.txt", "rb");
	
	while(fread(auxN,sizeof(char),100,arquivo)==100){
	for(i=p; i->prox!= NULL; i=i->prox);
	nova = (end *)malloc(sizeof(end));

	strcpy(nova->nome, auxN);
	fread(nova->rua,sizeof(char),100,arquivo);
	fread(nova->cidade,sizeof(char),100,arquivo);
	fread(nova->estado,sizeof(char),100,arquivo);
	fread(&nova->cep,sizeof(unsigned long int),1,arquivo);
	i->prox = nova;
	nova->prox = NULL;
	
}
fclose(arquivo);		
}
	
	
	
	
	
	
	
	
	
	
	
	

