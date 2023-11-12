#include "stdio.h"
#include "stdlib.h"

void printa_arr(int arr[], int n,int flag){
   // printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
   // if(flag)
   //   printf(" ");
}

void cocktail_sort(int arr[], int n){
    int flag =1;
    int trocou;
    int temp;
    while(1){
      trocou = 0;
      if(flag){
         for (int i = 0; i < n-1; i++)
         {
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                trocou = 1;
            }
         }
      }else{
         for (int i = n-1; i >= 1 ; i--)
         {
             if(arr[i] < arr[i-1]){
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                trocou = 1;
            }
         }
         

      }
    
       if(!trocou){
        printa_arr(arr,n,1);
        break;
       }else{
         printa_arr(arr,n,1);
         printf("\n");
       }
       flag = !flag;
    }
}




int main(){
    int n;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }

    cocktail_sort(arr,n);
    
}