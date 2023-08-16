/*

https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number Houses : ";
    cin >> n;
    int arr[n];
    cout << "Enter  array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    int prev2 = 0;
    int prev1 = temp[0];
    for (int i = 1; i < n - 1; i++)
    {
        int pick = temp[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int not_pick = prev1;
        int curr = max(pick, not_pick);

        prev2 = prev1;
        prev1 = curr;
    }

    int leaveFirst = prev1;

        for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i];
    }
    prev2 = 0;
    prev1 = temp[0];
    for (int i = 1; i < n - 1; i++)
    {
        int pick = temp[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int not_pick = prev1;

        int curr = max(pick, not_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    int leaveLast = prev1;
    cout << max(leaveFirst, leaveLast);
}