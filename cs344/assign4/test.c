#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT_TO 10000000
#define NUM_THREADS 3

// Declare a mutex
// pthread_mutex_t counterMutex;

//counter is a variable shared by all the threads
int counter = 0;

void* perform_work(void* argument){

     for(int i = 0; i < COUNT_TO; i++){
         // Try to acquire the lock before entering the critical section
         pthread_mutex_lock(&counterMutex);

         // THE CRITICAL SECTION STARTS
         counter += 1;
         // THE CRITICAL SECTION ENDS

         // Unlock the mutex
         pthread_mutex_unlock(&counterMutex);
     }
     return NULL;
}

int main(void){
    // Initialize the mutex
    pthread_mutex_init(&counterMutex, NULL);

    pthread_t threads[NUM_THREADS];
    // Start NUM_THREADS threads
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, perform_work, NULL);
    }

    // Wait for the threads to terminate
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
                 
    // Destroy the mutex
                                                                     
    pthread_mutex_destroy(&counterMutex);                                                                   
    printf("Expected value of counter = %d\n", COUNT_TO * NUM_THREADS);                                                              printf("Actual value of counter = %d\n", counter);                                                                       
    exit(EXIT_SUCCESS);
}
