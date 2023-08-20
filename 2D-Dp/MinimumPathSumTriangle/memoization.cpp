/*
https://www.codingninjas.com/studio/problems/triangle_1229398?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int getMinumumSum(vector<vector<int>> &vec, vector<vector<int>> &dp, int i, int j, int rows)
{
    if (i == rows - 1)
    {
        return vec[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = vec[i][j] + getMinumumSum(vec, dp, i + 1, j, rows);

    int downRight = vec[i][j] + getMinumumSum(vec, dp, i + 1, j + 1, rows);

    return dp[i][j] = min(down, downRight);
}
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
    vector<vector<int>> dp(rows, vector<int>(rows, -1));
    cout << getMinumumSum(vec, dp, 0, 0, rows);
}
