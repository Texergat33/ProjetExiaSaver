#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

int main(int argc, char* argv[]){
    system("clear");
    srand(time(NULL));
    pid_t pid = create_process();
    char current_directory[1024];
    getcwd(current_directory, 1024);
    int rnum = rand_a_b(1, 3);
    char* exiasaver_home = getenv("EXIASAVER_HOME");
    if(exiasaver_home == NULL) exiasaver_home = current_directory;
    switch(rnum){
        case 1:
            launchExiaSaver1(current_directory, exiasaver_home, pid);
            break;
        case 2:
            launchExiaSaver2(current_directory, exiasaver_home, pid);
            break;
        case 3:
            launchExiaSaver3(current_directory, exiasaver_home, pid);
            break;
    }
    return 0;
}
