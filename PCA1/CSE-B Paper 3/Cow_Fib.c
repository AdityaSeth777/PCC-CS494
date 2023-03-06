#include <stdio.h>

int main() {
    int n, i, total_cows = 1, new_cows;
    printf("Enter the number of years: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        new_cows = total_cows; // each cow produces one new calf per year
        total_cows += new_cows;
    }

    printf("After %d years, the number of cows is %d\n", n, total_cows);
    return 0;
}
