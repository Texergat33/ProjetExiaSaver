#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern char **environ;

int rand_a_b(int a, int b){
    int c = rand()%((b+1)-a)+a;
    return c;
}

int main(int argc, char* argv[]){
    system("clear");
    srand(time(NULL));
    char current_directory[1024];
    getcwd(current_directory, 1024);
    int rnum = rand_a_b(1, 3);
    char* exiasaver_home = getenv("EXIASAVER_HOME");
    if(exiasaver_home == NULL) exiasaver_home = current_directory;
    switch(rnum){
        case 1:
            char* exiasaver1_pbm = getenv("EXIASAVER1_PBM");
            if(exiasaver1_pbm == NULL) exiasaver1_pbm = current_directory;
            break;
        case 2:
            char* exiasaver2_pbm = getenv("EXIASAVER2_PBM");
            if(exiasaver2_pbm == NULL) exiasaver2_pbm = current_directory;
            char* exiasaver2_taille = getenv("EXIASAVER2_TAILLE");
            if(exiasaver2_taille == NULL) exiasaver2_taille = "5x3";
            char* exiasaver2_sleep = getenv("EXIASAVER2_SLEEP");
            if(exiasaver2_sleep == NULL) exiasaver2_sleep = "10";
            break;
        case 3:
            char* exiasaver3_pbm = getenv("EXIASAVER3_PBM");
            if(exiasaver3_pbm == NULL) exiasaver3_pbm = current_directory;
            break;
    }
    return 0;
}
