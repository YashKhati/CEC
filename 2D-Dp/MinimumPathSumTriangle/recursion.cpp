/*
https://www.codingninjas.com/studio/problems/triangle_1229398?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int getMinumumSum(vector<vector<int>> &vec, int i, int j, int rows)
{
    if (i == rows - 1)
    {
        return vec[i][j];
    }

    int down = vec[i][j] + getMinumumSum(vec, i + 1, j, rows);

    int downRight = vec[i][j] + getMinumumSum(vec, i + 1, j + 1, rows);

    return min(down, downRight);
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
    cout << getMinumumSum(vec, 0, 0, rows);
}
