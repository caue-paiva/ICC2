#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

struct _celula {
	int v;
	struct _celula * proximo;
};

typedef struct _celula celula_t;

celula_t * criar_lista_encadeada(int v);
void adicionar_elemento_lista(celula_t* head, int v);
void printar_lista(celula_t*head);
void modifica(celula_t*head, int n);
void inverte(celula_t* C3);

void merge(int v1[], int n1, int v2[], int n2, int v3[]);

int main(int argc, char ** argv)
{

    int N1, N2;
	
	scanf("%d", &N1);
	 celula_t* C1;
	for (int i = 0; i < N1; i++)
	{   int temp;		
		scanf("%d", &temp);
		
		if (i==0){
             C1 = criar_lista_encadeada(temp);
		}else {
			 adicionar_elemento_lista(C1, temp);
		}
	}

	scanf("%d", &N2);
	celula_t* C2;
	for (int i = 0; i < N2; i++)
	{   int temp;		
		scanf("%d", &temp);
		
		if (i==0){
            C2 = criar_lista_encadeada(temp);
		}else {
			 adicionar_elemento_lista(C2, temp);
		}
	}
	

	int v3[N1+N2];

	int menor;
	if (N1> N2){ 
		menor = N2;
	} else{ menor = N1;}

	//printar_lista(C1);
	//printf("\n\n");
	//printar_lista(C2);
	//printf("\n\n");

   celula_t * C3; 
   celula_t * i = C1; celula_t * j=C2;
   for (;i!=NULL || j!=NULL;){
		//printf(" pointer i %p   pointer j %p \n", i,j);
		if(i==NULL){
			for(celula_t * k = j ; k!=NULL; k=k->proximo){
				adicionar_elemento_lista(C3, k->v);
				//printf(" i NULL add elemento %d \n", k->v);
			}
			break;
		}
		if(j==NULL){
			for(celula_t * k = i ; k!=NULL; k=k->proximo){
				adicionar_elemento_lista(C3, k->v);
				//printf("j NULL  add elemento %d \n", k->v);
			}
			break;
		}
		if(i==C1 && j==C2){
			if(i->v < j->v){
				C3=criar_lista_encadeada(i->v);
				//printf("criar lista com i, numero %d\n", i->v);
				i=i->proximo;
			}
			else{
				C3=criar_lista_encadeada(j->v);
				//printf("criar lista com j, numero %d\n", j->v);
				j=j->proximo;
			}
		}
		else{
			if(i->v < j->v){
				adicionar_elemento_lista(C3, i->v);
				//printf("add elemento i, num %d \n", i->v);
				i=i->proximo;
			}
			else{
				adicionar_elemento_lista(C3, j->v);
				//printf("add elemento j, num %d \n", j->v);
				j=j->proximo;
			}
		}
		//printf(" loop \n");printf(" pointer i %p   pointer j %p \n", i,j);
   }


	printar_lista(C3);

	

	inverte(C3);

	printar_lista(C3);

	//printar_lista(C4);
}

void inverte(celula_t* C3){
      printf("\ninverte %d \n ", C3->v);
       celula_t* C4;
	   if(C3->proximo==NULL){
		printf("NULL");
		  C4 =  criar_lista_encadeada(C3->v);
		 
		  return;
	   }
	   inverte(C3->proximo);
	   adicionar_elemento_lista(C4, C3->v);

	   //C3 = C4;
}

/*void merge(celula_t* v1, int n1, celula_t* v2, int n2, celula_t* v3)
{
	if (n1 == n2) if (n1 == 0) return;
	
	int temp;
	if (n1 >0 && n2> 0) {
		if (v1[n1-1] >= v2[n2-1]) { // se o ultimo elemento alterado mais p esquerda de v1 for maior igual que o de v2
	 		temp = v1[n1-1];
			n1--;
		}
		else {
			temp = v2[n2-1];
			n2--;
		}

	}
	else if (n1 <= 0) {
		temp = v2[n2-1];
		n2--;
	}
	else {
		temp = v1[n1-1];
		n1--;
	}
	
	v3[n1+n2] = temp;
	merge(v1, n1, v2, n2, v3);
}*/



celula_t * criar_lista_encadeada(int v) {
	celula_t * lista = (celula_t *) calloc ( 1, sizeof(celula_t));
	assert(lista != NULL);

	lista->v = v;
	lista->proximo = NULL;
	return lista;
}

void adicionar_elemento_lista(celula_t* head, int v) {
	if (head->proximo == NULL) {
		celula_t * proximo = (celula_t*)calloc(1,sizeof(celula_t));
		assert(proximo != NULL);
		proximo->v = v;

		head->proximo = proximo;
		
	}
	else adicionar_elemento_lista(head->proximo, v);
}

void printar_lista(celula_t*head) {
	if (head->proximo == NULL) {
		printf("%d ", head->v);
		return;
	}

	printf("%d ", head->v);
	printar_lista(head->proximo);

}

celula_t * locate(celula_t* head, int target) {
	for (celula_t * p = head; p!= NULL; p = p->proximo) {
		if (p->v == target) return p;
	}
	return NULL;
}

void modifica(celula_t*head, int n){

     for (celula_t* p = head; p != NULL; p = p->proximo){
         if((p->v <= n) && (p->proximo->v >= n)){
                      
              celula_t* novo = (celula_t*) malloc(sizeof(celula_t));
              if(novo == NULL){exit(1);}
              novo->proximo = p->proximo;
              p->proximo = novo;
              novo->v = n;
              break;                          
         }
     }

}

	
