//Dan Tumaykin - August 2011
#include <stdio.h>

#define N 8

void init1(char mtx[][N], char c);
void init2(char mtx[][N], char c);

int main()
{
char mtx[N][N];
int i, j;

    init1(mtx, '*');
    
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%2c", mtx[i][j]);
        printf("\n");
    }
    printf("\n");

    init2(mtx, '*');

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%2c", mtx[i][j]);
        printf("\n");
    }
    printf("\n");

    getchar();
    return 0;
}

void init1(char mtx[][N], char c)
{
int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(j%2)
                mtx[i][j] = c;
            else
                mtx[i][j] = ' ';
}

void init2(char mtx[][N], char c)
{
int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if((i+j) % 2)
                mtx[i][j] = c;
            else
                mtx[i][j] = ' ';
}
