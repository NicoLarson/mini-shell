#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

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

pid_t spawnChild(char *program, char **arg_list)
{
	pid_t ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (ch_pid > 0)
	{
		printf("spawn child with pid - %d\n", ch_pid);
		return ch_pid;
	}
	else
	{
		execvp(program, arg_list);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

int mini_shell(void)
{
	// malloc
	char *leaving_prog_directory = "/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/build/";
	// strcat : copier la chaine
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
		printf("%s", strcat(prog_directory, first_word));
		// Enregistrer dans un tableau dynamique les arguments
		// Créer un processus fils et executer les programmes
		char *args[] = {first_word, NULL};
		pid_t child;
		int wstatus;
		child = spawnChild("aze", args);

		if (waitpid(child, &wstatus, WUNTRACED | WCONTINUED) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}

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
		printf("free input string");
		perror("execvp");

		free(input_string);
	}
	printf("EXIT");

	return EXIT_SUCCESS;
}
