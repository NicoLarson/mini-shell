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

void add_to_history_file(char *to_add)
{
    FILE *history_file;
    history_file = fopen("history.txt", "a+");

    if (history_file == NULL)
    {
        printf("Le fichier ne peut pas être ouvert\n");
        exit(1);
    }
    else
    {
        fputs(to_add, history_file);
    }
    fclose(history_file);
}
