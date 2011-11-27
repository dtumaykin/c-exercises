// Danil Tumaykin - 4AIN - November 2011
#include <stdio.h>

int main()
{
	FILE *fp;
	int last, curr;

	fp = fopen("integers.dat", "r+b");

	fread(&last, sizeof(int), 1, fp);

	while(fread(&curr, sizeof(int), 1, fp))
	{
		if(!curr && last)
		{
			fseek(fp, -2L * sizeof(int), SEEK_CUR);
			fwrite(&(++last), sizeof(int), 1, fp);
			fseek(fp, 1L * sizeof(int), SEEK_CUR);
		}
		last = curr;
	}

	fclose(fp);

	return 0;
}