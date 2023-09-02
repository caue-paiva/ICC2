#include "stdlib.h"
#include "stdio.h"




int main(){

int SeqSize,target, interv_size=1000;
int* arr =  (int*) malloc (sizeof(int)*SeqSize);
//int arr[] = {1,-2,3,-1,2,4};
int sum=0;

scanf("%d", &SeqSize);

 for (int i = 0; i < SeqSize; i++)
 {
     scanf("%d", &arr[i]);
   //  printf("\n number entered: %d", arr[i]);
 }

scanf("%d", &target);
int TempStart=0, TempEnd, FinalStart, FinalEnd;


for (int i = 0; i < SeqSize; i++)
{   sum = 0;

  for (int j = i; j < SeqSize ; j++)
  { TempStart = i;
  // printf( "i is %d j is %d \n",i, j);
    sum += arr[j];
   // printf(" current sum: %d \n", sum);

    if (sum == target){
        
        TempEnd = j;
       
        if ((TempEnd - TempStart) < interv_size){
             interv_size = TempEnd - TempStart;
             FinalStart = TempStart+1;
             FinalEnd = TempEnd+1;
             sum = 0;
             // printf("found sum  temp start: %d  temp end: %d \n", TempStart, TempEnd);
             break;        
        }
        
           
    }
  }  
    
}

printf( "%d %d", FinalStart, FinalEnd);



}