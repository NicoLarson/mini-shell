#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

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
	printf("%d",ch);
	if (ch < 0)
		printf("chdir change of directory not successful\n");
	else
	{
		printf("chdir change of directory successful\n");
	}
	system("pwd");
	return 0;
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
		printf("[mini_shell]-$: ");
		/* Lecture */
		nread = getline(&input_string, &n, stdin);
		add_to_history_file(input_string);
		char *first_word = strtok(input_string, " ");
		char *second_word = strtok(NULL, "\n");
		char *command_detected = command_detector(first_word);
		if (command_detected != 0)
		{
			// mcat
			if (strcmp(command_detected, "mcat") == 0)
			{
				char mcat_command[] = "./build/mcat ";
				if (second_word != NULL)
				{
					strcat(mcat_command, second_word);
					system(mcat_command);
				}
				else
				{
					system("./build/mcat");
				}
			}
			// mcd
			else if (strcmp(command_detected, "mcd") == 0)
			{
				mcd(second_word);
			}
			// mfind
			else if (strcmp(command_detected, "mfind") == 0)
			{
				system("./build/mfind");
			}
			// mgrep
			else if (strcmp(command_detected, "mgrep") == 0)
			{
				char mgrep_command[] = "./build/mgrep ";
				if (second_word != NULL)
				{
					strcat(mgrep_command, second_word);
					system(mgrep_command);
				}
				else
				{
					system("./build/mgrep");
				}
			}
			// mhist
			else if (strcmp(command_detected, "mhist") == 0)
			{
				system("./build/mhist");
			}
			// mls
			else if (strcmp(command_detected, "mls") == 0)
			{
				char mls_command[] = "./build/mls ";
				if (second_word != NULL)
				{
					strcat(mls_command, second_word);
					system(mls_command);
				}
				else
				{
					system("./build/mls");
				}
			}
			// mpwd

			else if (strcmp(command_detected, "mpwd") == 0)
			{
				system("./build/mpwd");
			}
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
