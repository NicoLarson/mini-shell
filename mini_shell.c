#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define NUM_OF_COMMAND 7
char *my_commands[NUM_OF_COMMAND] = {"mls", "mpwd", "mcd", "mfind", "mcat", "mgrep", "mhist"};

char *command_detector(char *input_command)
{
    char *first_word = strtok(input_command, " ");
    char *command_detected;
    for (int i = 0; i < NUM_OF_COMMAND; i++)
    {
        if ((strstr(first_word, my_commands[i])) == NULL)
        {
            command_detected = "Commande introuvable\n";
        }
        else
        {
            command_detected = my_commands[i];
            i = NUM_OF_COMMAND;
        }
    }

    return command_detected;
}

int mini_shell(void)
{

    int exit = 0;
    while (exit == 0)
    {
        size_t n = 0;
        char *my_command = NULL;
        ssize_t nread;
        /* Message */
        printf("$: ");
        /* Lecture */
        nread = getline(&my_command, &n, stdin);
        /* Verification */
        if (nread == -1)
        {
            perror("getline");
            return EXIT_FAILURE;
        }

        
        printf("command_detector: %s \n", command_detector(my_command));
        if (strcmp(my_command, "exit") == 10)
        {
            exit = 1;
        }
        /* Libérer la mémoire */
        free(my_command);
    }
    return EXIT_SUCCESS;
}