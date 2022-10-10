#include <stdio.h>
#include <stdlib.h>
#include "mcat.h"

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        mcat(argv[i]);
    }
    return 0;
}