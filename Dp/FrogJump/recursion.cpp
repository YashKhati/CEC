/*
question link : https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <iostream>
using namespace std;
int findMinimumEnergy(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int left = findMinimumEnergy(arr, n - 1) + abs(arr[n] - arr[n - 1]);

    if (n > 1)
    {
        int right = findMinimumEnergy(arr, n - 2) + abs(arr[n] - arr[n - 2]);
        return min(left, right);
    }
    return left;
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

    cout << findMinimumEnergy(arr, n - 1);
}