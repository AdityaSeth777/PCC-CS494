#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the size of arrays A and B: ");
    scanf("%d", &n);

    int A[n], B[n];
    printf("Enter the elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the elements of array B: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    int Amin = INT_MAX, Amax = INT_MIN, Bmin = INT_MAX, Bmax = INT_MIN;
    int min_diff = Amax - Amin, swaps = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < Amin) {
            Amin = A[i];
        }
        if (A[i] > Amax) {
            Amax = A[i];
        }
        if (B[i] < Bmin) {
            Bmin = B[i];
        }
        if (B[i] > Bmax) {
            Bmax = B[i];
        }
        if (Amax - Amin < Bmax - Bmin) {
            min_diff = Amax - Amin;
        } else {
            min_diff = Bmax - Bmin;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int diff1 = Amax - Amin;
            int diff2 = Bmax - Bmin;
            if (diff1 > diff2) {
                if (A[i] < B[j] && B[j] - A[i] < diff1 - diff2) {
                    int temp = A[i];
                    A[i] = B[j];
                    B[j] = temp;
                    Amin = INT_MAX, Amax = INT_MIN, Bmin = INT_MAX, Bmax = INT_MIN;
                    for (int k = 0; k < n; k++) {
                        if (A[k] < Amin) {
                            Amin = A[k];
                        }
                        if (A[k] > Amax) {
                            Amax = A[k];
                        }
                        if (B[k] < Bmin) {
                            Bmin = B[k];
                        }
                        if (B[k] > Bmax) {
                            Bmax = B[k];
                        }
                    }
                    swaps++;
                }
            } else {
                if (B[j] < A[i] && A[i] - B[j] < diff2 - diff1) {
                    int temp = A[i];
                    A[i] = B[j];
                    B[j] = temp;
                    Amin = INT_MAX, Amax = INT_MIN, Bmin = INT_MAX, Bmax = INT_MIN;
                    for (int k = 0; k < n; k++) {
                        if (A[k] < Amin) {
                            Amin = A[k];
                        }
                        if (A[k] > Amax) {
                            Amax = A[k];
                        }
                        if (B[k] < Bmin) {
                            Bmin = B[k];
                        }
                        if (B[k] > Bmax) {
                            Bmax = B[k];
                        }
                    }
                    swaps++;
                }
            }
        }
    }

