#include "stdio.h"
#include "stdlib.h"
#define N 8

int busca_bin(int arr[], int buscado){
   int infe = 0;
   int supe = N-1;
   int meio;
   while(supe >= infe){
      meio = (infe+supe)/2;
      if(arr[meio]== buscado)
        return meio;
      if(arr[meio] > buscado)
         supe = meio-1;
      else
         infe = meio+1;      
   }
   return -1;
}

int busca_bin_recu(int arr[], int infe, int supe, int buscado){
   if(infe > supe)
      return -1;
   int meio = (infe+supe)/2;
   if(arr[meio] == buscado)
     return meio;
   if(arr[meio] > buscado)
     return busca_bin_recu(arr,infe, meio-1, buscado);
   else
     return busca_bin_recu(arr,meio+1, supe, buscado);
}

int main(){
  int arr[N] = {1,5,6,8,9,10,23,57};
  //printf("%d ", busca_bin(arr,5));
   printf("%d ", busca_bin_recu(arr,0,N-1,100));

}