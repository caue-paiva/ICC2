#include <stdio.h>
#include<stdlib.h>

int main ()
{
  int mark[1000010];
  int n;

  for (int i = 0; i < 1000001; i++)
    mark[i] = 0;

  scanf ("%d", &n);

  long int tam = 0;
  for (int i = 0; i < n; i++)
    {
      int a;
      scanf ("%d", &a);
      if (!mark[a])
	{
	 
	  tam++;
	  mark[a] = 1;
	}
    }
    
    printf("%ld", (tam*(tam-1))/2);


  return 0;
}
