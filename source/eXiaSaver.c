#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

int main(int argc, char* argv[]){
    system("clear");
    srand(time(NULL));
    char current_directory[1024];
    char exiasaver_home[1024];
    getcwd(current_directory, 1024);
    int rnum = rand_a_b(1, 3);
    char* str = getenv("EXIASAVER_HOME");
    if(str != NULL) strcpy(exiasaver_home, str);
    else strcpy(exiasaver_home, current_directory);
    switch(rnum){
        case 1:
            launchExiaSaver1(current_directory, exiasaver_home);
            break;
        case 2:
            launchExiaSaver2(current_directory, exiasaver_home);
            break;
        case 3:
            launchExiaSaver3(current_directory, exiasaver_home);
            break;
    }
    return 0;
}
