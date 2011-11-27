// Danil Tumaykin - 4AIN - November 2011
#include <stdio.h>

int main()
{
	FILE *fp;
	FILE *ftemp;
	int curr, last;

	fp = fopen("integers.dat", "rb");
	ftemp = fopen("newintegers.dat", "wb");

	//reading one value
	fread(&last, sizeof(int), 1, fp);

	while(fread(&curr, sizeof(int), 1, fp))
	{
		if(!curr && last)
			last++;
		fwrite(&last, sizeof(int), 1, ftemp);
		last = curr;
	}

	fwrite(&last, sizeof(int), 1, ftemp);

	fclose(fp);
	fclose(ftemp);

	//remove & rename
	remove("integers.dat");
	rename("newintegers.dat", "integers.dat");

	return 0;
}