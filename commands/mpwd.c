#include <stdio.h>
#include <unistd.h>

void mpwd(void)
{
    char CWD[256];
    if (getcwd(CWD, sizeof(CWD)) == NULL)
        perror("getcwd(): error\n");
    else
        printf("%s\n", CWD);
}
