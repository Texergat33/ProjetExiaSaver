#include <stdio.h>
#include <stdlib.h>
#include "../../lib/PBM/PBM.h"
#include <unistd.h>

int main(int argc, char* argv[]){
    printf("Launcher 3\n");
    PBM Plane;
    strcpy(Plane.name, "planeHD.pbm");
    char pbm_file[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);
    strcat(pbm_file, "/");
    strcat(pbm_file, Plane.name);
    FILE* file = NULL;
    file = fopen(pbm_file, "r");
    if(file == NULL){        printf("Error. Can't open PBM file\n");
        return -1;
    }
    readResolution(file, &Plane);
    loadPBM(file, &Plane);
    fclose(file);
    //printPBM(Plane);
    system("setterm -cursor off");
    //pipe here
    getchar();
    getchar();
    system("clear");
    system("setterm -cursor on");
    return 0;
}
