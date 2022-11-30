#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// Fonction qui affiche le contenu d'un fichier
void mcat(char *file_directory)
{
    char ch;
    FILE *fp;
    printf("\n---\nfile_directory: %s\n---\n", file_directory);
    // Ouverture du fichier
    fp = fopen(file_directory, "r");
    // Si erreur d'ouverture afficher l'erreur
    if (fp == NULL)
    {
        int errnum = errno;
        fprintf(stderr, "%s \n", strerror(errnum));
    }
    // Sinon afficher le contenu
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
    printf("\n\n");
}

// Commande qui affiche le contenu d'un ou plusieurs fichiers donnés en argument
int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        mcat(argv[i]);
    }
    return 0;
}