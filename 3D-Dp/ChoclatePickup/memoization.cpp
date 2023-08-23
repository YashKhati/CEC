#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int helper(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= col || j2 >= col)
    {
        return INT_MIN;
    }
    if (i == row - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        int ans;
        for (int dj = -1; dj <= 1; dj++)
        {
            if (j1 == j2)
            {
                ans = grid[i][j1];
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + di, j2 + dj, row, col, grid, dp);
            }

            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int main()
{
    int m, n;
    cout << "Enter row and colums : ";
    cin >> n >> m;
    vector<vector<int>> vec(m, vector<int>(n, 0));
    cout << "Enter matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            vec[i][j] = temp;
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << helper(0, 0, m - 1, n, m, vec, dp);
}