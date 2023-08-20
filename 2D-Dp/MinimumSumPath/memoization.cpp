/*
https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

https://leetcode.com/problems/minimum-path-sum/

*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int help(vector<vector<int>> &vec, vector<vector<int>> &dp, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    if (i == 0 && j == 0)
    {
        return dp[i][j] = vec[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = vec[i][j] + help(vec, dp, i, j - 1);

    int up = vec[i][j] + help(vec, dp, i - 1, j);
    return dp[i][j] = min(left, up);
}
int main()
{
    int m, n;
    cout << "Enter value of M and N  : ";
    cin >> m >> n;

    vector<vector<int>> vec(m, vector<int>(n, 0));

    cout << "Enter matrix : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            vec[i][j] = temp;
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << "Minimum Path : " << help(vec, dp, m - 1, n - 1);
}