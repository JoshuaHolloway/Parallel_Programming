#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

char msg[50] = "uninitialized";

void *WatchMessage() {
    printf("Address of msg is %p and msg = %s \n", &msg, msg);
    sleep(2);
    printf("A few seconds later, msg = ");
}

void *ChangeMessage() {
    strcpy(msg, "I'm a little teapot, short and stout");
}

int main() {
    //pthread_t thr;
    //pthread_create(&thr, NULL, WatchMessage, NULL); // Now WatchMessage is exectured in a seperate thread
    WatchMessage();
    ChangeMessage();
}