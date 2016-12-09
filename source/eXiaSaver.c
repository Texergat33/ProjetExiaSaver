#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_a_b(int a, int b){
    int c = rand()%((b+1)-a)+a;
    return c;
}

int main(int argc, char* argv[]){
    system("clear");
    srand(time(NULL));
    int nbraleat = rand_a_b(1, 3);
    printf("%d\n", nbraleat);
    return 0;
}
