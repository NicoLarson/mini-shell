#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define OPTIONS "c"

// Fonction qui affiche l'historique des commandes exécutées
void mhist(void)
{
    printf("--- HISTORY ---\n");
    char ch;
    FILE *fp;
    // Ouverture et lecture du fichier history.txt
    fp = fopen("/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/history.txt", "r");
    ch = fgetc(fp);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}

// Fonction qui supprime le fichier history.txt
void clean_history(void)
{
    remove("/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/history.txt");
}

// Commande qui affiche l'historique des commandes exécutées avec une option pour la supprimer
int main(int argc, char **argv)
{
    opterr = 0;
    char option = 0;
    // Boucle pour gérer les options
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
