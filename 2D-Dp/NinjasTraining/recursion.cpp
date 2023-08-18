/*
https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int MaxPoints(vector<vector<int>> &points, int day, int lastDay)
{
    int maxPoints = 0;

    if (day == 0)
    {
        for (int i = 0; i <= 2; i++)
        {
            if (i != lastDay)
            {
                maxPoints = max(maxPoints, points[0][i]);
            }
        }
        return maxPoints;
    }
    for (int i = 0; i <= 2; i++)
    {
        if (i != lastDay)
        {
            int point = points[day][i] + MaxPoints(points, day - 1, i);
            maxPoints = max(maxPoints, point);
        }
    }
    return maxPoints;
}
int main()
{
    int n;
    cout << "Enter number of Days : ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3, 0));
    cout << "Enter Points Array : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp;
            cin >> temp;
            points[i][j] = temp;
        }
    }

    cout << MaxPoints(points, n - 1, 3);
}