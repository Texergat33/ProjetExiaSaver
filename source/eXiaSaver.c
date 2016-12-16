#include <stdio.h>
#include <stdlib.h>
#include "launcher.h"

int main(int argc, char* argv[])
{
    system("clear"); //clear the console
    if (argc == 2 && strcmp(argv[1],"-stats") == 0)
	{
        printStats(); //print history
	}
	else
    {
        char current_directory[1024];
        char exiasaver_home[1024];
        getcwd(current_directory, 1024); //get current directory
        int rnum = rand_a_b(1, 3); //random number to define the screen saver to launch
        char* str = getenv("EXIASAVER_HOME"); //get env home var
        if(str != NULL) strcpy(exiasaver_home, str); //copy str if she exists
        else strcpy(exiasaver_home, current_directory);
        switch(rnum)
        {
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
