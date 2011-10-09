// Danil Tumaykin - 4AIN - October 2011
#include <stdio.h>

#define DIM 5

int max(int *vett, int numElem); // solo numeri positivi

int main()
{
int vett[DIM];
int numElem = 0;
	
	while(numElem < DIM)
	{
		printf("Inserisci elemento numero %d: ", numElem+1);
		scanf("%d", vett + numElem++);
		fflush(stdin);
	}

	printf("Valore massimo e': %d.", max(vett, numElem - 1));

	fflush(stdin);
	getchar();
	return 0;
}

int max(int *vett, int numElem)
{
	if(numElem < 0) return 0; // volendo si puo sostituire 0 con -2147483647
	if(vett[numElem] > max(vett, numElem - 1)) // per renderla piu' efficiente basta calcolare max() una sola volta
		return vett[numElem];
	
	return max(vett, numElem - 1);
}