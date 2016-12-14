#include "rand.h"
int rand_a_b(int a, int b){
    srand(time(NULL));
    int c = rand()%((b+1)-a)+a;
    return c;
}

