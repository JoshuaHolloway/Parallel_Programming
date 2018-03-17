// Compile C-program with intecl C-compiler
$ source /opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh intel64
$ source /opt/intel/parallel_studio_xe_2018.1.038/bin/psxevars.sh

$ icc -o pThreads pThreads.c

///-------------
// First version:
#include <stdio.h>
#include <unistd.h>

char msg[50] = "uninitialized";

void *WatchMessage(void *tid) {
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
    ChangeMessage();
}

///-------------

Modify to run methods in parallel via p-threads:
----

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

char msg[50] = "uninitialized";

void *WatchMessage(void *tid) {
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

