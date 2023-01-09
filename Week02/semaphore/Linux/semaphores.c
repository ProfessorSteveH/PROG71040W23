// PROG71040 W23 - Week02 - Prof SteveH
//
// C program to demonstrate working of Semaphores 
//adapted from https://www.geeksforgeeks.org/use-posix-semaphores-c/

#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
  
void* thread(void* arg) 
{ 
    //wait 
    sem_wait(&mutex); 
    printf("\nEntered..\n"); 
  
    //critical section 
    sleep(4); 
      
    //signal 
    printf("\nJust Exiting...\n"); 
    sem_post(&mutex); 
    return 0;
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 	//create a new thread
    sleep(2); 					//sleep 2 seconds
    pthread_create(&t2,NULL,thread,NULL); 	//create another new thread - but this one has to wait
    			 			// for the first thread to finish (about 2 seconds)
    pthread_join(t1,NULL); 			
    pthread_join(t2,NULL); 			//rejoin the threads, aka wait for each of them to finish

    sem_destroy(&mutex); 
    return 0; 
} 

