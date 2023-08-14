/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <iostream>
using namespace std;

int distinctWays(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return distinctWays(n - 1) + distinctWays(n - 2);
}
int main()
{
    int top;
    cout << "Top : ";
    cin >> top;

    cout << distinctWays(top);
}