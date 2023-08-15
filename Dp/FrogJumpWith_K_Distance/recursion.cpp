/*

https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

#include <iostream>
#include <limits.h>
using namespace std;
int findMinimumEnergy(int arr[], int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int temp = findMinimumEnergy(arr, n - i, k) + abs(arr[n] - arr[n - i]);
            minEnergy = min(temp, minEnergy);
        }
    }
    return minEnergy;
}

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

    cout << findMinimumEnergy(arr, n - 1, k);
}