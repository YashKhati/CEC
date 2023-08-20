/*
https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

https://leetcode.com/problems/minimum-path-sum/

*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

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

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = vec[0][0];
                continue;
            }
            int up = 1e9, left = 1e9;
            if (i > 0)
            {
                up = vec[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = vec[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
        }
    }
    cout << "Minimum Cost : " << dp[m - 1][n - 1] << endl;
}