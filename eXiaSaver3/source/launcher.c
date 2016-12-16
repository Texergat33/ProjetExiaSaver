#include "launcher.h"
#include "../../lib/conio/conio.h"
#define SIZEKEY 256

void randomDirection(Plane *plane){ //Randomly defines a direction
    int nbr = rand_a_b(1, 4);
    switch(nbr){
        case 1:
            plane->direction = "right";
            strcpy(plane->img.name, "planeHD.pbm");
            break;
        case 2:
            plane->direction = "left";
            strcpy(plane->img.name, "planeHG.pbm");
            break;
        case 3:
            plane->direction = "up";
            strcpy(plane->img.name, "planeVH.pbm");
            break;
        case 4:
            plane->direction = "down";
            strcpy(plane->img.name, "planeVB.pbm");
            break;
    }
}

void loadDirection(Plane *plane){ //Changes the PBM image and the resolution of the plane according to the chosen direction
    char pbm_file[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);

    strcat(pbm_file, "/");
    strcat(pbm_file, plane->img.name);
    FILE* file = NULL;
    file = fopen(pbm_file, "r");
    if(file == NULL){
        printf("Error. Can't open PBM file\n");
        exit(-1);
    }

    readResolution(file, &plane->img); //Read the resolution of the new image
    for(int i=0; i<80; i++){
        for(int j=0; j<24; j++){
            plane->img.image[i][j] = 0;
        }
    }
    loadPBM(file, &plane->img); //Loads the PBM file into a array
    fclose(file);
}

void movePlane(Plane* plane){ //move the plane into an array
    PBM sky;
    sky = createBlankPBM(); //Initializes an array of the console size filled with 0
    strcpy(sky.name, "sky");

    if(strcmp(plane->direction, "left") == 0){
        strcpy(plane->img.name, "planeHG.pbm");
        loadDirection(plane); //Changes the PBM file according to the direction
        plane->posX -= 1; //mmove the plane to the left
        plane->posX = (plane->posX + 80)%80;
        placePBM(&sky, &plane->img, plane->posX,plane->posY);//Merges the white array and the plane array to a given position

    }
    else if(strcmp(plane->direction, "up") == 0){
        strcpy(plane->img.name, "planeVH.pbm");
        loadDirection(plane);
        plane->posY -= 1;
        placePBM(&sky, &plane->img, plane->posX,plane->posY);
    }
    else if(strcmp(plane->direction, "right") == 0){
        strcpy(plane->img.name, "planeHD.pbm");
        loadDirection(plane);
        plane->posX += 1;
        placePBM(&sky, &plane->img, plane->posX,plane->posY);
    }
    else if(strcmp(plane->direction, "down") == 0){
        strcpy(plane->img.name, "planeVB.pbm");
        loadDirection(plane);
        plane->posY += 1;
        placePBM(&sky, &plane->img, plane->posX,plane->posY);
    }
    plane->img = sky;
    system("clear");
    printPBM(plane->img); //Displays the array in the console
}

void child_process(){ //Management of user inputs
    char key[1];
    char k2, k3;
    int quit = 1;
    while(quit){
        key[0] = getch(); //waits for an input
        switch(key[0]){
            case 32:
                close(pipeDescriptor[0]);
                write(pipeDescriptor[1], "q", SIZEKEY); //Write the corresponding command in a pipe
                quit = 0;
                break;
            case 27:
                k2 = getch();
                if(k2 == 91){
                    k3 = getch();
                    switch(k3){
                        case 68://left arrow
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "l", SIZEKEY);
                            break;
                        case 65://top arrow
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "u", SIZEKEY);
                            break;
                        case 67://right arrow
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "r", SIZEKEY);
                            break;
                        case 66://bottom arrow
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "d", SIZEKEY);
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }
    exit(0);
}

void father_process(Plane *plane){//moves repeatedly the plane
    char* key = malloc(SIZEKEY);
    int integer;
    int flags = fcntl(pipeDescriptor[0], F_GETFL, 0);
    fcntl(pipeDescriptor[0], F_SETFL, flags | O_NONBLOCK);//Configures the pipe descriptor in non-blocking mode
    int quit = 1;
    while(quit){
        close(pipeDescriptor[1]);
        integer = read(pipeDescriptor[0], key, SIZEKEY); //check if we have an input
        usleep(70000); //sleep 70ms
        if(integer < 0 && errno == EAGAIN){
            movePlane(plane);//if we don't have an input, then we can move the plane
        }else if(integer >=0 ){
            switch(*key){
                case 'q':
                    quit = 0;
                    break;
                case 'l':
                    plane->direction = "left";
                    break;
                case 'u':
                    plane->direction = "up";
                    break;
                case 'r':
                    plane->direction = "right";
                    break;
                case 'd':
                    plane->direction = "down";
                    break;
                default:
                    break;
            }
        }
    }
    free(key);
}
