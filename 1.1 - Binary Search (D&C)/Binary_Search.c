#include <stdio.h>

int binary_search(int arr[], int left, int right, int x) {
    if (left > right) {
        // Element not found
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == x) {
        // Element found at mid index
        return mid;
    }
    else if (arr[mid] > x) {
        // Element is in left subarray
        return binary_search(arr, left, mid - 1, x);
    }
    else {
        // Element is in right subarray
        return binary_search(arr, mid + 1, right, x);
    }
}

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    
    int result = binary_search(arr, 0, n - 1, x);
    
    if (result == -1) {
        printf("Element not found");
    }
    else {
        printf("Element found at index %d", result);
    }
    
    return 0;
}
