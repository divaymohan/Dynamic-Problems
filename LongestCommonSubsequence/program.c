#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

int getLongestCommonSubSequenceByRecursion(char *, char *, int, int);
int getLongestCommonSubSequenceByDynamic(char *, char *, int, int);
int max(int, int);

int main(int argc, char *argv[])
{
    time_t start, end;
    float sec;
    //file pointer for input file
    FILE *fp;
    //opening the input file in reading mode
    fp = fopen(argv[1], "r");
    //let's read the test cases in variable t
    int t;
    fscanf(fp, "%d", &t);

    //loop for all the test cases
    while (t--)
    {
        printf("\nTEST CASE-%d\n", t + 1);
        //declare the variable to hold string 1
        char str1[MAX];
        //declare the variable to hold string 2
        char str2[MAX];
        //reading the strign 1 from input file
        fscanf(fp, "%s", str1);
        // reading the string 2 from input file
        fscanf(fp, "%s", str2);
        //strl1 holds the length of string 1
        int strl1 = (int)strlen(str1);
        //strl2 holds the length of strign 2
        int strl2 = (int)strlen(str2);

        //lets get the length of longest common subsequence by recursion
        start = clock();
        int result = getLongestCommonSubSequenceByRecursion(str1, str2, strl1, strl2);
        printf("Length by Recursive Program:: %d", result);
        end = clock();
        sec = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime Taken %f", sec);

        start = clock();
        result = getLongestCommonSubSequenceByDynamic(str1, str2, strl1, strl2);
        printf("\nLength by Dynamic Program:: %d", result);
        end = clock();
        sec = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime Taken %f", sec);
    }

    return 0;
}

//function for getting length by recursion
int getLongestCommonSubSequenceByRecursion(char *str1, char *str2, int strl1, int strl2)
{
    //check first for base condition
    if (strl1 == 0 || strl2 == 0)
    {
        return 0;
    }
    //if we got a match
    if (str1[strl1 - 1] == str2[strl2 - 1])
    {
        return 1 + getLongestCommonSubSequenceByRecursion(str1, str2, strl1 - 1, strl2 - 1);
    }
    //if we do not get a match
    return max(getLongestCommonSubSequenceByRecursion(str1, str2, strl1, strl2 - 1), getLongestCommonSubSequenceByRecursion(str1, str2, strl1 - 1, strl2));
}
//function for getting length by dynamic
int getLongestCommonSubSequenceByDynamic(char *str1, char *str2, int strl1, int strl2)
{
    //create dynamic table
    int result[strl1 + 1][strl2 + 1];
    //initialize whole by zero
    for (int i = 0; i <= strl1; i++)
    {
        for (int j = 0; j <= strl2; j++)
        {
            result[i][j] = 0;
        }
    }
    //actual logic
    for (int i = 1; i <= strl1; i++)
    {
        for (int j = 1; j <= strl2; j++)
        {
            if (str1[i] == str2[j])
            {
                result[i][j] = 1 + result[i - 1][j - 1];
            }
            else
            {
                result[i][j] = max(result[i - 1][j], result[i][j - 1]);
            }
        }
    }
    return result[strl1][strl2];
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}