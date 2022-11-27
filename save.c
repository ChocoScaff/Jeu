#include "common.h"
//#include "stdlib.h"

void save(void)
{
	FILE *inputFile=NULL;

	inputFile = fopen("saves/save.sav", "w");
	if (inputFile != NULL)
	{
		fputs("sauvergarde",inputFile);
		fclose(inputFile);
	}
}
