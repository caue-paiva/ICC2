#include "stdlib.h"
#include "stdio.h"
#define N 8
int merge_sort(int arr[], int ini , int fim){
    if(ini >= fim)
      return ini;
    int meio = (fim+ini)/2;

    int ini_primeiro = merge_sort(arr,ini,meio);
    int ini_segundo = merge_sort(arr,meio+1,fim);
    
    int novo_arr[(fim-ini)];
    int index_novo = 0 ;
    while(1){
        if(ini_primeiro > meio)
           break;
        if(ini_segundo > fim)
           break;

        if(arr[ini_primeiro] > arr[ini_segundo]){
            novo_arr[index_novo] = arr[ini_segundo];
            ini_segundo++;
            index_novo++;
        }else{
            novo_arr[index_novo] = arr[ini_primeiro];
            ini_primeiro++;
        }
   
    }

    return ini;
}

int main(){

    int arr[N] = {2,4,6,19,10,98,82,4};
    
    merge_sort(arr,0,N-1);

    for (int i =0; i < N; i++){
        printf("%d ", arr[i]);
    }

}