#include <stdio.h>

void print(const int list[], int length);

int main()
{
int array[]={1,2,3,4,5,6};

    print(array, sizeof(array)/sizeof(int));
    
    getchar();
    return 0;
}
 
void print(const int list[], int length)
{
  if(length>0)
  {
    print(list,length-1);
    printf("%d", list[length-1]);
  }
}
    
