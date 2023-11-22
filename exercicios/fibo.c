#include "stdio.h"
#include "stdlib.h"

int fibo_iter(int f0, int f1, int n){
    if (n==1) return 0;
    if (n==2) return 1;
    int ante1 = f1;
    int ante2 = f0;
    int total;
    for (int i = 2; i <= n; i++){
        total = ante1+ante2;
        ante2 = ante1;
        ante1 =total;
    } 

    return total;
}

int main(){

printf("%d", fibo_iter(0,1,6));



}