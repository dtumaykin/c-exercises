// Danil Tumaykin - 4AIN - October 2011
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
	int indice;
	char* voce;
}voceMenu;

typedef voceMenu* pVoceMenu;

int main()
{
int numElem, i;
char tmp[MAX];

	do
	{
		printf("Inserisci numero delle voci: ");
		scanf("%d", &numElem);
		fflush(stdin);
	}while(numElem < 0);
	
	//allocazione array di puntatori
	pVoceMenu *menu = new pVoceMenu[numElem];
	
	for(i = 0; i < numElem; i++)
	{
		//allocazione di singola voce
		menu[i] = new voceMenu;
		
		printf("Inserisci voce n. %d: ", i+1);
		gets(tmp);
		
		//allocazione spazio per la stringa
		menu[i]->voce = new char[strlen(tmp)+1];
		strcpy(menu[i]->voce, tmp);
		menu[i]->indice = i+1;
	}
	
	//stampa della struttura
	for(i = 0; i < numElem; i++)
	{
		printf("%d. %s.\n", menu[i]->indice, menu[i]->voce);
	}
	
	//deallocazione della struttura
	for(i = 0; i < numElem; i++)
	{
		delete[] menu[i]->voce;
		delete menu[i];
	}
	
	delete[] menu;
	
	fflush(stdin);
	getchar();
	return 0;
}
