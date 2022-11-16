#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "mini_shell.h"

int main(void)

{
    mini_shell();
    return EXIT_SUCCESS;
}