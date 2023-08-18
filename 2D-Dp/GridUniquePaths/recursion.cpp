/*
https://www.codingninjas.com/studio/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/
#include <iostream>
using namespace std;
int help(int m, int n, int i, int j)
{

    if (i > m || j > n || i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    return help(m, n, i - 1, j) + help(m, n, i, j - 1);
}
int main()
{
    int m, n;
    cout << "Enter value of M and N  : ";
    cin >> m >> n;

    cout << "Unique Path : " << help(m - 1, n - 1, m - 1, n - 1);
}