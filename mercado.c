#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produto{
	int codigo;
	char nome[30];
	float valor;
	int quantidade;
	struct produto *prox;
};
typedef struct produto produto;
struct produto* cria_lista();
void cadastrar(produto * p);
void mostrar(produto * p);
void save(produto * p);
void start(produto * p);
void venda(produto * p, float *l);
void excluir(produto *p, int cod);
void save_lucro(float lucro);
float start_lucro( );
int main( ){
produto *lista_de_produtos;
lista_de_produtos = cria_lista( );
start(lista_de_produtos);
int op;
float lucro;
lucro = start_lucro();
for(;;){
	printf(" MERCADO DO ALEJANDRO\n");
	printf("1)Cadastrar um produto\n");
	printf("2)Mostrar todos produtos\n");
	printf("3)Venda\n");
	printf("4)Lucro atual\n");
	printf("5)Gerar backup do lucro\n");
	printf("6)Sair\n");
	scanf("%d", &op);
	switch (op){
		case 1:
		cadastrar(lista_de_produtos);
		break;
		case 2:
		mostrar(lista_de_produtos);
		break;
		case 3:
		venda(lista_de_produtos, &lucro);
		break;
		case 4:
		printf("Lucro atual: R$ %.2f\n", lucro);
		break;
		case 5:
		save_lucro(lucro);
		break;
		case 6:
		save(lista_de_produtos);
		exit(0);
		break;
	}
}	
	return 0;
}
struct produto* cria_lista( ){
	produto *start;
	start = (produto *)malloc(sizeof(produto));
	start->prox = NULL;
	return start;
}
void cadastrar(produto * p){
	produto *busca, *nova;
	
	nova = (produto *)malloc(sizeof(produto));
	printf("Codigo do produto: ");
	scanf("%d", &nova->codigo);
	printf("Nome do produto: ");
	scanf("%s", nova->nome);
	printf("Valor: ");
	scanf("%f", &nova->valor);
	printf("Quantidade: ");
	scanf("%d", &nova->quantidade);
	for(busca = p ; busca->prox != NULL && busca->prox->codigo<nova->codigo; busca = busca->prox);
	nova->prox = busca->prox;
	busca->prox = nova;
}
void mostrar(produto * p){	
	produto *i;
	
	for(i = p->prox; i != NULL; i = i->prox){
	printf("Codigo: %d\n", i->codigo);
	printf("Nome do produto: %s\n", i->nome);
	printf("Valor: %.2f\n", i->valor);
	printf("Quantidade: %d\n", i->quantidade);
}	
}
void save(produto * p){
	produto *i;
	FILE *arquivo;
	arquivo = fopen("database.txt", "w");
	
	for(i = p->prox ; i!= NULL; i = i->prox){
	fprintf(arquivo,"%d\n", i->codigo);
	fprintf(arquivo,"%s\n", i->nome);
	fprintf(arquivo,"%f\n", i->valor);
	fprintf(arquivo,"%d\n", i->quantidade);
}
fclose(arquivo);
}
void start(produto * p){
	produto *busca, *nova;
	char lixo;
	FILE *arquivo;
	arquivo = fopen("database.txt", "r");
	nova = (produto *)malloc(sizeof(produto));
	fscanf(arquivo, "%d", &nova->codigo);
	while(!feof(arquivo)){
	fscanf(arquivo, "%s", nova->nome);
	fscanf(arquivo, "%c", &lixo);
	fscanf(arquivo, "%f", &nova->valor);
	fscanf(arquivo, "%d", &nova->quantidade);
	for(busca = p; busca->prox != NULL; busca=busca->prox);
	busca->prox = nova;
	nova->prox = NULL;
	nova = (produto *)malloc(sizeof(produto));
	fscanf(arquivo, "%d", &nova->codigo);
}
fclose(arquivo);
}
void venda(produto * p, float *l){
	int cod,quantidade,entrou=0;
	produto *i;
	printf("Digite o cod do produto: ");
	scanf("%d", &cod);
	for(i = p->prox; i != NULL; i=i->prox){
		if(i->codigo == cod){
	printf("Quantidade: ");
	scanf("%d", &quantidade);
	if(quantidade <= i->quantidade){
		i->quantidade = i->quantidade - quantidade;
		(*l) = ((*l) + (quantidade * i->valor));
		printf("Venda realidada com sucesso!\n");
		entrou++;
		if(i->quantidade == 0){
			excluir(p,i->codigo);
		}
	}
	else{
		printf("Quantidade insuficiente\n");
	}
}
}
if(entrou==0){	
	printf("Codigo nao registrado!");
}
}
void excluir(produto *p, int cod){
	produto *i, *j;
	
	for(i=p,j=p->prox; j != NULL; i=i->prox,j=j->prox){
	if(j->codigo == cod){	
	i->prox = j->prox;
	free(j);
}
}
}
void save_lucro (float lucro){
	FILE *arquivo;
	arquivo = fopen("lucro.bak", "wb");
	fwrite(&lucro, sizeof(float),1,arquivo);

}
float start_lucro( ){
	FILE *arquivo;
	float l;
	arquivo = fopen("lucro.bak", "rb");
	fread(&l, sizeof(float),1,arquivo);
	
	return l;
}
