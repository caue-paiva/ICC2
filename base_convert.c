#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"

int str_to_int(char* strin, int base){
int result = 0;
int exponent = 0; 
int tam = strlen(strin);
for (int i = tam-1; i >= 0; i--)
{   // printf(" letter: %c", strin[i]);  
    int multi = strin[i]-'0';
    result+=multi*pow(base, tam-i-1);

    exponent++;
}

return result;


}


int main(){

char str[]= "110";
int converted = str_to_int(str, 7);
printf("%d\n ", converted);

}