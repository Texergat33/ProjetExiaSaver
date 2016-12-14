#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct PBM PBM;
struct PBM
{
    int width;
    int length;
    char name[1024];
    int image[80][24];
};

void readResolution(FILE *file, PBM*);
void loadPBM(FILE *file, PBM*);
void printPBM(PBM);
PBM createBlankPBM();
void placePBM (PBM *dst, PBM *source, int x, int y);
