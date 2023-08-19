/*
https://www.codingninjas.com/studio/problems/unique-paths-ii_977241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


https://leetcode.com/problems/unique-paths-ii/description/
*/

#include <vector>
#include <iostream>
using namespace std;
int help(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i >= 0 || j >= 0 || matrix[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
    {
        return dp[i][j] = 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = 0, left = 0;

    up = help(i - 1, j, matrix, dp);

    left = help(i, j - 1, matrix, dp);

    return dp[i][j] = up + left;
}
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

    cout << "Unique Path : " << help(m - 1, n - 1, matrix, dp);
}