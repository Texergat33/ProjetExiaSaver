#include "PBM.h"

void loadPBM(FILE *file, PBM* p)
{
    char readFile[71] = "";
    int binaryPBM;

    fgets(readFile, 71, file);
    while (fgets(readFile, 71, file) != NULL)
    {
        for(int z = 0; z < p->length; z++)
        {
            for(int k = 0; k < p->width; k++)
            {
                fscanf(file, "%d", &binaryPBM);
                p->image[k + ((80 - p->width)/2)][z + ((24 - p->length)/2)] = binaryPBM;
            }
        }
    }
}

void readResolution(FILE *file, PBM* p)
{
    char readLine[10] = "";
    int a, b;
    for(int i = 0; i < 1; i++)
    {
        fgets(readLine, 71, file);
    }
    fscanf(file, "%d %d", &(p->width), &(p->length));
}

void printPBM(PBM p)
{
	char c[] = {226, 150, 136, 0};
    for (int i = 0 ;i < 24; i++)
    {
        for (int j = 0;j < 80; j++)
        {
            if(p.image[j][i] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%s", c);
            }
        }
        printf("\n");
    }
}

PBM createBlankPBM()
{
    PBM pbm;
    for(int i=0; i<80; i++)
    {
        for(int j=0; j<24; j++)
        {
            pbm.image[i][j] = 0;
        }
    }
    return pbm;
}

void placePBM (PBM *dst, PBM *source, int x, int y)
{
    for(int i = 0; i < source->length; i++)
    {
        for(int j = 0; i < source->width; j++)
        {
            dst->image[(x+i)%dst->length][y+j] = source->image[i][j];
        }
    }
}
