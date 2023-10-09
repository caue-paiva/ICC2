#include <stdio.h>
#include<stdlib.h>

int ctbits(int v){
    int ans=0;
    for(int i=1;i<=v;i*=2){
        if(i&v){
            ans++;
        }
    }
    //printf("%d %d\n", v, ans);
    return ans;
}

int main ()
{
    int n;
    int tam[11];
    int buckets[11][1010];
    int v[1010];
    
    scanf("%d", &n);
    
    for(int i=0;i<11;i++){
        tam[i]=0;
    }
    
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    
    while(1){
        int swapped=0;
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        int bits=ctbits(v[i]);
        buckets[bits][tam[bits]]=v[i];
        tam[bits]++;
    }
    
    for(int i=1;i<11;i++){
        if(tam[i]){
            for(int j=0;j<tam[i];j++){
                printf("%d ", buckets[i][j]);
            }printf("\n");
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }printf("\n");

  return 0;
}
