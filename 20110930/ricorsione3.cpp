#include <stdio.h>

void printChar( const char* stringa);

int main()
{
char *vett="Greta";

char * stringa;

    stringa=vett;

    printChar(stringa);
    
    getchar();
    return 0;
}
 
void printChar( const char* stringa)
{
  if(*stringa!='\0')
  {
    printf("%c\n", *stringa);
    printChar(stringa+1);
  }
}
    
