/*
https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <iostream>
using namespace std;

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
    dp[0] = arr[0];
    int neg = 0;
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += dp[i - 2];
        }
        int nottake = dp[i - 1];

        dp[i] = max(take, nottake);
    }

    cout << dp[n - 1];
}
