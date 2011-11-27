// Danil Tumaykin - 4AIN - November 2011
#include <stdio.h>

int main()
{
	int vect[] = {1, 0, 0, 6, 8, 0, 9};
	int length = sizeof(vect)/sizeof(int);
	int i;
	FILE *fp;

	fp = fopen("integers.dat", "wb");

	for(i = 0; i < length; i++)
		fwrite(&vect[i], sizeof(int), 1, fp);

	fclose(fp);

	return 0;
}