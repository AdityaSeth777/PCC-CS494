#include<stdio.h>

int count(int S[], int m, int n)
{
    int i, j, x, y;

    int table[n+1][m];

    for (i=0; i<m; i++)
        table[0][i] = 1;

    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            y = (j >= 1)? table[i][j-1]: 0;

            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

int main()
{
    int i, N, m;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Enter the number of coins: ");
    scanf("%d", &m);

    int S[m];
    printf("Enter the values of coins:\n");
    for (i=0; i<m; i++)
        scanf("%d", &S[i]);

    printf("The number of ways to make change for %d cents is %d", N, count(S, m, N));

    return 0;
}
