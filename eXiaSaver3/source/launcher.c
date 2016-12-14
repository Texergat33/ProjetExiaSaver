#include "launcher.h"
#define SIZEKEY 256

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

void father_process(){
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
                //deplacer vers la gauche
                break;
            case 'u':
                //deplacer vers le haut
                break;
            case 'r':
                //deplacer vers la droite
                break;
            case 'd':
                //deplacer vers le bas
                break;
            default:
                break;
        }
    }
    free(key);
}
