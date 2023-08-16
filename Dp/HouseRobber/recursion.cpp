/*

https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

*/

#include <iostream>
#include <limits.h>
using namespace std;
int houseRobber(int arr[], int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (n < 0)
    {
        return 0;
    }
    int pick = arr[n];
    if (n > 1)
    {
        pick += houseRobber(arr, n - 2);
    }
    int notPick = 0 + houseRobber(arr, n - 1);

    return max(pick, notPick);
}

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
    int leaveFirst = houseRobber(temp, n - 2);

    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = arr[i];
    }
    int leaveLast = houseRobber(temp, n - 2);

    cout << max(leaveFirst, leaveLast);
}