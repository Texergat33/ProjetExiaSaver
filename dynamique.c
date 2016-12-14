#include <stdio.h>
#include <stdlib.h>
#include "PBM.h"

PBM createBlankPBM()
{
    PBM pbm;
    for(int i=0; i<80, i++)
    {
        for(int j=0, j<24, j++)
        {
            pbm.image[i][j] = 0;
        }
    }
}

void placePBM (PBM *dst, PBM *source, int x, int y)
{
    for(int i = 0, i < source->length, i++)
    {
        for(int j = 0, i < source->width, j++)
        {
            dst->image[(x+i)%dst->length][y+j] = source->image[i][j];
        }
    }
}
