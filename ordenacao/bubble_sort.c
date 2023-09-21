#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 6


int bubble_sort(int*arr){
    int swap_count =1;
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


int iter = bubble_sort(arr1);

for (int  i = 0; i < N; i++)
{
   printf("%d ", arr1[i]);
}

printf("\n iterations %d \n", iter);




}