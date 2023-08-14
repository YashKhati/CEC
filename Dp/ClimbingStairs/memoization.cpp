/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <iostream>
using namespace std;

int distinctWays(int n, int dp[])
{
    if (n == 0 || n == 1)
    {
        return dp[n] = 1;
    }

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = distinctWays(n - 1, dp) + distinctWays(n - 2, dp);
}
int main()
{
    int top;
    cout << "Top : ";
    cin >> top;
    int dp[top + 1];
    for (int i = 0; i <= top; i++)
    {
        dp[i] = -1;
    }
    cout << distinctWays(top, dp);
}