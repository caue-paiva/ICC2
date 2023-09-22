#include "stdlib.h"
#include "stdio.h"


int main(){

char  alfa[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int M;
char str[27];
scanf("%d",&M);
scanf("%s", str);

int flag =0;
int chance;

for (int i =0; i < M; i++){
     if (alfa[i] != str[i]){
        flag++;
     }

     if (flag > 2){
        printf("There aren't the chance.");
        return 0;
        
     }
    
}

printf("There are the chance.");


}