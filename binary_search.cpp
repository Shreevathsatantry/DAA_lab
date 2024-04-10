#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[SIZE];

    srand(time(NULL));

    printf("Randomly generated 50 sorted numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array in ascending order
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    int position = binarySearch(arr, SIZE, target);

    if (position != -1)
        printf("Number %d found at position %d.\n", target, position + 1);
    else
        printf("Number %d not found in the list.\n", target);

    return 0;
}
