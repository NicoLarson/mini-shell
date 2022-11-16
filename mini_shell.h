#ifndef __MINI_SHELL_H__
#define __MINI_SHELL_H__

char *command_detector(char *first_word);
void add_to_history_file(char *to_add);
int mini_shell(void);

#endif
