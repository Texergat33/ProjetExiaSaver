#include <stdio.h>
#include <stdlib.h>
#include "../../lib/PBM/PBM.h"
#include "../../lib/conio/conio.h"

int main (int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error. Incorrect number of args\n");
        return -1;
    }
    PBM image;
    char key;
    strcpy(image.name, argv[1]);
    for(int i=0; i<80; i++)
    {
        for(int j=0; j<24; j++)
        {
            image.image[i][j] = 0;
        }
    }
    char pbm_file[1024];
    char* str = getenv("EXIASAVER1_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);
    strcat(pbm_file, "/");
    strcat(pbm_file, image.name);
    FILE* file = fopen(pbm_file, "r");
    if(file != NULL)
    {
        readResolution(file, &image);
        loadPBM(file, &image);
        fclose(file);
        printPBM(image);
        system("setterm -cursor off");
        key = getch();
        system("clear");
        system("setterm -cursor on");
    }
    else
    {
        printf("This file can't be opened.\n");
    }
    return 0;
}
