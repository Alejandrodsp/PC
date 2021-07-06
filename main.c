#include <stdio.h>
#include <stdlib.h>
 
struct loja{ 
    int codigo; 
    int estoque; 
    float valorCompra; 
    float margemLucro; 
    int vendas; 
}; 
  
struct no{ 
    struct loja c; 
    struct no* prox; 
}; 
 
void inserir(struct no** l, struct loja dta){ 
  struct no *busca, *nova;
  for(busca = *l; busca->prox != NULL; busca= busca->prox);
  
  nova = (struct no*)malloc(sizeof(struct no*));
  busca->prox = nova;
  nova->prox = NULL;
  nova->c = dta;
} 
  
int retirar(struct no** l, struct loja dta){ 
    struct no *i, *morta;
    for(i=(*l),morta=(*l)->prox; morta->c.codigo != dta.codigo; i=i->prox, morta=morta->prox);
    i->prox = morta->prox;
    free(morta);
    
    return 0;
    
} 
  
struct loja procurar(struct no** l, int d){ 
	struct loja erro;
	struct no *busca;

	for(busca = (*l)->prox; busca != NULL; busca = busca->prox){
		if(busca->c.codigo == d){
			return busca->c;
	
		}	
	}
	
		erro.codigo = 0;
		return erro;
	
} 
  
void atualizar(struct no** l, struct loja dta){ 
    struct no *busca;
    for(busca = (*l)->prox; busca->c.codigo != dta.codigo; busca = busca->prox);
    
    busca->c = dta;
} 
  
void save(struct no** l){ 
    FILE *file2; 
    file2 = fopen("estoque.bak", "w"); 
    struct no* aux; 
     
    for(aux = (*l)->prox; aux != NULL; aux=aux->prox){ 
        fprintf(file2, "%d,%d,%.2f,%.2f\n", aux->c.codigo, aux->c.estoque, aux->c.valorCompra, aux->c.margemLucro); 
    } 
    fclose(file2); 
} 
  
void gera(struct no** l){ 
    FILE *file3; 
    file3 = fopen("relatorio.txt", "w"); 
    struct no* aux; 
    float luc; 
     
    for(aux = (*l)->prox; aux != NULL; aux=aux->prox){ 
        luc = ((aux->c.margemLucro/100) * aux->c.valorCompra) * aux->c.vendas; 
        fprintf(file3, "%d,%d,%d,%.2f\n", aux->c.codigo, aux->c.estoque, aux->c.vendas, luc); 
    } 
    fclose(file3); 
} 
 
int main(){ 
    struct no *stok=NULL; 
    struct loja dta, cod; 
    FILE *file1; 
    int aux_while=1, v, est; 
    float val, luc; 
     stok = (struct no*)malloc(sizeof(struct no*));
     stok->prox = NULL;
     
    file1 = fopen("estoque.bak", "r"); 
     
    while(!feof(file1)){ //lê o arquivo .txt
        fscanf(file1, "%d,%d,%f,%f", &dta.codigo, &dta.estoque, &dta.valorCompra, &dta.margemLucro);
        dta.vendas = 0;
        inserir(&stok, dta);
    }
     
    fclose(file1); 
     
    while(aux_while != 0){ 
        char c; 
        printf("\nEscolha:\n(v): Venda de um produto.\n(a): Adicionar item ao estoque.\n(s): Salvar a lista.\n(r): Gerar relatorio de vendas.\n(x): Sair do programa\n"); 
        c = getchar(); 
 
        switch(c){ 
        case 'v' : 
             
            printf("\nRegistro de Venda\n"); 
            printf("Insira o codigo do produto: "); 
            scanf("%d", &v); 
                         
            cod = procurar(&stok,v); 
     
            if(cod.codigo != 0){ 
                if(cod.estoque == 0){ 
                    printf("Produto esgotado, retirando do estoque!\n"); 
                    retirar(&stok,cod); 
                } 
                else{ 
                    cod.estoque=cod.estoque-1; 
                    printf("Venda realizada!\n"); 
                    cod.vendas++; 
                    atualizar(&stok,cod); 
                    if(cod.estoque <= 0){ 
                        retirar(&stok,cod); 
                        printf("Produto esgotado, retirando do estoque!\n"); 
                    } 
                } 
            } 
            else printf("Codigo de produto inexistente ou duplicado!\n\n"); 
        break; 
     
        case 'a' : 
             
            printf("\nAdicionar ou atualizar produto\n"); 
            printf("\nInsira o codigo do produto: "); 
            scanf("%d", &v); 
            cod = procurar(&stok, v); 
            printf("Quantidade no estoque: "); 
            scanf("%d", &est); 
            printf("Valor de compra: "); 
            scanf("%f", &val); 
            printf("Porcentagem de lucro: "); 
            scanf("%f", &luc); 
             
            if(cod.codigo == 0){
            	dta.codigo = v; 
                dta.estoque = est; 
                dta.valorCompra = val; 
                dta.margemLucro = luc; 
                dta.vendas = 0; 
                inserir(&stok,dta); 
                printf("Adicionado com sucesso!\n"); 
            } 
            else{
                cod.estoque = est; 
                cod.valorCompra = val; 
                cod.margemLucro = luc; 
                atualizar(&stok,cod); 
                printf("Atualizado com sucesso!\n"); 
            }
             
           break; 
     
        case 's' : 
            save(&stok); 
        break; 
     
        case 'r' : 
            gera(&stok); 
        break; 

        case 'x' : 
            save(&stok); 
            gera(&stok); 
            aux_while = 0; 
        break; 
         
        default: 
            printf("Opcao Invalida!\n"); 
        } 
        getchar(); 
    } 
     
    return 0; 
} 
