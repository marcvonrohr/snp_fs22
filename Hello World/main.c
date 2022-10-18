#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define PI

static void* worker(void* args) {
    for(int i = 0; i < 2; i++) { sleep(2); printf("[%d]", i); }
}
void action(void);
pthread_t thread;
int main() {
    printf(""PI""); action(); printf("[end]");
}

void action(void) {
    pthread_create(&thread, NULL, worker, NULL);
    sleep(3);
    printf("[action]");

}
