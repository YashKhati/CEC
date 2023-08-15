/*
https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <iostream>
using namespace std;
int maxSum(int arr[], int dp[], int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int pick = arr[n] + maxSum(arr, dp, n - 2);

    int notPick = 0 + maxSum(arr, dp, n - 1);
    return dp[n] = max(pick, notPick);
}

int main()
{
    int n;
    cout << "Array Size : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }
    cout << maxSum(arr, dp, n - 1);
}
