#include <stdio.h>
#include <limits.h>

void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            m[i][j] = 0;
        }
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("S matrix is: \n");
    for (int L = 1; L < n; L++)
    {
        for (int i = 1; i < n; i++)
        {
            printf("%d ", bracket[L][i]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
}
int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &dimensions[i]);
    }
    matrixChainOrder(dimensions, n + 1);

    return 0;
}