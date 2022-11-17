#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

void add_to_history_file(char *to_add)
{
	FILE *history_file;
	history_file = fopen("history.txt", "a+");

	if (history_file == NULL)
	{
		printf("Le fichier ne peut pas être ouvert\n");
		exit(1);
	}
	else
	{
		fputs(to_add, history_file);
	}
	fclose(history_file);
}

void run_command(char *command_name, char *arguments)
{
	char command_to_run[] = "./build/";
	strcat(command_to_run, command_name);
	strcat(command_to_run, " ");

	if (arguments != NULL)
	{
		strcat(command_to_run, arguments);
		system(command_to_run);
	}
	else
	{
		system("./build/mcat");
	}
}

int mcd(char *directory)
{
	int ch = chdir(directory);
	printf("%d", ch);
	if (ch < 0)
		printf("chdir change of directory not successful\n");
	else
	{
		printf("chdir change of directory successful\n");
	}
	system("pwd");
	return 0;
}

// Function who concatenate 2 strings
char *concatenate(char *s1, char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
	// in real code you would check for errors in malloc here
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}
int mini_shell(void)
{
	char *leaving_prog_directory = "/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/build/";
	char **arg_list = malloc(100 * sizeof(char *));
	int exit_mini_shell = 0;
	while (exit_mini_shell == 0)
	{
		size_t n = 0;
		char *input_string = NULL;
		ssize_t nread;
		printf("[MINI-SHELL]-$: ");
		nread = getline(&input_string, &n, stdin);
		// Enregistrer dans une variable la commande
		char *first_word = strtok(input_string, " ");
		char *command = concatenate(leaving_prog_directory, first_word);
		// Enregistrer les arguments dans le tableau arguments
		int i = 0;
		while (first_word != NULL)
		{
			arg_list[i] = first_word;
			first_word = strtok(NULL, " ");
			i++;
		}
		arg_list[i] = NULL;
		// afficher les tableau
		for (int j = 0; j < i; j++)
		{
			printf("%s\n", arg_list[j]);
		}

		// Detecter la commande
		// executer les programmes
		// TODO : gerer les argument

		printf("command - %s\n", command);
		char *args[] = {first_word, NULL};
		// execvp fonctionne avec des arguments
		execvp(command, args);
		perror("execve");

		if (nread == -1)
		{
			printf("nread == -1 ");

			perror("getline");
			return EXIT_FAILURE;
		}

		if (strcmp(input_string, "exit") == 10)
		{
			exit_mini_shell = 1;
		}
		/* Libérer la mémoire */
		perror("execvp");

		free(input_string);
	}
	printf("EXIT");

	return EXIT_SUCCESS;
}
