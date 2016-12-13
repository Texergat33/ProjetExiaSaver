#include "fork.h"
pid_t create_process(void){
    pid_t pid;
    do {
    pid = fork();
    } while ((pid == -1) && (errno == EAGAIN));
    return pid;
}
