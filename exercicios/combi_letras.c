#include "stdio.h"
#include "stdlib.h"

void combina_letra(int n,  char  letras_possiveis[], char ja_printou[]){
     
     for (int i = 0; i < n; i++)
     {
         if(ja_printou[i] <= 122 && 97 <= ja_printou[i])
           printf("%c", ja_printou[i]);
     }
     
     for (int i=0; i < n; i++){
        char copia_letras[n];
        for (int j=0; j < n; j++){
          copia_letras[j] = letras_possiveis[j];
        }
        char novo_ja_printou[n];
        if (letras_possiveis[i] != '#'){
            char pro_printar = letras_possiveis[i];
            novo_ja_printou[i] = letras_possiveis[i];
            printf("%c",copia_letras[i]);
            copia_letras[i] = '#';
            combina_letra(n,copia_letras,novo_ja_printou);
            printf(" ");
        }

     }
       printf(" ");
}

// void permuta_letras(int n, char letra_possi[], char ja_printou[]){
//    int novo_indi;
//    for (int i = 0; i < n; i++)
//    {
//      novo_ja_printou[n];
//   //   novo_indi = rand%n;
//      char novo_char = letras_possi[novo_indi];
//      if (ja_printou[novo_indi] != novo_char){
//         printf("%c", novo_char);
//      }else
//    }
   

// };


int main(){
   int n =3;
   char alfabeto[] = {'a','b','c','d'};
    char letras_possiveis[n];

    char ja_printou[n];
    for (int i=0; i < n; i++){
        letras_possiveis[i] = alfabeto[i];
    }

   combina_letra(3,letras_possiveis,ja_printou);

}