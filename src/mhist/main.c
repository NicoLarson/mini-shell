#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mhist.h"

#define OPTIONS "c"

void clean_history(void)
{
    remove("/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/history.txt");
}

int main(int argc, char **argv)
{
    opterr = 0;
    char option = 0;
    while (option != -1)
    {
        option = getopt(argc, argv, OPTIONS);
        switch (option)
        {
        case 'c':
            clean_history();
            break;
        case '?':
            fprintf(stdout, "Option %c inconnue\n", optopt);
            break;
        }
    }
    mhist();

    return EXIT_SUCCESS;
}
