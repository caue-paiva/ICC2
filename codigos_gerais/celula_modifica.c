#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct _celula {
	int v;
	struct _celula * proximo;
};

typedef struct _celula celula_t;

celula_t * criar_lista_encadeada(int v);
void adicionar_elemento_lista(celula_t* head, int v);
void printar_lista(celula_t*head);
void modifica(celula_t*head, int n);


int main(int argc, char ** argv) {
	
	celula_t* head = criar_lista_encadeada(1);

	adicionar_elemento_lista(head, 2);
	adicionar_elemento_lista(head, 4);
	
	printar_lista(head);

	printf("\n");

    modifica(head, 0);
    modifica(head, -1);
	modifica(head, 3);
    modifica(head, 6);
    modifica(head, 9);
    
	printar_lista(head);
}

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


void modifica(celula_t*head, int n){
     if (head->v > n){
        celula_t* novo = (celula_t*) malloc(sizeof(celula_t));
        if(novo == NULL){exit(1);}
        novo->proximo = head->proximo;
        novo->v = head->v;
        head->proximo = novo;
        head->v = n;
        return;
     }
     for (celula_t* p = head; p != NULL; p = p->proximo){
         
         if((p->v <= n)){
             if (p->proximo == NULL){
                 celula_t* novo = (celula_t*) malloc(sizeof(celula_t));
                 if(novo == NULL){exit(1);}
                 novo->proximo == p->proximo;
                 p->proximo = novo;
                novo->v = n;
                break;
             } else if (p->proximo->v >= n){

                celula_t* novo = (celula_t*) malloc(sizeof(celula_t));
                if(novo == NULL){exit(1);}
                novo->proximo = p->proximo;
                p->proximo = novo;
                novo->v = n;
                break;  
             }
                      
                                     
         }
     }

}
