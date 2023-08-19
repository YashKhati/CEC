/*
https://www.codingninjas.com/studio/problems/unique-paths-ii_977241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <vector>
#include <iostream>
using namespace std;
int help(int i, int j, vector<vector<int>> &matrix)
{
    if (i > 0 && j > 0)
        if (i < 0 || j < 0)
        {
            return 0;
        }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    int up = 0, left = 0;
    if (i > 0)
    {
        if (matrix[i - 1][j] != 1)
        {
            up = help(i - 1, j, matrix);
        }
    }
    if (j > 0)
    {
        if (matrix[i][j - 1] != 1)
        {
            left = help(i, j - 1, matrix);
        }
    }
    return up + left;
}
int main()
{
    int m, n;
    cout << "Enter value of M and N  : ";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));

    cout << "Enter matrix : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    cout << "Unique Path : " << help(m - 1, n - 1, matrix);
}