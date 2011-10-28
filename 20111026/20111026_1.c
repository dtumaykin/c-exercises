// Danil Tumaykin - 4AIN - October 2011
#include <stdio.h>
#include <stdlib.h>

void printMenu(const char *menu[]);

int main()
{
char * menu[] = {
	"1. Voce 1\n",
	"2. Voce 2\n",
	"3. Voce 3\n",
	NULL
};

	printMenu(menu);

	getchar();
	return 0;
}

void printMenu(const char *menu[])
{
	do
	{
		puts(*menu);
	} while(*(++menu));
}
