/*
question link : https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of stairs : ";
    cin >> n;
    int arr[n];
    cout << "Enter height array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }

        dp[i] = min(right, left);
    }
    cout << dp[n - 1];
}