
int mls(char *directory)
{
    // char *my_parameter = NULL;
    printf("Directory: %s", directory);
    if (strcmp(directory, "mls") == 10)
    {
        directory = "./";
    }
    remove_command_from_input(directory, "mls");
    DIR *d;
    struct dirent *rp;
    /* Nom répertoire */
    char *nom_rep = directory;
    /* Ouverture du flux */
    d = opendir(nom_rep);
    /* Test de bonne ouverture */
    if (d == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }
    /* Lecture du contenu et affichage du nom de chaque fichier rencontré */
    fprintf(stdout, "Contenu du répertoire %s\n", nom_rep);
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
