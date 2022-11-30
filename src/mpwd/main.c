#include <stdio.h>
#include <unistd.h>

// Affichage du répertoire courant
int main(void)
{
    char CWD[256];
    if (getcwd(CWD, sizeof(CWD)) == NULL)
        perror("getcwd(): error\n");
    else
        printf("%s\n", CWD);
    return 0;
}
