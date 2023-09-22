#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 8



void quick_sort(int* arr, int ini, int fim){
  if(ini >= fim){return;}
  int pivo = arr[(ini+fim)/2];
  int temp;
 
  int i = ini;
  int j = fim;
  bool i_flag =  false;
  bool j_flag = false;
  while(i <= j)
  {
    if(arr[i] < pivo){
       i++;
    } else{
        i_flag = true;
    }

     if(arr[j] > pivo){
       j--;
    }else{
        j_flag = true;
    }
  
    if((j_flag && i_flag)){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j]= temp;
        i ++;
        j --;  
       i_flag = false;
       j_flag = false;   
    } 


  }

   quick_sort(arr,ini,j);
   quick_sort(arr,i,fim);   

}
/* Análise de complexidade: Seja n o número de elementos do vetor e k o número de iterações (profundidade) do algoritmo

a cada iteração do algoritmo é identificado um pivô e os outros elementos são movidos de modo que o pivô, 
ao final de uma iteração está na posição correta ordenada. Tambem a cada chamada da função, por recursão outras 2 são chamadas.

então o número de chamadas para que n elementos sejam analizados como pivôs e colocados nos seus lugares é:

2^k = n  // aplicando log (base 2) de ambos os lados temos: ( log(2^k) = log(n) ) = k * log(2) na base 2, então temos k=log(n)

portanto o número de iterações do algoritmo é log(n), essa é a profundidade da "árvore" de divisões do vetor

A cada iteração nos temos N - 2^k operações de comparação, k sendo a profundidade da chamada recursiva, devido ao fato de que ao modo em que os pivos são selecionados,
menos elementos dos vetores são percorridos nas sucessivas chamadas de função, porém para a notação Big O, N-Constante, sendo 2^k em uma certa iteração uma constante numérica,
então N-2^k = N para a análise de complexidade.

Portanto a complexidade final do algoritmo é (N * log(N) )








*/













int main(){

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


}
