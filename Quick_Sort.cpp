#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partition function to assist QuickSort
int partition(int A[], int l, int r) {
    int pivot = A[r]; // Choosing the rightmost element as the pivot
    int i = l - 1;    // Index of smaller element

    // Iterate through elements from l to r-1
    for (int j = l; j <= r - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (A[j] <= pivot) {
            // Swap A[i+1] and A[j]
             i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap A[i+1] and A[r] to place the pivot in its correct position
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1; // Return the partitioning index
}

// Recursive QuickSort function
void quickSort(int A[], int l, int r) {
    if (l < r) {
        int s = partition(A, l, r); // Partitioning index
        // Recursively sort elements before and after partition
        quickSort(A, l, s - 1);
        quickSort(A, s + 1, r);
    }
}

int main() {
    // File operation to store time vs. n data
    FILE *fp = fopen("time_vs_n_quick.csv", "w");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fp, "n,time_taken\n");

    srand(time(NULL)); // Seed for random number generation

    // Experiment loop for different sizes of input data (n)
    for (int n = 100; n <= 2000; n += 100) {
        int A[n]; // Array to hold random data
        // Generate random data and fill the array
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 1000; // Generate random numbers between 0 and 999
        }

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start); // Start time measurement
        quickSort(A, 0, n - 1); // Perform QuickSort on the array
        clock_gettime(CLOCK_MONOTONIC, &end); // End time measurement

        // Calculate the time taken for sorting
        double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        // Write the data (n and time_taken) to the file
        fprintf(fp, "%d,%.6f\n", n, time_taken);
    }

    fclose(fp); // Close the file
    printf("Experiment completed. Results saved to time_vs_n_quick.csv.\n");
    return 0; // Exit the program
}
