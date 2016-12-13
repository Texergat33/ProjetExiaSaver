#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

int rand_a_b(int a, int b)
{
    srand(time(NULL));
    int c = rand()%((b+1)-a)+a;
    return c;
}

char *selectPBM(char *pbm_directory){
    DIR* rep = opendir(pbm_directory);
    if(rep != NULL)
    {
        struct dirent * ent;
        int count = 0;
        while((ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) count ++;
        }
        int random_nbr = rand_a_b(1, count);
        rewinddir(rep);
        count = 0;
        while(count != random_nbr && (ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) count ++;
        }
        closedir(rep);
        return ent->d_name;
    }
    exit(-1);
}

void execSaver1(char* arguments[], char* exiasaver_home)
{
    char chemin[1024];
    strcpy(chemin, exiasaver_home);
    strcat(chemin, "/eXiaSaver1/eXiaSaver1");
    if(execv(chemin, arguments) == -1)
    {
        perror("execv");
        exit(-1);
    }
}

void execSaver3(char* arguments[], char* exiasaver_home)
{
    char chemin[1024];
    strcpy(chemin, exiasaver_home);
    strcat(chemin, "/eXiaSaver3/eXiaSaver3");
    if(execv(chemin, arguments) == -1)
    {
        perror("execv");
        exit(-1);
    }
}

void launchExiaSaver1(char current_directory[1024], char *exiasaver_home)
{
    char* str = getenv("EXIASAVER1_PBM");
    char exiasaver1_pbm[1024];
    if(str != NULL) strcpy(exiasaver1_pbm, str);
    else strcpy(exiasaver1_pbm, current_directory);
    char *random_pbm = selectPBM(exiasaver1_pbm);
    char* arguments[] = {"eXiaSaver1", random_pbm, NULL};
    pid_t pid = create_process();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver1(arguments, exiasaver_home);
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

void launchExiaSaver2(char current_directory[1024], char *exiasaver_home)
{
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
    printf("Launcher 2\n");
}

void launchExiaSaver3(char current_directory[1024], char *exiasaver_home)
{
    char exiasaver3_pbm[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(exiasaver3_pbm, str);
    else strcpy(exiasaver3_pbm, current_directory);
    char* arguments[] = {"eXiaSaver3", NULL};
    pid_t pid = create_process();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver3(arguments, exiasaver_home);
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
