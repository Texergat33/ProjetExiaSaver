#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "launcher.h"

pid_t create_process(void)
{
    pid_t pid;
    do {
    pid = fork();
    } while ((pid == -1) && (errno == EAGAIN));
    return pid;
}

int rand_a_b(int a, int b){
    int c = rand()%((b+1)-a)+a;
    return c;
}

char *selectPBM(char *pbm_directory){
    DIR* rep = opendir(pbm_directory);
    if(rep != NULL){
        struct dirent * ent;
        int count = 0;
        while((ent = readdir(rep)) != NULL){
            count++;

        }
        int random_nbr = rand_a_b(1, count);
        rewinddir(rep);
        count = 0;
        while(count != random_nbr && (ent = readdir(rep)) != NULL){
            count ++;
        }
        closedir(rep);
        return ent->d_name;
    }
    exit(-1);
}

void execSaver1(char* arguments[], char* exiasaver_home){
    char chemin[1024];
    strcpy(chemin, exiasaver_home);
    strcat(chemin, "eXiaSaver1/eXiaSaver1");
    if(execv(chemin, arguments) == -1){
        perror("execv");
        exit(-1);
    }
}

void launchExiaSaver1(char current_directory[1024], char *exiasaver_home, pid_t pid){
    char* exiasaver1_pbm = getenv("EXIASAVER1_PBM");
    if(exiasaver1_pbm == NULL) exiasaver1_pbm = current_directory;
    char *random_pbm = selectPBM(exiasaver1_pbm);
    char* arguments[] = {"eXiaSaver1", random_pbm};
    switch(pid){
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            execSaver1(arguments, exiasaver_home);
            break;
        default:
            if (wait(NULL) == -1) {
                perror("wait :");
                exit(-1);
            }
            break;
    }
}

void launchExiaSaver2(char current_directory[1024], char *exiasaver_home, pid_t pid){
    char* exiasaver2_pbm = getenv("EXIASAVER2_PBM");
    if(exiasaver2_pbm == NULL) exiasaver2_pbm = current_directory;
    char* exiasaver2_taille = getenv("EXIASAVER2_TAILLE");
    if(exiasaver2_taille == NULL) exiasaver2_taille = "5x3";
    char* exiasaver2_sleep = getenv("EXIASAVER2_SLEEP");
    if(exiasaver2_sleep == NULL) exiasaver2_sleep = "10";
    printf("Launcher 2\n");
}

void launchExiaSaver3(char current_directory[1024], char *exiasaver_home, pid_t pid){
    char* exiasaver3_pbm = getenv("EXIASAVER3_PBM");
    if(exiasaver3_pbm == NULL) exiasaver3_pbm = current_directory;
    printf("Launcher 3\n");
}
