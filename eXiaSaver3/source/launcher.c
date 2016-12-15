#include "launcher.h"
#include "../../lib/conio/conio.h"
#define SIZEKEY 256

void randomDirection(Plane *plane){
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

void loadDirection(Plane *plane){
    char pbm_file[1024];
    char* str = getenv("EXIASAVER3_PBM");
    if(str != NULL) strcpy(pbm_file, str);
    else getcwd(pbm_file, 1024);

    strcat(pbm_file, "/");
    strcat(pbm_file, plane->img.name);
    FILE* file = NULL;
    file = fopen(pbm_file, "r");
    if(file == NULL){        printf("Error. Can't open PBM file\n");
        exit(-1);
    }

    readResolution(file, &plane->img);
    for(int i=0; i<80; i++){
        for(int j=0; j<24; j++){
            plane->img.image[i][j] = 0;
        }
    }
    loadPBM(file, &plane->img);
    fclose(file);
}

void movePlane(Plane* plane){
    PBM sky;
    sky = createBlankPBM();
    strcpy(sky.name, "sky");

    if(strcmp(plane->direction, "left") == 0){
        strcpy(plane->img.name, "planeHG.pbm");
        loadDirection(plane);
        plane->posX -= 3;
        plane->posX = (plane->posX + 80)%80;
        placePBM(&sky, &plane->img, plane->posX,plane->posY);

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
        plane->posX += 3;
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
    printPBM(plane->img);
}

void child_process(){
    char key[1];
    char k2, k3;
    int quit = 1;
    while(quit){
        key[0] = getch();
        switch(key[0]){
            case 32:
                close(pipeDescriptor[0]);
                write(pipeDescriptor[1], "q", SIZEKEY);
                quit = 0;
                break;
            case 27:
                k2 = getch();
                if(k2 == 91){
                    k3 = getch();
                    switch(k3){
                        case 68:
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "l", SIZEKEY);
                            break;
                        case 65:
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "u", SIZEKEY);
                            break;
                        case 67:
                            close(pipeDescriptor[0]);
                            write(pipeDescriptor[1], "r", SIZEKEY);
                            break;
                        case 66:
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

void father_process(Plane *plane){
    char* key = malloc(SIZEKEY);
    int integer;
    int flags = fcntl(pipeDescriptor[0], F_GETFL, 0);
    fcntl(pipeDescriptor[0], F_SETFL, flags | O_NONBLOCK);
    int quit = 1;
    while(quit){
        close(pipeDescriptor[1]);
        integer = read(pipeDescriptor[0], key, SIZEKEY);
        usleep(75000);
        if(integer < 0 && errno == EAGAIN){
            movePlane(plane);
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
