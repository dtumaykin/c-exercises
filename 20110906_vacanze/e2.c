//Dan Tumaykin - September 2011
#include <stdio.h>

#define F 5 //file
#define P 6 //posti per fila
#define L 2  //poltronissime

#define NORM 15.5f
#define POLT 50.0f

void init(int t[F][P]);
void stampaPianta(const int t[F][P]);
int prenota(const int f, const int p, int t[F][P], int *prenotazione);
double incasso(const int t[F][P]);
int poltroneAffiancateInFila(const int t[F][P], const int f, int *p);
int poltroneAffiancate(const int t[F][P], int *f, int *p);
char menu();

int main()
{
int teatro[F][P];
int prenotazione = 0;
	
int f, p, done = 0;

	init(teatro);
	
	while(!done)
	{
		fflush(stdin);
		switch(menu())
		{
			case 's':
				stampaPianta(teatro);
				break;
			case 'p':
				printf("Inserisci numero di posto e fila che vuoi prenotare: ");
				scanf("%d%d", &p, &f);
				switch(prenota(f, p, teatro, &prenotazione))
				{
					case -1:
						printf("Valori inamessibili.");
						break;
					case 0:
						printf("Il posto e' occupato.");
						break;
					default:
						printf("Prenotazione riuscita, n: %d.", prenotazione);
						break;
				}
				break;
			case 'i':
				printf("L'incasso e' pari a: %5.2f", incasso(teatro));
				break;
			case 'a':
				if(poltroneAffiancate(teatro, &f, &p))
					printf("Ci sono delle poltrone affiancate nella fila %d, posto %d.", f, p);
				else
					printf("Non ci sono piu' poltrone affiancate.");
				break;
			case 'u':
				done = 1;
				break;
			default:
				break;
		}
	}
	
	fflush(stdin);
	getchar();
	return 0;
}

void init(int t[F][P])
{
int i, j;
	for(i = 0; i < F; i++)
		for(j = 0; j < P; j++)
			t[i][j] = 0;
}

void stampaPianta(const int t[F][P])
{
int i, j;

	//stampa intestazione tabella
	printf("\n\t");
	for(i = 0; i < P; i++)
		printf("%d\t", i+1);

	printf("\n");
	for(i = 0; i < F; i++)
	{
		printf("%d\t", i+1);
		for(j = 0; j < P; j++)
			if(t[i][j])
				printf("%c\t", 'X');
			else
				printf("%c\t", 'O');
		printf("\n");
	}
}
	
int prenota(const int f, const int p, int t[F][P], int *prenotazione)
{
	if(f > F || p > P) //se il valore e amissibile
		return -1;
	else if(t[f-1][p-1]) //se il posto e' libero
		return 0;
	else
		t[f-1][p-1] = ++*prenotazione; //prenotiamo il posto
		
	return *prenotazione;
}

double incasso(const int t[F][P])
{
double tot = 0;
int i, j;

	for(i = 0; i < F; i++)
		for(j = 0; j < P; j++)
			if(i < L) // se poltronissima
				tot+=POLT;
			else 
				tot+=NORM;
	return tot;
}

int poltroneAffiancateInFila(const int t[F][P], const int f, int *p)
{
int j;
	for(j = 0; j < P - 1; j++)
		if(!(t[f][j] || t[f][j+1]))
		{
			*p = j+1;
			return 1;
		}
	return 0;
}

int poltroneAffiancate(const int t[F][P], int *f, int *p)
{
int i;
	for(i = 0; i < F; i++)
		if(poltroneAffiancateInFila(t, i, p))
		{
			*f = i+1;
			return 1;
		}
		return 0;		
}
char menu()
{
char c;

	printf("\nQuale azione desidera eseguire: \n");
	printf("s: stampare la pianta del teatro\n");
	printf("p: prenotare un posto\n");
	printf("a: trovare delle poltrone affiancate\n");
	printf("i: visualizza incasso\n");
	printf("e: uscire dal programma\n");
	
	printf("\nLa tua scelta: ");
	scanf("%c", &c);
	fflush(stdin);

	return c;
}
