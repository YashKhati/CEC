#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
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

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = vec[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = vec[n - 1][j1] + vec[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {

            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++)
                {
                    int ans = 0;
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (j1 == j2)
                        {
                            ans = vec[i][j1];
                        }
                        else
                        {
                            ans = vec[i][j1] + vec[i][j2];
                            if (j1 + di >= 0 && j1 + di < m && j2 + dj >= 0 && j2 + dj < m)
                            {
                                ans += dp[i + 1][j1 + di][j2 + dj];
                            }
                            else
                            {
                                ans += -1e8;
                            }
                                                }

                        maxi = max(maxi, ans);
                    }
                }
                return dp[i][j1][j2] = maxi;
            }
        }
    }
}