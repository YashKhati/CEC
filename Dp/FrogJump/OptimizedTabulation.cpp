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

    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(arr[i] - arr[i - 2]);
        }

        int curr = min(right, left);

        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
}