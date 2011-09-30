#include <stdio.h>
#include <stdlib.h>

int somma(int num);

int main()
{
int num,risult;

  printf("Inserisci un valore intero positivo: ");
  scanf("%d",&num);
  fflush(stdin);
  
  risult=somma(num);
  
  printf("\n\nrisultato somma: %d",risult);
  
  getchar();
  return 0;
}

int somma(int num)
{
    if(!num)
      return 0;
    else
      return num+somma(--num);
}
