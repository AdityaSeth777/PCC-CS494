This program implements the merge sort algorithm using the divide and conquer approach to sort an array of integers. Merge sort is a sorting algorithm that works by dividing an array into two halves, sorting each half recursively, and then merging the sorted halves back together. It has a time complexity of O(n log n), making it an efficient sorting algorithm for large datasets.

Now,
```bash
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

```

This is the merge function, which takes four arguments: the array to be sorted (arr), the indices for the left, middle, and right elements of the subarray to be merged (left, mid, and right respectively).

The function first calculates the sizes of the two subarrays to be merged (n1 and n2) and creates two temporary arrays (L and R) to hold the left and right subarrays respectively.

It then populates the L and R arrays by copying elements from the original array arr into the temporary arrays using two for loops. The L array contains the elements from left to mid, and the R array contains the elements from mid+1 to right.

The function then uses three counters (i, j, and k) to merge the two subarrays back into the original array in sorted order. The while loop continues as long as there are elements left in both L and R arrays. The loop compares the current elements at indices i and j of the two subarrays and copies the smaller element to the next available position in the original array. The loop then increments the relevant counters (i, j, and k) and continues until both L and R have been fully merged.

If there are still remaining elements in the L or R arrays, the function copies them back to the original array in order using two separate while loops.

```bash
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right

```