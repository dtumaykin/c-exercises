// Danil Tumaykin - 4AIN - October 2011
#include <stdio.h>

double funz(double a, int n);

int main()
{
double a;
int n;

	printf("Inserisci N e A: ");
	scanf("%d%lf", &n, &a);

	printf("Risultato: %4.2f", funz(a, n));

	fflush(stdin);
	getchar();
	return 0;
}

double funz(double a, int n)
{
	if(n == 1)
		return a - n/a;
	return (a - n/a) + funz(a, n - 1);
}