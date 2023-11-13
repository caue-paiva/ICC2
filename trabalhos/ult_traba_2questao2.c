#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define N 10000
#define INDEX_N 50

const int RANGE = (N/INDEX_N);

typedef struct {
  int arr[N/INDEX_N];
  int max_elemento;
} sublista;

void quick_sort(int* arr, int ini, int fim){
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
      sublista* array_indexado = (sublista*) malloc(sizeof(sublista)* INDEX_N);
         if(!array_indexado)
            exit(1);

      int indice_externo= -1;
      for (int i =0 ; i < N; i++){
         if(i%(RANGE) == 0){
            indice_externo++; 
            int index_maior_elemento = ((RANGE) * (indice_externo +1)) - 1;
            sublista indice = {.max_elemento = arr_sequencial[index_maior_elemento]};
            array_indexado[indice_externo] = indice;
         }
         array_indexado[indice_externo].arr[i%RANGE] = arr_sequencial[i];
      }
      return array_indexado;
}

int busca_indexada(sublista* lista_indices, int buscado){
    int range_certo = -1;
   // printf("entrou busca indexada \n");
    for(int i =0 ; i < INDEX_N ; i++){
        if(lista_indices[i].max_elemento >= buscado){
            range_certo = i;
            break;
        }
    }
    if(range_certo == -1)
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
            return i;
        }
    }
    return -1;
}

int main(){
  int arr[N];

  for(int i =0 ; i < N; i++){
    arr[i] = rand()%N +1;
  }
  quick_sort(arr,0,N-1);

  sublista* lista_index = cria_lista_indexada(arr);
 
  float inicial_busca_trad = clock();
  for (int i =0 ; i < 50; i++){
      int valor = rand()%N+1;
      for (int j = 0; j < 1000; j++)
      {
          busca_tradiciona(arr,valor);
      }
      
  }
  float final_busca_trad = clock();

  printf("busca tradicional levou %f segundos \n\n", (final_busca_trad - inicial_busca_trad )/CLOCKS_PER_SEC);

  float inicial_busca_index = clock();
  for (int i =0 ; i < 50; i++){
      int valor = rand()%N+1;
      for (int j = 0; j < 1000; j++)
      {
        busca_indexada(lista_index,valor);
      }
      
  }
  float final_busca_index = clock();

  printf("busca index levou %f segundos \n\n", (final_busca_index - inicial_busca_index)/CLOCKS_PER_SEC);

}