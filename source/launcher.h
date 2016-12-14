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
#include "../lib/fork/fork.h"
#include "../lib/rand/rand.h"

extern char **environ;
char *selectPBM(char *pbm_directory);/**Selects a file in a directory randomly*/
void execSaver1(char* arguments[], char* exiasaver_home);/**Runs the static saver*/
void execSaver3(char* arguments[], char* exiasaver_home);/**Runs the interactive saver*/
void launchExiaSaver1(char current_directory[1024], char *exiasaver_home);/**Prepares the execution of the static saver*/
void launchExiaSaver2(char current_directory[1024], char *exiasaver_home);/**Prepares the execution of the dynamic saver*/
void launchExiaSaver3(char current_directory[1024], char *exiasaver_home);/**Prepares the execution of the interactive saver*/

#endif
