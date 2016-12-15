#include <stdio.h>
#include <stdlib.h>
#include "../../lib/PBM/PBM.h"
#include "../../lib/conio/conio.h"

int main (int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error. Incorrect number of args\n"); //print an error message if there is not the name of the opened file
        return -1;
    }
    PBM image; //
    char key; //create a char key which would accept keyboard inputs
    strcpy(image.name, argv[1]); //copy the name of the PBM file into argv[1]
    for(int i=0; i<80; i++)
    {
        for(int j=0; j<24; j++)
        {
            image.image[i][j] = 0; //initialize the size of the console
        }
    }
    char pbm_file[1024]; //create a char 
    char* str = getenv("EXIASAVER1_PBM"); //
    if(str != NULL) strcpy(pbm_file, str); //
    else getcwd(pbm_file, 1024); //
    strcat(pbm_file, "/"); //add a "/" at the end of the way of the pbm file
    strcat(pbm_file, image.name); //add the name of the pbm file after the "/"
    FILE* file = fopen(pbm_file, "r"); //open the pbm_file for reading
    if(file != NULL)
    {
        readResolution(file, &image); //
        loadPBM(file, &image); //
        fclose(file); //
        printPBM(image); //
        system("setterm -cursor off"); //remove the cursor of the screen
        key = getch(); //read keyboard inputs without the user needs to press on entry
        system("clear"); //erase the console
        system("setterm -cursor on"); //puts back the cursor on the screen
    }
    else
    {
        printf("This file can't be opened.\n"); //print an error message
    }
    return 0;
}
