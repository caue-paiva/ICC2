#include "stdlib.h"
#include "stdio.h"


void printa_arr(int arr[], int n){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
}
void printa_arr2(int arr[], int n, int numero_remo){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    printf(" -%d ",numero_remo);
}

void rearranja_heap(int vetor[], int indice, int tamanho){
    int dir,esq,meio,maior;
    dir = 3*indice +1;
    meio =3* indice +2;
    esq = 3*indice +3;

   maior = indice;

    if (dir < tamanho && vetor[dir] > vetor[maior]) maior = dir;
    if (meio < tamanho && vetor[meio] > vetor[maior]) maior = meio;
    if (esq < tamanho && vetor[esq] > vetor[maior]) maior = esq;

    if (maior != indice){
        int temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;
        rearranja_heap(vetor,maior, tamanho);      
    }
}

void construir_heap(int  vetor[], int tamanho){
    for (int i = (tamanho/3)-1; i >= 0 ; i--)
    {
        rearranja_heap(vetor,i, tamanho);
    }  
}

void heap_sort(int vetor[], int tamanho){
  printa_arr(vetor,tamanho);
  construir_heap(vetor,tamanho);
  printa_arr(vetor,tamanho);
  printf("\n");
  int aux, tam_heap;
  tam_heap = tamanho;
  for (int i = tamanho-1; i >= 0; i--)
  { aux = vetor[0];
    
    vetor[0] = vetor[i];
    vetor[i]= aux;
    tam_heap--;
    printa_arr2(vetor,tam_heap,aux);
    rearranja_heap(vetor,0,tam_heap);
    printa_arr(vetor,tam_heap);
    printf("\n");
    
  }
  
}



int main(){

    /// array auxiliar para toda vez que testar não precisar escrever

    int n;
    scanf("%d",&n);
    int arr1[n];
    for (int  i = 0; i < n; i++){
       scanf("%d",&arr1[i]);
    }


    heap_sort(arr1,n);






}