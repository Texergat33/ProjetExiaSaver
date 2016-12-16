#include "launcher.h"

int main(int argc, char* argv[]){
    Plane plane;
    if(argc == 2){ //set the plane position if she is filled in
        char* position = argv[1];
        sscanf(position, "%dx%d", &plane.posX, &plane.posY);
        plane.posX = (plane.posX-(80/2)); //the function loadPBM centers the image in an array, so we move the center of the plane to the correct position
        plane.posY = (plane.posY-(24/2));
    }else{
        plane.posX = 0;
        plane.posY = 0;
    }
    randomDirection(&plane); //choose a random direction for the plane
    for(int i=0; i<80; i++){
        for(int j=0; j<24; j++){
            plane.img.image[i][j] = 0; //initialize the image
        }
    }

    char pbm_file[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);

    strcat(pbm_file, "/");
    strcat(pbm_file, plane.img.name);
    FILE* file = NULL;
    file = fopen(pbm_file, "r"); //open the correct pbm file
    if(file == NULL){
        printf("Error. Can't open PBM file\n");
        return -1;
    }

    readResolution(file, &plane.img); //read the resolution of the plane
    loadPBM(file, &plane.img); //load the pbm in the array
    fclose(file);
    movePlane(&plane); //move the values in the plane array
    pipe(pipeDescriptor); //create a pipe
    pid_t pid = create_process(); //create a child process
    switch(pid){
        case -1:
            perror("fork");
            return -1;
        case 0:
            child_process(); //listen the user inputs
            break;
        default:
            system("setterm -cursor off"); //disables the display of the cursor
            father_process(&plane); //move the plane
            break;
    }
    system("clear");
    system("setterm -cursor on"); //enables the display of the cursor
    return 0;
}
