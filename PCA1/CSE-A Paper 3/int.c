#include <stdio.h>

int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int a[n], count[2] = {0};  // initialize count array to 0

    printf("Enter the %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i] % 2]++;  // increment count for even/odd elements
    }

    if (count[0] == n || count[1] == n) {  // check if all elements are even or odd
        printf("No interesting array exists.\n");  // if all elements are even or odd, no interesting array exists
        return 0;
    }

    printf("The interesting array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);  // print even elements first
        if (a[i] % 2 == 0) {
            count[0]--;  // decrement count of even elements
            if (count[0] == 0) {
                for (int j = i+1; j < n; j++) {
                    if (a[j] % 2 != 0) {
                        printf("%d ", a[j]);  // print odd elements after even elements
                    }
                }
                break;  // exit loop once all odd elements have been printed
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            printf("%d ", a[i]);  // print remaining odd elements
        }
    }
    printf("\n");
    return 0;
}
