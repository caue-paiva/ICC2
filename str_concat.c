#include "stdlib.h"
#include "stdio.h"
#include "string.h"

char *str_concat(char *str1, char* str2){

int len1 = strlen(str1);
int len2=  strlen(str2);
int len = (len1 + len2)+1;

char *new_str = (char*) malloc (sizeof(char)* len);
    if (new_str == NULL)
        exit(1);


for (int i = 0; i < len-1; i++)
{   if (i < (len-len2-1)){
     new_str[i]= str1[i];
    } else {
     new_str[i] = str2[i - len1];
    }  
}
    new_str[len] = '\0';
    return new_str;

}


int main(){

char str[]= "thalesasfkasjf";
char str2[] = "filipesdkjgskdjg";

char *ret_str = str_concat(str, str2);
printf("%s ", ret_str);


}