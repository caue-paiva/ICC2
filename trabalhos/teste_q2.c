
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define N 8
#define INDEX_N 4

const int RANGE = (N/INDEX_N); //constante do range que cada indicide ira segurar

typedef struct {
  int arr[N/INDEX_N]; //vetor dentro de cada indice da lista indexada
  int max_elemento; //maior elemento daquele indice (dentro daquele range)
} sublista;

void quick_sort(int* arr, int ini, int fim){ //quick sort padrao
    if(ini >= fim){return;}
    int pivo = arr[(ini+fim)/2];
    int i = ini;
    int j = fim;

    while(i <= j){
      while(arr[j] > pivo)
            j--;
      while(arr[i] < pivo)
            i++;

      if(i <= j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
      }
    }

    quick_sort(arr,ini,j);
    quick_sort(arr,i,fim);
}

sublista* cria_lista_indexada(int arr_sequencial[]){
      sublista* array_indexado = (sublista*) malloc(sizeof(sublista)* INDEX_N); //maloca uma lista de structs que representam os indexes com um range de números
         if(!array_indexado)
            exit(1);

      int indice_externo = -1;
      for (int i = 0 ; i < N; i++){  //roda por todo o arrayy original
         if(i%(RANGE) == 0){  //se ele chegar num multiplo do range(200,400) ele aumenta o index da lista indexada
            indice_externo++; 
            int index_maior_elemento = ((RANGE) * (indice_externo +1)) - 1; //index do maior elemento (ex 199, 399...)
            sublista indice = {.max_elemento = arr_sequencial[index_maior_elemento]};  //cria uma struct sublista e inicia o max elemento 
            array_indexado[indice_externo] = indice; //coloca essa struct num array de structs
         }
         array_indexado[indice_externo].arr[i%RANGE] = arr_sequencial[i];  //copia o array normal na lista indexada
      }
      return array_indexado;
}

int busca_indexada(sublista* lista_indices, int buscado){
    int range_certo = -1;
   // printf("entrou busca indexada \n");
    for(int i =0 ; i < INDEX_N ; i++){
        if(lista_indices[i].max_elemento >= buscado){ //acha o index com o range certo
            range_certo = i;
            break; 
        }
    }
    if(range_certo == -1) //se o range certo não existir ele da return -1, que significa que o index n existe
       return -1;
    sublista lista_certa = lista_indices[range_certo];
    for (int i = 0 ; i < RANGE; i++){
         if(lista_certa.arr[i] == buscado)
            return range_certo;
    }
    return -1;
}

int busca_tradiciona(int arr_sequencial [], int buscado){
    for(int i = 0; i < N; i++){
        if(arr_sequencial[i] == buscado){
            return i; //busca todo o array
        }
    }
    return -1;
}

int main(){
  int arr[N] = {1,7,9,17,82,1,5,8};
 
 
  quick_sort(arr,0,N-1); //quick sort no vetor

  sublista* lista_index = cria_lista_indexada(arr); //cria lista indexada e retorna um ponteiro para essa struct
 

  float inicial_busca_index = clock(); //msm coisa com a busca indexada
  for (int i =0 ; i < N; i++){
        int valor = arr[i];
        if (busca_indexada(lista_index,valor) == -1) //func de busca indexada com ranges
            printf("erro ");  
  }
  float final_busca_index = clock();

  printf("busca index levou %f segundos \n", (final_busca_index - inicial_busca_index)/CLOCKS_PER_SEC);
  
  free(lista_index); //libera memória alocada para a lista indexada
}

/*Resultados da comparação

busca indexada levou 0.00

*/