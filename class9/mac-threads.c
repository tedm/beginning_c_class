/*

This program was written by Phill of SCN

This demonstrates race conditions

Consider a gym that keeps milk on hand for protien shakes.
When they run out, someone needs to buy more.
Each thread represents a member of the gym.
They are not very organized, so they can buy too much or not have enough.
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NUMBER_OF_THREADS 10
#define MIN_MILK 2
#define MILK_PER_NEW_UNIT 6

int milk = MILK_PER_NEW_UNIT;

unsigned long long negative_milk_counter = 0;
unsigned long long too_much_milk_counter = 0;

// safe place in memory to store thread completion times
clock_t end_times[NUMBER_OF_THREADS];

void milk_check() {
    
    // this function attempts to mitigate the race
    // condition by storing the global value locally
    int milk_state = milk;
    
    // increase the counter if the gym has negative milk
    if (milk_state < 0) negative_milk_counter++;
    
    // the fridge can only hold 2 units of milk
    if (milk_state > 2*MILK_PER_NEW_UNIT)
        too_much_milk_counter++;

    // due to race conditions, there is no garuntee these values are correct
}


// common task for all threads to complete
void *thread_task(void *arg) {
    
    // you can pass a struct if you need a lot of data
    // notice how the castings are constructed
    int thread_number = (int)*(int*)arg;
    
    // measure how long each thread takes to process
    time_t start_time = time(NULL);
    
    // notice how this is not always in the same order
    printf("starting thread %d\n", thread_number);
    
    // simulate several uses of milk from the fridge
    // this number will need to be adjusted to your system's conditions
    // too few and the time demonstration is not meaningful
    // too many and your just sitting there waiting for the program to finish running
    for (int x = 0; x < (INT_MAX/8); x++) {
        
        // get more milk and verify amount of milk
        if (milk < MIN_MILK) milk += MILK_PER_NEW_UNIT;
        milk_check();
        
        // simulate using the milk then verify amount of milk
        milk--;
        milk_check();
    }

    // display the completion time
    printf("thread %d completed in %lu seconds\n",
        thread_number,
        time(NULL) - start_time);
    
    // return this pointer to measure how long the thread waits before joining
    end_times[thread_number] = clock();
    return (void*)&end_times[thread_number];
}

int main() {
    
    // pointers to the threads
    pthread_t threads[NUMBER_OF_THREADS];
    
    // numerical index of threads passed to each thread to identify itself
    int thread_number[NUMBER_OF_THREADS];

    // start the threads
    for (int x = 0; x < NUMBER_OF_THREADS; x++) {
        
        // this value needs to be stored in a safe place so the thread can access it
        thread_number[x] = x;
        
        // start a thread
        pthread_create(&threads[x], NULL, thread_task, &thread_number[x]);
        
        // display confirmation of the call
        printf("called thread %d at %lx\n", x, threads[x]);
    }

    // loop for rejoining the threads
    for (int x = 0; x < NUMBER_OF_THREADS/3; x++) {
        
        // place to hold the return sent from the thread
        void *end_time = NULL;
        
        // wait for each thread in order to rejoin
        // notice how some threads finish sooner than they rejoin
        pthread_join(threads[x], &end_time);
        
        // calculate how long the thread has been waiting to rejoin
        clock_t time_diffrence = clock() - (clock_t)*(clock_t*)end_time;
        
        // convert clock units to miliseconds
        double total = 1000.0 * time_diffrence / CLOCKS_PER_SEC;
        
        // display the rejoin information
        printf("thread %d returned after waiting %.2f ms\n", x, total);        
    }

    // show the error counters
    printf("negative counter: %llu\n", negative_milk_counter);
    printf("too much counter: %llu\n", too_much_milk_counter);

    return EXIT_SUCCESS;
}