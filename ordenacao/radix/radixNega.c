
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 1000
typedef int Q_type; 

typedef struct {
   int start;
   int end;  //teste 
   int total;
   Q_type list[N];
} QUEUE;

bool queue_full(QUEUE*QUE){
   if (QUE->total==N){
      return true;
   }else{ return false; }
}

QUEUE* queue_create(void){
       QUEUE* new_q = (QUEUE*) malloc(sizeof(QUEUE));
              if(new_q==NULL){exit(1);}
       new_q->start = 0;
       new_q->end = 0;
       new_q->total = 0;
       return new_q;
}

void queue_free(QUEUE** QUE){
     free(*QUE);
     *QUE= NULL;
}

bool queue_empty(QUEUE*QUE){
   if (QUE->total == 0){
      return true;
   }else {return false;}
}

Q_type queue_pop(QUEUE*QUE){
       if (queue_empty(QUE)){
         printf(" fila vazia \n");
        exit(1);
       }else {
         Q_type retu = QUE->list[QUE->start];
         (QUE->start)++;
         (QUE->start) = (QUE->start % N);
         (QUE->total) -- ;
         return retu;
       }
}

bool queue_push(Q_type item, QUEUE* QUE){
     if(queue_full(QUE)){
        printf("queue is full \n");
        return false;
     } 
      QUE->list[QUE->end] = item;
      QUE->end++;
      QUE->end  = (QUE->end % N);
      //printf("new end: %d", QUE->end);
      QUE->total++;
      
      return true;
}


void radix_sort(int* arrPosi, int* arrNega, int tamPosi, int tamNega,int digitos){

QUEUE* filaArr[10];

for (int i = 0; i < 10; i++)
{
   QUEUE* TEMPfila = queue_create();
   filaArr[i] = TEMPfila;
  // printf("criou filas ");
}


//caso positivo
for (int i = 0; i < digitos; i++)
{

for (int j = 0; j < tamPosi; j++)
{
    int num = arrPosi[j];
    int raiz = (num / (int) pow(10, i)) % 10;
    QUEUE* fila_da_raiz = filaArr[raiz];
    queue_push(num,fila_da_raiz);
}
int index_posi = 0;

for (int k = 0; k < 10; k++)
{
    QUEUE* fila_da_raiz = filaArr[k];
   
    while(!queue_empty(fila_da_raiz)){
         arrPosi[index_posi] = queue_pop(fila_da_raiz);
         index_posi++;
    }
}
}


for (int i = 0; i < digitos; i++)
{

for (int j = 0; j < tamNega; j++)
{
    int num = abs(arrNega[j]);
    int raiz = (num / (int) pow(10, i)) % 10;
    QUEUE* fila_da_raiz = filaArr[raiz];
    queue_push(num,fila_da_raiz);
}
int index_nega= 0;

for (int k = 0; k < 10; k++)
{
    QUEUE* fila_da_raiz = filaArr[k];
   
    while(!queue_empty(fila_da_raiz)){
         arrNega[index_nega] = queue_pop(fila_da_raiz);
         index_nega++;
    }
}


}

for (int i = tamNega-1; i >= 0 ; i--)
{    
    int temp = (arrNega[i]* -1);
    printf("%d ", temp);
}

for (int i = 0; i < tamPosi; i++)
{
    printf("%d ", arrPosi[i]);
}




}

int main(){

int N1;
//printf("começo");
scanf("%d", &N1);

int arrPosi[N1];
int arrNega[N1];
int temp;
int tamPosi = 0 ;
int tamNega =0 ;
//printf("chama função ");
for (int i = 0; i < N1; i++)
{
   scanf("%d",&temp);

   if (temp>= 0){
      arrPosi[tamPosi] = temp;
      tamPosi++;
   } else{
    arrNega[tamNega] = temp;
    tamNega++;
   }
}

//printf("chama função \n");
radix_sort(arrPosi, arrNega,tamPosi, tamNega, 5);
}