/*
https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <iostream>
using namespace std;
int maxSum(int arr[], int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (n < 0)
    {
        return 0;
    }
    int pick = maxSum(arr, n - 2) + arr[n];

    int notPick = maxSum(arr, n - 1);
    return max(pick, notPick);
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

    cout << maxSum(arr, n - 1);
}
