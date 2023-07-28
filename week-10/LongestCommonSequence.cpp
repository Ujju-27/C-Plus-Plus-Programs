#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void printLongestCommonSubsequence(char *sequence1, char *sequence2, int length1, int length2)
{
    int dp[length1 + 1][length2 + 1];

    // Build the dp[][] array in a bottom-up manner
    for (int i = 0; i <= length1; i++)
    {
        for (int j = 0; j <= length2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (sequence1[i - 1] == sequence2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Find the length of the longest common subsequence
    int lcsLength = dp[length1][length2];

    // Store the longest common subsequence
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';

    // Traverse the dp[][] array to construct the longest common subsequence
    int i = length1, j = length2;
    while (i > 0 && j > 0)
    {
        if (sequence1[i - 1] == sequence2[j - 1])
        {
            lcs[lcsLength - 1] = sequence1[i - 1];
            i--;
            j--;
            lcsLength--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of the longest common subsequence: " << dp[length1][length2] << endl;
}

int main()
{
    char sequence1[100], sequence2[100];
    cout << "Enter sequence 1: ";
    cin >> sequence1;
    cout << "Enter sequence 2: ";
    cin >> sequence2;

    int length1 = strlen(sequence1);
    int length2 = strlen(sequence2);

    printLongestCommonSubsequence(sequence1, sequence2, length1, length2);

    return 0;
}
