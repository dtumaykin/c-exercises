#include <stdio.h>

#define DIM 10

int sommaDisp(int array[], int lung);

int main()
{
int array[DIM];
int i,lung,sum;

    printf("Quanti elementi vuoi inserire? ");
    scanf("%d", &lung);
    fflush(stdin);

    for(i=0;i<lung;i++)
    {
      printf("%d-Inserisci un numero intero positivo: ",i+1);
      scanf("%d", &array[i]);
      fflush(stdin);
    }
    
    sum=sommaDisp(array,--lung);
    
    printf("\n\n%d", sum);
    
    getchar();
    return 0;
}

int sommaDisp(int array[], int lung)
{
  if(lung>0)
  {
    if(lung%2)
    {
      return array[lung]+sommaDisp(array,lung-2);
    }
    else
      return sommaDisp(array,--lung);
  }
  else 
    return 0;
}
