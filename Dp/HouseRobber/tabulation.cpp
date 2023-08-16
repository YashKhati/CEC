/*

https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

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

    vector<int> dp(n - 1, 0);
    int temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i + 1];
    }
    dp[0] = temp[0];

    for (int i = 1; i < n - 1; i++)
    {
        int pick = temp[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
    }

    int leaveFirst = dp[n - 2];

    fill(dp.begin(), dp.end(), -1);
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        int pick = temp[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int not_pick = dp[i - 1];

        dp[i] = max(pick, not_pick);
    }
    int leaveLast = dp[n - 2];
    cout << max(leaveFirst, leaveLast);
}