#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the size -> ");
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        printf ("Enter the numbers -> ");
        scanf("%d", &a[i]);
    }
    
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) {
            max3 = a[i];
        }
        
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2) {
            min2 = a[i];
        }
    }
    
    int result = (max1 - max2) * max3;
    int temp = (max1 - min1) * min2;
    if (temp > result) {
        result = temp;
    }
    
    printf("The max element is -> %d\n", result);
    
    return 0;
}