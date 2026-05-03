
#include <stdio.h>

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        
        // Perform insertion sort for this gap
        for (i = gap; i < n; i++) {
            temp = arr[i];

            // Shift earlier gap-sorted elements up
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}















