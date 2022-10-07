#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

// #include "commands/mcat.c"
// #include "commands/mcd.c"
// #include "commands/mfind.c"
// #include "commands/mgrep.c"
// #include "commands/mhist.c"
// #include "commands/mls.c"
// #include "commands/mpwd.c"

#define NUM_OF_COMMAND 7

char *my_commands[NUM_OF_COMMAND] = {"mls", "mpwd", "mcd", "mfind", "mcat", "mgrep", "mhist"};

char *command_detector(char *first_word)
{
	char *command_detected;
	for (int i = 0; i < NUM_OF_COMMAND; i++)
	{
		if ((strstr(first_word, my_commands[i])) == NULL)
		{
			command_detected = 0;
		}
		else
		{
			command_detected = my_commands[i];
			i = NUM_OF_COMMAND;
		}
	}

	return command_detected;
}

void parameter_detector(char *parameter)
{
}

int mini_shell(void)
{
	int exit = 0;
	while (exit == 0)
	{
		size_t n = 0;
		char *input_string = NULL;
		ssize_t nread;
		/* Prompteur */
		printf("[mini-shell]-$: ");
		/* Lecture */
		nread = getline(&input_string, &n, stdin);
		// add_to_history_file(input_string);
		char *first_word = strtok(input_string, " ");
		printf("first_word: %s \n", first_word);

		char *second_word = strtok(NULL, " ");

		printf("second_word2: %s \n", second_word);

		char *command_detected = command_detector(first_word);
		if (command_detected != 0)
		{
		// 	// mcat
		// 	if (strcmp(command_detected, "mcat") == 0)
		// 	{
		// 		if (second_word != NULL)
		// 		{
		// 			printf("Veillez indiquer un fichier. \n");
		// 		}

		// 		mcat(main.c);
		// 	}
		// 	// mcd
		// 	else if (strcmp(command_detected, "mcd") == 0)
		// 	{
		// 		mcd();
		// 	}
		// 	// mfind
		// 	else if (strcmp(command_detected, "mfind") == 0)
		// 	{
		// 		mfind();
		// 	}
		// 	// mgrep
		// 	else if (strcmp(command_detected, "mgrep") == 0)
		// 	{
		// 		mgrep();
		// 	}
		// 	// mhist
		// 	else if (strcmp(command_detected, "mhist") == 0)
		// 	{
		// 		mhist();
		// 	}
		// 	// mls
		// 	else if (strcmp(command_detected, "mls") == 0)
		// 	{
		// 		if (second_word == NULL)
		// 		{
		// 			second_word = "./";
		// 		}
		// 		mls(second_word);
		// 	}
		// 	// mpwd

		// 	else if (strcmp(command_detected, "mpwd") == 0)
		// 	{
		// 		if (second_word != NULL)
		// 		{
		// 			printf("Argument inutile\n");
		// 		}
		// 		mpwd();
		// 	}
		}
		else
		{
			printf("Commande inconnue \n");
		}

		/* Verification */
		if (nread == -1)
		{
			perror("getline");
			return EXIT_FAILURE;
		}

		if (strcmp(input_string, "exit") == 10)
		{
			exit = 1;
		}
		/* Libérer la mémoire */
		free(input_string);
	}
	return EXIT_SUCCESS;
}
