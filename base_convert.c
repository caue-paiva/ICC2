#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"

int str_to_int(char* strin, int base){
int result = 0;
int tam = strlen(strin);
for (int i = tam-1; i >= 0; i--)
{   // printf(" letter: %c", strin[i]);  
    int multi = strin[i]-'0';

    int expo = tam-i-1;
    float power =  pow(base,expo);
    int add = multi * power; 
    result+= add;

}
return result;

}


int main(){

char str[]= "00100";
int converted = str_to_int(str, 2);
printf(" %d \n ", converted);

}