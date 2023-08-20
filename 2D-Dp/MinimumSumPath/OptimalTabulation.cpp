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

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[0] = vec[0][0];
                continue;
            }
            int up = 1e9, left = 1e9;
            if (i > 0)
            {
                up = vec[i][j] + prev[j];
            }

            if (j > 0)
            {
                left = vec[i][j] + curr[j - 1];
            }

            curr[j] = min(up, left);
        }
        prev = curr;
    }
    cout << "Minimum Cost : " << prev[n - 1] << endl;
}