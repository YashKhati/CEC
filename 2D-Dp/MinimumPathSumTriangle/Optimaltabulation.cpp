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

    vector<int> next(rows, 0);
    vector<int> curr(rows, 0);
    for (int i = 0; i < rows; i++)
    {
        next[i] = vec[rows - 1][i];
    }

    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = vec[i][j] + next[j];
            int downRight = vec[i][j] + next[j + 1];

            curr[j] = min(down, downRight);
        }
        next = curr;
    }
    cout << next[0] << endl;
}
