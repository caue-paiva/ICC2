#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 8



void quick_sort(int arr[], int ini, int fim){
  if(ini >= fim){return;}
  int pivo = arr[(ini+fim)/2];
  int temp;
 
  int i = ini;
  int j = fim;

  while(i <= j)
  {
    while(arr[i] < pivo){
       i++;
    } 
    
    while(arr[j] > pivo){
       j--;
    }
   
   if (i <= j){
    temp = arr[i];
    arr[i] = arr[j];
    arr[j]= temp;
    i ++;  //isso é para que a partição da direita não conte com o index do pivo
    j --;    //isso é para que a partição da esquerda não conte com o index do pivo
   }
  
  }
   quick_sort(arr,ini,j);
   quick_sort(arr,i,fim);   
}

void quicksort2(int arr[], int comeco ,int fim){
    if(comeco>= fim){return;}
    int i = comeco;
    int j = fim;
    int pivo = arr[(fim+comeco)/2];
    while (i <= j){

        while(arr[i] < pivo){
            i++;
        }
        while(arr[j]> pivo){
            j--;
        }

        if (i <= j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }
    quicksort2(arr,i,fim);
    quicksort2(arr,comeco,j);
}

int main(){

    int arr[N] = {2,4,6,19,10,98,82,4};
    
    quicksort2(arr,0,N-1);

    for (int i =0; i < N; i++){
        printf("%d ", arr[i]);
    }
}
/* Análise de complexidade: caso em que o pivô é selecionado no meio

Seja n o número de elementos do vetor e k o número de iterações (profundidade) do algoritmo

a cada iteração do algoritmo é identificado um pivô e os outros elementos são movidos de modo que o pivô, 
ao final de uma iteração está na posição correta ordenada. Tambem a cada chamada da função, por recursão outras 2 são chamadas.

então o número de chamadas para que n elementos sejam analizados como pivôs e colocados nos seus lugares é:

2^k = n  // aplicando log (base 2) de ambos os lados temos: ( log(2^k) = log(n) ) = k * log(2) na base 2, então temos k=log(n)

portanto o número de iterações do algoritmo é log(n)

A cada iteração nos temos N - 2^k operações de comparação, k sendo a profundidade da chamada recursiva, devido ao fato de que ao modo em que os pivos são selecionados,
menos elementos dos vetores são percorridos nas sucessivas chamadas de função, porém para a notação Big O, N-Constante, sendo 2^k em uma certa iteração uma constante numérica,
então N-2^k = N para a análise de complexidade.


Portanto a complexidade final do algoritmo é (N * log(N) )








*/

void quick_sort3(int arr[], int ini, int fim){
    if(ini >= fim) return;
    int i = ini;
    int j =fim;
    int pivo = arr[ ((ini+fim)/2) ];

    while (i<=j){

        while(arr[i] < pivo)
          i++;
        while (arr[j] > pivo)
          j--;
        
        if(i<=j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] =temp;
            i++;
            j--;
        }
    }

    quick_sort3(arr,ini,j);
    quick_sort3(arr,i,fim);

}






void quick_sort2(int arr[], int come, int fim){
    if (come>=fim)
      return;
    int i = come;
    int j = fim;
    int pivo = arr[(come+fim)/2];

    while (i <= j){

        while (arr[j] > pivo)
           j--;
        while(arr[i]< pivo)
           i++;

        if(i<=j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j--;
            i++;
        }
    }

    quick_sort2(arr,come,j);
    quick_sort2(arr,i,fim);
}





/*int main(){

int* arr1 =(int*) malloc(sizeof(int)* N );

int arr2[N] = {2,8,7,3,0,9,9,9}; /// array auxiliar para toda vez que testar não precisar escrever

for (int  i = 0; i < N; i++)
{
    arr1[i] = arr2[i];
}

quick_sort(arr1,0,N-1);


for (int i = 0; i < N; i++)
{
    printf("%d ", arr1[i]);
}


}*/
