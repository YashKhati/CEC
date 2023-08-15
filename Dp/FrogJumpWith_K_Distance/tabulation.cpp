/*

https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of stairs : ";
    cin >> n;
    int k;
    cout << "Enter Value of K : ";
    cin >> k;
    int arr[n];
    cout << "Enter height array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minEnergy = INT_MAX;

    int dp[n] = {-1};
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int temp = dp[i - j] + abs(arr[i] - arr[i - j]);
                minEnergy = min(temp, minEnergy);
            }
        }
        dp[i] = minEnergy;
    }

    cout << dp[n - 1];
}