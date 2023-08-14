/*
question link : https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <iostream>
using namespace std;
int findMinimumEnergy(int arr[], int n, int dp[])
{
    if (n == 0)
    {
        return dp[n] = 0;
    }

    if (dp[n] != -1)
        return dp[n];

    int left = findMinimumEnergy(arr, n - 1, dp) + abs(arr[n] - arr[n - 1]);

    if (n > 1)
    {
        int right = findMinimumEnergy(arr, n - 2, dp) + abs(arr[n] - arr[n - 2]);
        return dp[n] = min(left, right);
    }
    return dp[n] = left;
}

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
        dp[i] = -1;
    }

    cout << findMinimumEnergy(arr, n - 1, dp);
}