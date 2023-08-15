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
    int prev2 = 0;
    int prev1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += prev2;
        }
        int nottake = prev1;

        int curr = max(take, nottake);

        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
}
