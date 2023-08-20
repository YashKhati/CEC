
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row;
    cout << "Enter value of Rows Of triangle :  ";
    cin >> row;

    int **arr = new int *[row];
    int size = 1;
    for (int i = 0; i < row; i++)
    {
        *(arr + i) = new int[size];
        size++;
    }

    // Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Triangle Elements : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}