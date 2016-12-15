#include "launcher.h"

int main(int argc, char* argv[]){
    Plane plane;
    if(argc == 2){
        char* position = argv[1];
        sscanf(position, "%dx%d", &plane.posX, &plane.posY);
        plane.posX = (plane.posX-(80/2));
        plane.posY = (plane.posY-(24/2));
    }else{
        plane.posX = 0;
        plane.posY = 0;
    }
    randomDirection(&plane);
    for(int i=0; i<80; i++){
        for(int j=0; j<24; j++){
            plane.img.image[i][j] = 0;
        }
    }

    char pbm_file[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);

    strcat(pbm_file, "/");
    strcat(pbm_file, plane.img.name);
    FILE* file = NULL;
    file = fopen(pbm_file, "r");
    if(file == NULL){        printf("Error. Can't open PBM file\n");
        return -1;
    }

    readResolution(file, &plane.img);
    loadPBM(file, &plane.img);
    fclose(file);
    movePlane(&plane);
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
            father_process(&plane);
            break;
    }
    system("clear");
    system("setterm -cursor on");
    return 0;
}
