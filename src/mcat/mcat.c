#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "mcat.h"

void mcat(char *file_directory)
{
	char ch;
	FILE *fp;
	printf("\nfile_directory: %s\n\n", file_directory);
	fp = fopen(file_directory, "r");
	if (fp == NULL)
	{
		int errnum = errno;
		fprintf(stderr, "%s \n", strerror(errnum));
	}
	else
	{

		printf("---\n");
		ch = fgetc(fp);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(fp);
		}
		fclose(fp);
	}

	printf("\n---\n\n");
}
