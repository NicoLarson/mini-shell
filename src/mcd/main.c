#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int ch = chdir(argv[1]);

    if (argc == 2)
    {

        if (ch < 0)
            printf("chdir change of directory not successful\n");
        else
        {
            printf("chdir change of directory successful\n");
        }
    }
    system("pwd");
    return chdir(argv[1]);
}