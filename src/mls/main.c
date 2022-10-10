#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    DIR *d;
    struct dirent *rp;
    /* Nom répertoire */
    char *directory_name = "./";
    if (argc == 2)
    {
        directory_name = argv[1];
    }
    /* Ouverture du flux */
    d = opendir(directory_name);
    /* Test de bonne ouverture */
    if (d == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }
    /* Lecture du contenu et affichage du nom de chaque fichier rencontré */
    rp = readdir(d);
    while (rp != NULL)
    {
        fprintf(stdout, "%s\n", rp->d_name);
        rp = readdir(d);
    }
    /* Fermeture du flux */
    closedir(d);
    printf("\n");
    return EXIT_SUCCESS;
}
