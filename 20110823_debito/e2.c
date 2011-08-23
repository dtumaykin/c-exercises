//Dan Tumaykin - August 2011
#include <stdio.h>

#define STR_MAX 256

int integerCount(const char *str);

int main()
{
char str[STR_MAX];

    printf("Inserisci la stringa: ");
    gets(str); // scanf("%s", str); 

    printf("Massimo numero di cifre consecutive in \"%s\" e' %d.", str, integerCount(str));

    getchar();
    return 0;
}

int integerCount(const char *str)
{
int i, max = 0, temp = 0;

    for(i = 0; i < STR_MAX; i++)
        if(isdigit(str[i])) // str[i] >= 48 && str[i] <= 57
        {
            temp++;
            if(temp >= max) max = temp;
        }
        else
            temp = 0;

    return max;
}

