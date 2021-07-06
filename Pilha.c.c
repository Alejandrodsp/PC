//AED1 - Monitoria
//Tarefa Prática
//Pilha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char equip[31];
	struct node *next;
};

struct node *newNode();
void printStack(struct node *head);
void push(struct node *head, char *equip);
struct node *pop(struct node *head);
char *top(struct node *head);
int isEmpty(struct node *head);

int main(){
	struct node *head = newNode();
	head->next = NULL;
	int option;
	char pushEquip[31];
	struct node *popEquip;
	
	do{
		printf("1 - Push\n2 - Pop\n3 - Print Stack\n4 - Top\n0 - Exit\n");
		scanf("%d", &option);
		getchar();
		
		switch(option){
			case 1:
				printf("Equip: ");
				fgets(pushEquip, 31, stdin);
				printf("\n");
				push(head, pushEquip);
				break;
				
			case 2:
				if((popEquip = pop(head))){
					printf("%s\n\n", popEquip->equip);
					free(popEquip);
				}
				break;
			
			case 3:
				printStack(head);
				printf("\n");
				break;
			
			case 4:
				printf("%s\n\n", top(head));
				break;
				
			default:
				break;
		}
		
	} while(option != 0);
	
	free(head);
	return 0;
}


//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
void push(struct node *head, char *equip){
	struct node *nova,*busca;
	for(busca = head ; busca->next != NULL; busca = busca->next);

	nova = newNode();
	strcpy(nova->equip,equip);
	nova->next = NULL;
	busca->next = nova;
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
struct node *pop(struct node *head){
struct node *busca,*morta;
	if(!isEmpty(head)){
	for(busca = head , morta = head->next; morta->next != NULL;morta=morta->next, busca = busca->next);

	busca->next = morta->next;
	return morta;
	}
	else{
		return NULL;
	}
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
char *top(struct node *head){
	struct node *busca;
	if(!isEmpty(head)){
for(busca = head ; busca->next != NULL; busca = busca->next);

return busca->equip; 
}
else{
	return "Pilha vazia!";
}
}

int isEmpty(struct node *head){
	if(head->next == NULL)
		return 1;
	else return 0;
}

void printStack(struct node *head){
	if(head->next == NULL)
		printf("Pilha Vazia\n");
	
	struct node *printer = head->next;
	
	while(printer != NULL){
		printf("%s", printer->equip);
		printer = printer->next;
	}
}

struct node *newNode(){
	struct node *new = malloc (sizeof (struct node));
	return new;
}
