#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// affichage des lignes de fichiers donnés en argument contenant une chaîne de caractères aussi donnée en argument
int main(int argc, char **argv)
{

    // vérification du nombre d'arguments
    if (argc < 3)
    {
        printf("Utilisation: %s string fichier& [fichier2 ...]\n", argv[0]);
        return 1;
    }

    // parcours des fichiers
    for (int i = 2; i < argc; i++)
    {
        // ouverture du fichier
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("Erreur: ouverture du fichier %s\n", argv[i]);
            continue;
        }

        // parcours des lignes du fichier
        char *line = NULL;
        size_t size = 0;
        int line_number = 0;
        while (getline(&line, &size, file) != -1)
        {
            line_number++;

            // recherche de la chaîne de caractères dans la ligne
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s:%d: %s", argv[i], line_number, line);
            }
        }

        // fermeture du fichier
        fclose(file);
    }

    return 0;
}