#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "mhist.h"

void mhist(void)
{
    char ch;
    FILE *fp;
    fp = fopen("history.txt", "r");
    if (fp == NULL)
    {
        int errnum = errno;
        fprintf(stderr, "fp == NULL. %s \n", strerror(errnum));
    }
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fp);
        }
        fclose(fp);
    }
}
