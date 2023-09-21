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

  while(i <= j)
  {

    while(arr[i] < pivo){
        i++;
    }

    while(arr[j] > pivo){
        j--;
    }

    if(i <= j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j]= temp;
        i ++;
        j --;     
    } 
  }

   quick_sort(arr,ini,j);
   quick_sort(arr,i,fim);   

}














int main(){

int* arr1 =(int*) malloc(sizeof(int)* N );

int arr2[N] = {2,3,8,9,0,9};

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