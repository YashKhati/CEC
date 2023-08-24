#include <iostream>
using namespace std;
bool IsTarget(int arr[], int target, int indx)
{
    if (target == 0)
    {
        return true;
    }
    if (indx < 0)
    {
        return false;
    }
    bool notTake = IsTarget(arr, target, indx - 1);

    bool take = false;
    if (arr[indx] <= target)
    {
        take = IsTarget(arr, target - arr[indx], indx - 1);
    }

    return take || notTake;
}
int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target : ";
    cin >> target;

    if (IsTarget(arr, target, n - 1))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}