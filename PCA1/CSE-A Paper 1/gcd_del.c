#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], diff[n-1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i > 0) {
            diff[i-1] = abs(a[i] - a[i-1]);  // calculate absolute difference between adjacent elements
        }
    }
    int gcd = diff[0];  // initialize gcd to the first absolute difference
    for (int i = 1; i < n-1; i++) {
        gcd = __gcd(gcd, diff[i]);  // calculate gcd of all absolute differences
    }
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if (diff[i] != gcd) {
            count++;  // count the number of absolute differences that are not equal to gcd
        }
    }
    printf("%d", count);
    return 0;
}
