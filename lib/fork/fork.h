#ifndef FORK_INCLUDED
#define FORK_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pid_t create_process(void);/**creates a child process*/

#endif
