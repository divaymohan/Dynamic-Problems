#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int n;
    fscanf(fp, "%d", &n);
    int in[n][n];
    int out[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                in[i][j] = 0;
                out[i][j] = 0;
            }
            else
            {
                out[i][j] = 0;
                fscanf(fp, "%d", &in[i][j]);
            }
        }
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            int q = in[i - 1][j - 1];
            for (int k = i + 1; k < j; k++)
            {

                int min = out[i][k] + out[k][j];
                if (min < q)
                {
                    q = min;
                }
            }
            out[i][j] = q;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", out[i][j]);
        }
        printf("\n");
    }
    printf("Cost : %d", out[1][n]);

    return 0;
}