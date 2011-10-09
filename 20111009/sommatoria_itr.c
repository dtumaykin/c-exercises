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
double result = 0;

	while(n)
	{
		result += a - n/a;
		n--;
	}
	return result;
}