#include <stdio.h>
#include <stdlib.h>
#include "PBM.h"

void createHour()
{
    for(int i=0; i<80, i++)
    {
        for(int j=0, j<24, j++)
        {
            PBM.image[i][j] = " ";
        }
    }
}

void placePBM (PBM dst, PBM source, int x, int y)
{
    for(int i = 0, i < source->length, i++)
    {
        for(int j = 0, i < source->width, j++)
        {
            dst->image[x+i][y+j]%dst->length;
            source->image[i][j];
        }
    }
}
