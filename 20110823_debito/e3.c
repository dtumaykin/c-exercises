//Dan Tumaykin - August 2011
#include <stdio.h>

#define N 10

typedef struct {
    int elem[N];
    int index;
} set;

int isIn(const set *s, int num);
int addEl(set *s, int new);
set unione(const set *s1, const set *s2);

int main() // main() non era richiesta nell'esercizio, solo le funzioni e le loro chiamate
{
set s1, s2, s3;
int i, temp, status;

    s1.index = s2.index = -1; // inizilizziamo i set

    //aggiungiamo 3 elementi ad ogni set
    for(i = 0; i < 3; i++)
    {
        printf("Inserisci elemento da aggiungere a set 1: ");
        scanf("%d", &temp);
        status = addEl(&s1, temp);
        if(status)
            printf("aggiunto\n");
        else
            printf("gia' presente/set pieno\n");
    }

    for(i = 0; i < 3; i++)
    {
        printf("Inserisci elemento da aggiungere a set 2: ");
        scanf("%d", &temp);
        status = addEl(&s2, temp);
        if(status)
            printf("aggiunto\n");
        else
            printf("gia' presente/set pieno\n");
    }

    //ora uniamo due set
    s3 = unione(&s1, &s2);

    //stampiamo il risultato di unione
    for(i = 0; i <= s3.index; i++)
        printf("%3d", s3.elem[i]);
    printf("\n");

    fflush(stdin);
    getchar();
    return 0;
}

int isIn(const set *s, int num)
{
int i;
    
    for(i = 0; i <= s->index; i++)
        if(s->elem[i] == num)
            return 1;
			
    return 0;
}

int addEl(set *s, int new)
{
    if(!isIn(s, new))
    {
        s->elem[++s->index] = new; //oppure in 1 sola righa: s->elem[++(s->index)] = new;
        return 1;
    }
	
    return 0;
}       

set unione(const set *s1, const set *s2)
{
int i;
set result;

    result.index = -1; // init new set

    for(i = 0; i <= s1->index; i++) // copia il primo set nel set resultante
		addEl(result, s1->elem[i]);

    for(i = 0; i <= s2->index; i++) // copia il secondo set nel set resultante
		addEl(result, s2->elem[i]);
		
    return result;
}

