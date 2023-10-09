#include "stdlib.h"
#include "stdio.h"
#define N 8


void rearranja_heap(int*vetor, int indice, int tamanho){
    int dir,esq,maior;
    dir = 2*indice +1;
    esq =2* indice +2;

    if(esq < tamanho && vetor[esq]> vetor[indice]){
        maior = esq;
    }else if ( dir < tamanho && vetor[dir]> vetor[indice]){
        maior = dir;
    }else {maior = indice;}
    
    if (maior != indice){

        int temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;
        rearranja_heap(vetor,maior, tamanho);
    }
}

void construir_heap(int * vetor, int tamanho){

    for (int i = (tamanho/2)-1; i >= 0 ; i--)
    {
        rearranja_heap(vetor,i, tamanho);
    }
    
}

void heap_sort(int*vetor, int tamanho){
  construir_heap(vetor,tamanho);
  int aux, tam_heap;
  tam_heap = n;
  for (int i = tamanho-1; i >= 0; i--)
  { aux = vetor[0];
    vetor[0] = vetor[i];
    vetor[i]= aux;
    tam_heap--;
    rearranja_heap(vetor,0,tam_heap);
    
  }
  

}



int main(){


int* arr1 =(int*) malloc(sizeof(int)* N );

int arr2[N] = {2,8,7,3,0,9,9,9}; /// array auxiliar para toda vez que testar não precisar escrever

for (int  i = 0; i < N; i++)
{
    arr1[i] = arr2[i];
}


construir_heap(arr1,N);






}