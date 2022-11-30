#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *word_to_find = argv[2];

    DIR *d;
    struct dirent *rp;
    /* Nom répertoire */
    char *directory_name = argv[1];

    /* Ouverture du flux */
    d = opendir(directory_name);
    /* Test de bonne ouverture */
    if (d == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }
    /* Lecture du contenu et affichage du nom de chaque fichier rencontré */
    // TODO : parcourir le dossier
    rp = readdir(d);
    while (rp != NULL)
    {
        if (strncmp(rp->d_name, word_to_find, 3) == 0)
        {
            if (rp->d_type == 4)
            {
                fprintf(stdout, "Find directory: \"%s\" in %s\n", rp->d_name, directory_name);
            }
            else
            {
                fprintf(stdout, "Find file: \"%s\" in %s\n", rp->d_name, directory_name);
            }
        }
        rp = readdir(d);
    }

    /* Fermeture du flux */
    closedir(d);
    printf("\n");
    return EXIT_SUCCESS;
}