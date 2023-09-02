#include "stdlib.h"
#include "stdio.h"


struct cel {
    int conteudo;
    struct cel *prox;
};

typedef struct cel celula;

void imprime(celula* ini){

    for (celula* p = ini; p != NULL; p = p->prox)
    {
       printf("% d ", p->conteudo);
    }
    
}


celula* preenche(int n){

    celula* antiga = (celula*) malloc(sizeof(celula));
    int content;
    int flag_start =1;

   for (int i = 0; i < n; i++)
   {   
        
       if (flag_start){
         celula* novo = (celula*) malloc(sizeof(celula));
         scanf("%d",&content);
         antiga->conteudo = content;
         antiga->prox = novo; 
         flag_start = 0 
       } else {
         scanf("%d",&content);
          celula* novo2 = (celula*) malloc(sizeof(celula));
          novo
         

       }
       
       if (novo==NULL){exit(1);}    
    
       scanf("%d", &(novo->conteudo));
       novo->prox == NULL;

       antiga->prox == novo;

   }
   
   
      
}


celula* locate(celula*ini, int target){
    
   for (celula* p = ini; p != NULL; p = p->prox){
           if (p->conteudo == target){
            return p;
           }
   }

   return NULL;
}


void modifica(celula*p, int n){

     for (celula* p = ini; p != NULL; p = p->prox){
         if((p->conteudo <= n) && (p->prox->conteudo => n)){

              celula* novo = (celula*) malloc(sizeof(celula));
              if(novo == NULL){exit(1);}
              novo->prox = p->prox;
              p->prox = novo;
              novo->conteudo = n;
              break;                          
         }
     }

}


int main(){

celula c;
celula *p;

preenche(p, 5);

imprime(p);




}