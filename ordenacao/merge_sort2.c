#include "stdio.h"
#include "stdlib.h"


/* integrantes do grupo
CAUE PAIVA LIRA 
NUSP: 14675416

José Carlos Andrade do Nascimento
NUSP: 12549450

Thales Sena de Queiroz
NUSP:   14608873

Filipe Bueno Balsani
nusp: 4621914


Yvin Miguel Juanico Carvalho
NUSP: 13677239


Tiago Carvalho de Freitas
NUSP: 11800754



*/

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
     if (fim - come+1 <= k){
        insert_sort(arr, come,fim); 
        for (int i = come; i <= fim; i++){
         printf("%d " , arr[i]);
        }printf("\n");
             
        return;
    }

    int meio = (fim  +come) / 2;
     
     merge_sort(arr,come,meio,k);
     merge_sort(arr,meio+1,fim,k);

     int arr1[meio-come+1];
     int arr2[fim-meio];
    
    int j=0;
     for(int i=come;i<=meio;i++){
        arr1[j]=arr[i];
        j++;
     }
    j=0;
     for(int i=meio+1;i<=fim;i++){
        arr2[j]=arr[i];
        j++;
     }

     int i1=0;
     int i2=0; 
     for(int i=come;i<=fim;i++){
        if(i1==meio-come+1){
            arr[i]=arr2[i2];
            i2++;
        }else if(i2==fim-meio){
            arr[i]=arr1[i1];
            i1++;
        }else if(arr1[i1]<arr2[i2]){
            arr[i]=arr1[i1];
            i1++;
        }else{
           arr[i]=arr2[i2];
           i2++; 
        }
     }

     for (int i = come; i <= fim; i++){
         printf("%d" , arr[i]);
         if(i!=fim) 
            printf(" ");
    }

}



int main(){

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

free(arr1);



}