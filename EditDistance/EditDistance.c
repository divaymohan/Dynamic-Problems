#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 20
int min(int, int, int);
int editDistance(char *, char *);
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int t;
    fscanf(fp, "%d", &t);
    while (t--)
    {
        printf("\nTEST-CASE%d", t + 1);
        char str1[MAX];
        char str2[MAX];
        fscanf(fp, "%s", str1);
        fscanf(fp, "%s", str2);
        //find out the edit distance
        int dist = editDistance(str1, str2);
        printf("\nThe Edit Distance is :: %d", dist);
    }
    return 0;
}
int editDistance(char *str1, char *str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int resultMat[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; i++)
    {
        resultMat[0][i] = INT_MAX;
        resultMat[i][0] = 0;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (str2[i - 1] == str2[j - 1])
            {
                resultMat[i][j] = resultMat[i - 1][j - 1];
            }
            else
            {
                resultMat[i][j] = min(resultMat[i - 1][j - 1], resultMat[i - 1][j], resultMat[i][j - 1]) + 1;
            }
        }
    }
    return resultMat[l1][l2];
}
int min(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
    }
    return c;
}