#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Commande qui affiche des lignes de fichiers donnés en argument contenant une chaîne de caractères aussi donnée en argument
int main(int argc, char **argv)
{
    // Vérification du nombre d'arguments
    if (argc < 3)
    {
        printf("Utilisation: %s string fichier& [fichier2 ...]\n", argv[0]);
        return 1;
    }
    // Parcours des fichiers
    for (int i = 2; i < argc; i++)
    {
        // Ouverture du fichier
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("Erreur: ouverture du fichier %s\n", argv[i]);
            continue;
        }
        // Parcours des lignes du fichier
        char *line = NULL;
        size_t size = 0;
        int line_number = 0;
        while (getline(&line, &size, file) != -1)
        {
            line_number++;
            // Recherche de la chaîne de caractères dans la ligne
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s: ligne %d:\n%s", argv[i], line_number, line);
            }
        }
        // Fermeture du fichier
        fclose(file);
    }
    return 0;
}