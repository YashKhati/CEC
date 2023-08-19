/*
https://www.codingninjas.com/studio/problems/unique-paths-ii_977241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


https://leetcode.com/problems/unique-paths-ii/description/
*/

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter value of M and N  : ";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Enter matrix : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= 0 && j >= 0 && matrix[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    cout << dp[m - 1][n - 1] << endl;
}