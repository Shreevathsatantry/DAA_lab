#include <stdio.h>

int main() {
    // Given array to be heapified
    int H[] = {0, 9, 6, 7, 5, 4, 2, 3, 8}; 
    int n = sizeof(H) / sizeof(H[0]) - 1; // Number of elements in the array

    // Display array before heapify
    printf("Array before heapify: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Heapify the array
    for (int i = n / 2; i >= 1; i--) {
        int k = i; // Current index
        int v = H[k]; // Value at current index
        int heap = 0; // Flag to indicate if heap property is satisfied
        // Adjust the heap starting from index k
        while (!heap && 2 * k <= n) {
            int j = 2 * k; // Left child index
            // Compare left and right children to find the larger child
            if (j < n && H[j] < H[j + 1]) {
                j++;
            }
            // If the value at index k is greater than or equal to the value at the larger child index j, heap property is satisfied
            if (v >= H[j]) {
                heap = 1;
            }
            // If not, swap the value at index k with the value at index j, and continue adjusting the heap from index j
            else {
                H[k] = H[j];
                k = j;
            }
        }
        // Place the original value v at its correct position in the heap
        H[k] = v;
    }

    // Display array after heapify
    printf("Array after heapify: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
