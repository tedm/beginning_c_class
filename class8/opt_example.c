// opt_example.c

#include <stdio.h>
#include <time.h>

// A sample function to demonstrate timing
void sample_function() {
    long long sum = 0;
    for (long long i = 0; i < 1000000000; i++) {
        sum += i;
    }
    printf("Sum calculated: %lld\n", sum);
}

int main() {
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock(); // Record start time
    sample_function();    // Call the function to be timed
    end_time = clock();   // Record end time

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time in seconds

    printf("sample_function() took %f seconds to execute.\n", time_taken);

    return 0;
}
