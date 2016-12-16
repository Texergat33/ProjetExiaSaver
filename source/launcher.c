#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

char *selectPBM(char *pbm_directory){ //select a random pbm name
    DIR* rep = opendir(pbm_directory); //open the pbm directory
    if(rep != NULL)
    {
        struct dirent * ent;
        int count = 0; //count the number of pbms in the directory
        while((ent = readdir(rep)) != NULL) //read each file until the end of the directory
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) count ++;//if ent points on . or .., we don't want to increase count
        }
        int random_nbr = rand_a_b(1, count); //select a random number between 1 and the number of files in the directory
        rewinddir(rep); //returns the pointer to the top of the directory
        count = 0;
        while(count != random_nbr && (ent = readdir(rep)) != NULL)//if count == random_nbr then the file pointed by ent is the file randomly selected
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) count ++;
        }
        closedir(rep);
        return ent->d_name; //returns the name of the random file
    }
    exit(-1); //if the file can't be opened
}

void execSaver1(char* arguments[], char* exiasaver_home)
{ //execute the static saver with the correct args
    char path[1024];
    strcpy(path, exiasaver_home);
    strcat(path, "/eXiaSaver1/eXiaSaver1");
    if(execv(path, arguments) == -1)
    {
        perror("execv");
        exit(-1);
    }
}

void execSaver2(char* arguments[], char* exiasaver_home)
{ //execute the dynamic saver with the correct args
    char path[1024];
    strcpy(path, exiasaver_home);
    strcat(path, "/eXiaSaver2/eXiaSaver2");
    if(execv(path, arguments) == -1)
    {
        perror("execv");
        exit(-1);
    }
}

void execSaver3(char* arguments[], char* exiasaver_home)
{ //execute the interactive saver with the correct args
    char path[1024];
    strcpy(path, exiasaver_home);
    strcat(path, "/eXiaSaver3/eXiaSaver3");
    if(execv(path, arguments) == -1)
    {
        perror("execv");
        exit(-1);
    }
}

void launchExiaSaver1(char current_directory[1024], char *exiasaver_home)
{ //prepares the array of correct args for the static screen saver and creates a child process
    char* str = getenv("EXIASAVER1_PBM");
    char exiasaver1_pbm[1024];
    if(str != NULL) strcpy(exiasaver1_pbm, str);
    else strcpy(exiasaver1_pbm, current_directory);
    char *random_pbm = selectPBM(exiasaver1_pbm);//select a random pbm file name
    char tolog[255];
    strcpy(tolog, random_pbm);
    char* arguments[] = {"eXiaSaver1", random_pbm, NULL}; //arguments array
    pid_t pid = create_process(); //creates a child process
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver1(arguments, exiasaver_home); //executes the static saver with the correct args array
            break;
        default:
            if (wait(NULL) == -1) //wait for the end of the child process
            {
                perror("wait :");
                exit(-1);
            }
            break;
    }
    logger(1, tolog); //log the launching
}

void launchExiaSaver2(char current_directory[1024], char *exiasaver_home)
{ //prepares the array of correct args for the dynamic screen saver and creates a child process
    char exiasaver2_pbm[1024];
    char* str = getenv("EXIASAVER2_PBM");
    if(str != NULL) strcpy(exiasaver2_pbm, str);
    else strcpy(exiasaver2_pbm, current_directory);
    char exiasaver2_taille[100];
    str = getenv("EXIASAVER2_TAILLE");
    if(str != NULL) strcpy(exiasaver2_taille, str);
    else strcpy(exiasaver2_taille, "5x3");
    char exiasaver2_sleep[100];
    str = getenv("EXIASAVER2_SLEEP");
    if(str != NULL) strcpy(exiasaver2_sleep, str);
    else strcpy(exiasaver2_sleep, "10");
    char* size = "5x3";
    logger(2, size);
    char* arguments[] = {"eXiaSaver2", size, NULL};
    pid_t pid = create_process();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver2(arguments, exiasaver_home); //executes the dynamic saver with the correct args array
            break;
        default:
            if (wait(NULL) == -1)
            {
                perror("wait :");
                exit(-1);
            }
            break;
    }
}

void launchExiaSaver3(char current_directory[1024], char *exiasaver_home)
{ //prepares the array of correct args for the interactive screen saver and creates a child process
    char exiasaver3_pbm[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(exiasaver3_pbm, str);
    else strcpy(exiasaver3_pbm, current_directory);
    int x = rand_a_b(0, 80); //define a random plane position
    int y = rand_a_b(0, 24);
    char position[10];
    sprintf(position, "%dx%d", x, y);
    char* arguments[] = {"eXiaSaver3", position, NULL};
    logger(3, position);
    pid_t pid = create_process();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver3(arguments, exiasaver_home); //executes the interactive saver with the correct args array
            break;
        default:
            if (wait(NULL) == -1)
            {
                perror("wait :");
                exit(-1);
            }
            break;
    }
}
