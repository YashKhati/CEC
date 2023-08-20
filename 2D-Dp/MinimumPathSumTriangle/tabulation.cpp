/*
https://www.codingninjas.com/studio/problems/triangle_1229398?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    int rows;
    cout << "Enter rows: ";
    cin >> rows;

    vector<vector<int>> vec;
    cout << "Enter triangle Elements : ";
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i + 1; j++)
        {
            int ele;
            cin >> ele;
            temp.push_back(ele);
        }
        vec.push_back(temp);
    }
    vector<vector<int>> dp(rows, vector<int>(rows, 0));

    for (int i = 0; i < rows; i++)
    {
        dp[rows - 1][i] = vec[rows - 1][i];
    }

    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = vec[i][j] + dp[i + 1][j];
            int downRight = vec[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, downRight);
        }
    }
    cout << dp[0][0] << endl;
}
