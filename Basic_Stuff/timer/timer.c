#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    time_t mytime;
    struct tm *time_ptr;
    mytime = time(NULL);
    printf("%s\n", ctime(&mytime));

    // This can be used to seed random-number generator
    time_t T = time(NULL); // epoch time
    printf("Number of seconds elapsed sice Jan 1 1970: %zd\n",T);

    // Get date
    char tm[100];
    strcpy(tm,ctime(&T));
    puts(tm);

    // Measure elapsed time between two points in code
    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    unsigned long i=0;
    while(i++ < 10000000) // spin the CPU
    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("some_long_computation took about %.5f seconds\n",
        ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
        ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));


    return 0;
}