// PROG71040 W23 - Week02 - Prof SteveH
//
// a simple pthread example 
// compile with -lpthread

#include<pthread.h>
#include<stdio.h>
#include <stdint.h>



// create the function to be executed as a thread
void *thread(void *ptr)
{
    uintptr_t type = (uintptr_t) ptr;
    fprintf(stderr,"Thread - %ld\n",type);
    return  ptr;
}

int main(int argc, char **argv)
{
    // create the thread objs
    pthread_t thread1, thread2;
    unsigned long thr = 1;
    unsigned long thr2 = 2;
    // start the threads
    pthread_create(&thread1, NULL, *thread, (uintptr_t *) thr);
    pthread_create(&thread2, NULL, *thread, (uintptr_t *) thr2);
    // wait for threads to finish
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}
