#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 5

int bubble_sort2(int*arr){
    for (int i = N-1; i >= 0 ; i--){   
        for (int j = 0; j < i; j++)
        {
            if(arr[j]> arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int bubble_sort(int*arr){
    int swap_count = 1;
    int iter = 0;
    while(swap_count != 0){
        swap_count = 0;
        for (int i = 0; i < N-1; i++)
        {   int temp;
            iter++;
            if(arr[i] > arr[i+1]){
               temp = arr[i+1];
               arr[i+1]= arr[i];
               arr[i] = temp;
               swap_count++;
              
            }            
        }   
        printf("%d\n", swap_count);     
    }
    return iter;
}


int main(){

int* arr1 =(int*) malloc(sizeof(int)* N );

for (int  i = 0; i < N; i++)
{
    scanf("%d", &arr1[i]);
}


bubble_sort2(arr1);

for (int  i = 0; i < N; i++)
{
   printf("%d ", arr1[i]);
}



}