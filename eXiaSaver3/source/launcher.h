#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <stdio.h>
#include <stdlib.h>
#include "../../lib/PBM/PBM.h"
#include "../../lib/fork/fork.h"
#include "../../lib/rand/rand.h"
#include <unistd.h>

struct Plane{
    PBM img;
    char* direction;
    int posX, posY;
};
typedef struct Plane Plane;

int pipeDescriptor[2];
void child_process();
void father_process(Plane* plane);
void movePlane(Plane* plane, char* direction);
void randomDirection(Plane *plane);
void loadDirection(Plane *plane);

#endif
