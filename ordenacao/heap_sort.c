#include "stdlib.h"
#include "stdio.h"
#define N 8


void rearranja_heap(int*vetor, int indice, int tamanho){
    int dir,esq,maior;
    dir = 2*indice +1;
    esq = 2* indice +2;

    if(esq < tamanho && vetor[esq]> vetor[indice]){
        maior = esq;
    }else if ( dir < tamanho && vetor[dir]> vetor[indice]){
        maior = dir;  //acha quem é o maior filho
    }else {maior = indice;}
    
    if (maior != indice){
        int temp = vetor[indice];
        vetor[indice] = vetor[maior]; //troca o maior filho com o pai
        vetor[maior] = temp;
        rearranja_heap(vetor,maior, tamanho); //desce mais um nível para ver precisa rearranjar os niveis abaixo depois da mudança
    }
}

void construir_heap(int * vetor, int tamanho){
    for (int i = (tamanho/2)-1; i >= 0 ; i--) //pega os items na metade do array -1, pq depois disso só tem nós folhas
    {
        rearranja_heap(vetor,i, tamanho); //rearranja a heap 
    }
}

void heap_sort(int*vetor, int tamanho){
  construir_heap(vetor,tamanho); //constroi a heap uma vez
  int aux, tam_heap;
  tam_heap = n;
  for (int i = tamanho-1; i >= 0; i--){ //começa do fim e vai descendo ate 0
    aux = vetor[0]; //pega a raiz da arvore, o maior numero
    vetor[0] = vetor[i];  //troca de lugar o maior com o ultimo do vetor atual (antes dos que ja estão no lugar certo)
    vetor[i]= aux;
    tam_heap--; //reduz o tamanho da heap
    rearranja_heap(vetor,0,tam_heap); //rearranja ela com o menor tamanho
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