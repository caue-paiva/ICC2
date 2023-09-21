#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 6



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
/* Análise de complexidade












*/













int main(){

int* arr1 =(int*) malloc(sizeof(int)* N );

int arr2[N] = {2,3,8,9,0,9}; /// array auxiliar para toda vez que testar não precisar escrever

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