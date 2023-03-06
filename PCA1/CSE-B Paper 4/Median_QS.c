#include <stdio.h>

// function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to partition the array using the median as the pivot
int partition(int arr[], int low, int high, int pivot) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
        else if (arr[j] == pivot) {
            // move the pivot element to the end of the array
            swap(&arr[j], &arr[high]);
            j--;
        }
    }
    // move the pivot element to its correct position
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// function to find the median of an unsorted array
int find_median(int arr[], int n) {
    // sort the array using selection sort
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
    // return the median element
    return arr[n/2];
}

// function to implement quick sort using the median as the pivot
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // find the median of the array and use it as the pivot
        int pivot = find_median(arr + low, high - low + 1);
        // partition the array using the pivot
        int pi = partition(arr, low, high, pivot);
        // recursively sort the left and right subarrays
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // find the median of the array
    int median = find_median(arr, n);
    printf("Median of the array is: %d\n", median);
    // sort the array using quick sort with median as the pivot
    quick_sort(arr, 0, n-1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
