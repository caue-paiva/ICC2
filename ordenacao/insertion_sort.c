#include "stdlib.h"
#include "stdio.h"
#define TAM 10

void insertion_sort(int arr[]){
   for(int i = 1; i < TAM; i++){
     int valor_atual =  arr[i];
     int j = i-1;

     while(j >= 0 && valor_atual < arr[j]){
         arr[j+1] = arr[j];
         j--;
     }
     arr[j+1] = valor_atual;
   }
}

int main(){

    int arr[TAM] = {2,4,6,19,10,98,82,4,8,9};
    
    insertion_sort(arr);

    for (int i =0; i < TAM; i++){
        printf("%d ", arr[i]);
    }
}