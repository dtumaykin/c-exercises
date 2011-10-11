// Danil Tumaykin - 4AIN - October 2011
#include <stdio.h>

int somma(int n, int k);

int main()
{
int n, k;

	printf("Inserisci n, k: ");
	scanf("%d%d", &n, &k);

	printf("Somma: %d.", somma(n, k));

	fflush(stdin);
	getchar();
	return 0;
}

int somma(int n, int k)
{
	if(!n) return 0;
	return n*k + somma(n - 1, k);
}