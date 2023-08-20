/*
https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

https://leetcode.com/problems/minimum-path-sum/

*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int help(vector<vector<int>> &vec, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 1000;
    }
    if (i == 0 && j == 0)
    {
        return vec[i][j];
    }
    int left = vec[i][j] + help(vec, i, j - 1);

    int up = vec[i][j] + help(vec, i - 1, j);
    return min(left, up);
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
    cout << "matrix : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Minimum Path : " << help(vec, m - 1, n - 1);
}