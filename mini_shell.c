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
	history_file = fopen("/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/history.txt", "a+");

	if (history_file == NULL)
	{
		printf("Le fichier ne peut pas être ouvert\n");
		exit(1);
	}
	else
	{
		fputs(to_add, history_file);
		fputs("\n", history_file);
	}
	fclose(history_file);
}

int mcd(char *directory)
{
	int ch = chdir(directory);
	if (ch < 0)
		printf("chdir change of directory not successful\n");

	system("pwd");
	return 0;
}

char *concatenate(char *s1, char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2));
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}
int mini_shell(void)
{
	char *leaving_prog_directory = "/mnt/c/Users/nyang2/OneDrive - Université de Guyane/Documents/COURS/SYSTEM/mini-shell/build/";
	char **arg_list = calloc(100, sizeof(char *));
	char *input = calloc(100, sizeof(char));

	int exit_mini_shell = 0;
	while (exit_mini_shell == 0)
	{
		printf("mini-shell> ");
		fgets(input, 100, stdin);
		// insert input word in arg_list
		char *token = strtok(input, " ");
		int i = 0;
		while (token != NULL)
		{
			arg_list[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		arg_list[i - 1] = strtok(arg_list[i - 1], "\n");

		arg_list[i] = NULL;
		// if input is exit, exit the program
		if (strcmp(arg_list[0], "exit") == 0)
		{
			exit_mini_shell = 1;
		}
		else
		{
			add_to_history_file(arg_list[0]);
			char *command_build = concatenate(leaving_prog_directory, arg_list[0]);
			char *command = strtok(command_build, "\n");
			pid_t child_pid;
			child_pid = fork();
			if (child_pid != 0)
			{
				int child_status;
				waitpid(child_pid, &child_status, 0);
			}
			else
			{
				if (strcmp(arg_list[0], "mcd") == 0)
				{
					mcd(arg_list[1]);
				}
				else
				{
					execvp(command, arg_list);
				}
			}
		}
	}
	free(arg_list);
	free(input);
	return EXIT_SUCCESS;
}
