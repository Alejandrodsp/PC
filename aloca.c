#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n); 
void sorteia_valores(int *sorteio, int n); 
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns); 

int main(void)
{
	int i, aux = 0, *aposta, na, ns, *sorteio, *hits;
	ns = 20;
 printf("Informe quantos numeros deseja apostar: ");
 scanf("%d", &na);
 while(na<0 || na>20){
	 printf("Nao e possivel apostar mais que 20 numeros, por favor informe quantos numeros deseja apostar: ");
	 scanf("%d", &na); 
 }
	aposta = (int *)malloc (na * sizeof(int));
	sorteio = (int *)malloc (ns * sizeof(int));

	ler_aposta(aposta, na);
	sorteia_valores(sorteio, ns);
	compara_aposta(aposta, sorteio, hits, na, ns);

	printf("Seus acertos foram : \n");

	if( hits[0] < 101 && hits[0] > -1 )
		for( i = 0; hits[i] ; i++ )
			if( hits[i] < 101 && hits[i] > -1 )
				printf("%d, ", hits[i]);	
	if( aux <= 0 ) 
		printf("\tNem um =(\n");

	free(aposta);
	free(sorteio);
	free(hits);
	return 0;
}

void ler_aposta(int *aposta, int n)
{
	int i = 0;

	printf("Informe os numeros que deseja apostar: ");
	for( ; i < n ; i++ ){
		scanf("%d", &aposta[i]);
		while( aposta[i] > 101 || aposta[i] < -1 )
			scanf("%d", &aposta[i]);
	}
} 

void sorteia_valores(int *sorteio, int n)
{
	int i = 0;


	printf("Numeros sorteados : \n");
	srand(time(NULL));
	for( ; i < n ; i++ ){
		
		sorteio[i] = rand() % 100;
		printf("%d ", sorteio[i]);
	}
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
	int i = 0;

	qtdacertos  = (int *)malloc(sizeof(int));
	printf("\n");

	for( ; i < na ; i++ )
		if( aposta[i] == sorteio[i] ){
			qtdacertos[i] = aposta[i];
			qtdacertos  = (int *)realloc(qtdacertos, (i+1) * sizeof(int));
		}
} 
