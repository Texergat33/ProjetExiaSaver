#ifndef EXIASAVER_H
#define EXIASAVER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>

extern char **environ;
pid_t create_process(void);
int rand_a_b(int, int);
char *selectPBM(char *pbm_directory);
void execSaver1(char* arguments[], char* exiasaver_home);
void execSaver3(char* arguments[], char* exiasaver_home);
void launchExiaSaver1(char current_directory[1024], char *exiasaver_home);
void launchExiaSaver2(char current_directory[1024], char *exiasaver_home);
void launchExiaSaver3(char current_directory[1024], char *exiasaver_home);

#endif
