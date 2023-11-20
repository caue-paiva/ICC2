#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define BUCKET_SIZE 10
#define EMPTY_VALUE_HASHTABLE -181871
#define REMOVED_VAR_HASHTABLE -981972

typedef struct {
   int lista[BUCKET_SIZE];
   int num_elem;
} hashtable;

hashtable* hashtable_criar(){
   hashtable* hash1 = (hashtable*) malloc(sizeof(hashtable));
         if(!hash1)
            exit(1);
   for (int i = 0; i < BUCKET_SIZE; i++){
      hash1->lista[i] = EMPTY_VALUE_HASHTABLE;
   }
   hash1->num_elem = 0;
   return hash1;
}

bool hashtable_inserir(hashtable* hash1, int elemento){
    int hash_val_atual;
    for (int i = 0; i < BUCKET_SIZE; i++){
        hash_val_atual = (elemento + i)%BUCKET_SIZE;
        
        if(hash1->lista[hash_val_atual] == EMPTY_VALUE_HASHTABLE || hash1->lista[hash_val_atual] == REMOVED_VAR_HASHTABLE){
           hash1->lista[hash_val_atual] = elemento;
           (hash1->num_elem)++;
           return true;
        }
    }
    return false;
}

int hashtable_busca(hashtable* hash1, int elemento ){
   int hash_val_atual;
      for (int i = 0; i < BUCKET_SIZE; i++){
        hash_val_atual = (elemento + i)%BUCKET_SIZE;
        if(hash1->lista[hash_val_atual] == EMPTY_VALUE_HASHTABLE)
           return false;
        if (hash1->lista[hash_val_atual] == elemento)
          return true;
    }
    return false;
}

bool hashtable_remover(hashtable*hash1, int elemento){
  int hash_val_atual;
      for (int i = 0; i < BUCKET_SIZE; i++){
        hash_val_atual = (elemento + i)%BUCKET_SIZE;
        if(hash1->lista[hash_val_atual] == EMPTY_VALUE_HASHTABLE)
           return false;
        if (hash1->lista[hash_val_atual] == elemento){
           hash1->lista[hash_val_atual] = REMOVED_VAR_HASHTABLE;
           (hash1->num_elem)--;
           return true;
        }
          
    }
    return false;
}

void hashtable_printar(hashtable* hash){
   for (int i = 0; i < BUCKET_SIZE; i++){
      printf("%d ", hash->lista[i]);
   }
   printf("\n");
}

int hashtable_num_elem(hashtable* hash){
    return hash->num_elem;
}

int main(){

   hashtable* hash1 = hashtable_criar();
   hashtable_inserir(hash1,3);
   hashtable_inserir(hash1,5);
   hashtable_inserir(hash1,6);
   hashtable_inserir(hash1,25);
   hashtable_printar(hash1);
   printf("buscando o elem %d , resultado %d \n\n", 25 , hashtable_busca(hash1,25));
   hashtable_remover(hash1,6);
   hashtable_printar(hash1);
   printf("buscando o elem %d , resultado %d \n\n", 25 , hashtable_busca(hash1,25));
  // printf("buscando o elem %d , resultado %d \n\n", 10 , hashtable_busca(hash1,10));

}