// Tumaykin Danil - 4AIN - October 2011
#include <stdio.h>
#include <string.h>

#define DIM 256

int pal(char *str, int length);

int main()
{
char str[DIM];

	printf("Inserisci la parola: ");
	scanf("%s", str);

	if(pal(str, strlen(str)))
		printf("\nParola \"%s\" e' palindroma.", str);
	else
		printf("\nParola \"%s\" non e' palindroma.", str);

	fflush(stdin);
	getchar();
	return 0;
}

int pal(char *str, int length)
{
	if(length <= 1) return 1;
	if(str[0] == str[length - 1] && pal(str+1, length - 2)) 
		return 1;

	return 0;
}