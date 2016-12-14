#include "launcher.h"

int main(int argc, char* argv[]){
    PBM Plane;
    strcpy(Plane.name, "planeHD.pbm");
    for(int i=0; i<80; i++){
        for(int j=0; j<24; j++){
            Plane.image[i][j] = 0;
        }
    }

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
    printPBM(Plane);
    pipe(pipeDescriptor);
    pid_t pid = create_process();
    switch(pid){
        case -1:
            perror("fork");
            return -1;
        case 0:
            child_process();
            break;
        default:
            system("setterm -cursor off");
            father_process();
            break;
    }
    system("clear");
    system("setterm -cursor on");
    return 0;
}
