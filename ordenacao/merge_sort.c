#include "stdio.h"
#include "stdlib.h"

/* 




*/
Q
void insert_sort(int *arr, int come, int fim){
     
     for (int i = come+1; i <= fim; i++)
     {
        int j = i - 1;
        int item = arr[i];

     while(j >= come && arr[j] > item){
        arr[j + 1] = arr[j];
        j--;

     }
    arr[j + 1] = item;
}

}

void merge_sort(int * arr, int come , int fim, int k){
     if ((fim - come)+1 <= k){
        insert_sort(arr, come,fim); 
        //printf(" \n \n items do insert sort ");
        for (int i = come; i <= fim; i++)
        {
         printf("%d " , arr[i]);
        }
        printf("\n");
             
        return;
    }


     if (come < fim) {
     int meio = (fim  +come) / 2;
       
     merge_sort(arr,come,meio,k);
     merge_sort(arr,meio+1,fim,k);
     insert_sort(arr, come,fim);

     }

}

// void sort_2_vetores(int * arr, int come, int fim){
        
//         for (int i = come; i < fim; i++)
//         {
            
//         }
        

// }


int main(){


//int arr2[N] = {9,4,8,7,6,2,3,1,0,5}; /// array auxiliar para toda vez que testar não precisar escrever

int N,K;
scanf("%d",&N);


int* arr1 =(int*) malloc(sizeof(int)* N );
    if (arr1 ==NULL){exit(1);}
for (int  i = 0; i < N; i++)
{
   scanf("%d", &arr1[i]); 
}

scanf("%d",&K);


merge_sort(arr1,0, N-1, K);

for (int i = 0; i < N; i++)
{
    printf("%d ", arr1[i]);
}

free(arr1);


}