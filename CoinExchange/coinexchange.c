#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int coinExchange(int *, int, int);
int min(int, int);

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int t;
    fscanf(fp, "%d", &t);
    while (t--)
    {
        int k;

        fscanf(fp, "%d", &k);

        int Coins[k];
        for (int i = 0; i < k; i++)
        {
            fscanf(fp, "%d", &Coins[i]);
        }
        int Price;
        fscanf(fp, "%d", &Price);

        //getting Number Of Coins
        int ncoin = coinExchange(Coins, k, Price);
        printf("\nNumber Of Coins Required :: %d\n", ncoin);
    }

    return 0;
}
int coinExchange(int *in, int k, int price)
{
    int dp[k + 1][price + 1];
    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= price; i++)
    {
        dp[0][i] = 9999;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= price; j++)
        {
            if (j >= in[i - 1])
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - in[i - 1]] + 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= price; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("\n\nSolution Vector\n\n");
    int i = k;
    int j = price;

    while (dp[i][j] != 9999 && dp[i][j] != 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i = i - 1;
        }
        else
        {
            printf("%d ", in[i - 1]);
            j = j - in[i - 1];
        }
    }

    return dp[k][price];
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}