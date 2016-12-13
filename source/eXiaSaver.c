#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

int main(int argc, char* argv[]){ /**Randomly launches one of the three screensavers*/
    system("clear");

    if (argc == 2 && strcmp(argv[1],"-stats") == 0)
	{
		//printStats();
		printf("Statistiques\n");
	}else{

        char current_directory[1024];
        getcwd(current_directory, 1024);

        char exiasaver_home[1024];
        char* str = getenv("EXIASAVER_HOME");
        if(str != NULL) strcpy(exiasaver_home, str);
        else strcpy(exiasaver_home, current_directory);

        int rnum = rand_a_b(1, 3);
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
    }
    return 0;
}
