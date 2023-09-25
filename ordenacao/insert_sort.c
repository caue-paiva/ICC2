#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 8

void shell_sort(int* arr, int Num){
    int h =1;

    while(h<Num/3){
      h= 3*h +1;
    }
   

    while(h > 0){
    printf("H: %d  \n\n", h);
    for (int i = h; i < Num; i++){
        
        int temp = arr[i];
        int j = i;

        while (j >= h && arr[j - h] > temp) {
                arr[j] = arr[j - h];
                j -= h;
            }

           arr[j] = temp;
     }

     h = h/2;
    }
}


int main(){


int* arr1 =(int*) malloc(sizeof(int)* N );

int arr2[N] = {25,57,48,37,12,92,86,33}; /// array auxiliar para toda vez que testar não precisar escrever

for (int  i = 0; i < N; i++)
{
    arr1[i] = arr2[i];
}

shell_sort(arr1,N);

for (int i = 0; i < N; i++)
{
    printf("%d ", arr1[i]);
}





}