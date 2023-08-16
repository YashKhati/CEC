/*

https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int houseRobber(vector<int> dp, int arr[], int n)
{
    if (n == 0)
    {
        return dp[n] = arr[n];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int pick = arr[n];
    if (n > 1)
    {
        pick += houseRobber(dp, arr, n - 2);
    }
    int notPick = 0 + houseRobber(dp, arr, n - 1);

    return dp[n] = max(pick, notPick);
}

int main()
{
    int n;
    cout << "Enter number Houses : ";
    cin >> n;
    int arr[n];
    cout << "Enter  array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n - 1, -1);
    int temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    int leaveFirst = houseRobber(dp, temp, n - 2);

    fill(dp.begin(), dp.end(), -1);
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    int leaveLast = houseRobber(dp, temp, n - 2);

    cout << max(leaveFirst, leaveLast);
}