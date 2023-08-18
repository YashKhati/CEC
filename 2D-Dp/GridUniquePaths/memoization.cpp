/*
https://www.codingninjas.com/studio/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <iostream>
#include <vector>
using namespace std;
int help(vector<vector<int>> &dp, int i, int j)
{

    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return dp[i][j] = 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = help(dp, i - 1, j) + help(dp, i, j - 1);
}
int main()
{
    int m, n;
    cout << "Enter value of M and N  : ";
    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n, -1));
    cout << "Unique Path : " << help(vec, m - 1, n - 1);
}