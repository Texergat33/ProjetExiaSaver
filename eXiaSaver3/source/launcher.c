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

void movePlane(Plane* plane, char* direction){
    plane->direction = direction;
    if(strcmp(direction, "left") == 0);
    else if(strcmp(direction, "up") == 0);
    else if(strcmp(direction, "right") == 0);
    else if(strcmp(direction, "down") == 0);
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
    int quit = 1;
    while(quit){
        close(pipeDescriptor[1]);
        read(pipeDescriptor[0], key, SIZEKEY);
        switch(*key){
            case 'q':
                quit = 0;
                break;
            case 'l':
                movePlane(plane, "left");
                break;
            case 'u':
                movePlane(plane, "up");
                break;
            case 'r':
                movePlane(plane, "right");
                break;
            case 'd':
                movePlane(plane, "down");
                break;
            default:
                break;
        }
    }
    free(key);
}
