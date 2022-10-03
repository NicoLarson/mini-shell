#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void mcat(char *file_directory)
{
	char ch;
	FILE *fp;
	printf("file_directory: %s", file_directory);
	fp = fopen(file_directory, "r");
	if (fp == NULL)
	{
		int errnum = errno;
		fprintf(stderr, "fp == NULL. %s \n", strerror(errnum));
	}
	else
	{
		fprintf(stdout, "Traitement du fichier \"%s\": Ok \n", file_directory);
		ch = fgetc(fp);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(fp);
		}
		fclose(fp);
	}
}
