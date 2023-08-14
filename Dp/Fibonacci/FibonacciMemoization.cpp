#include <iostream>
using namespace std;
int fib(int n, int dp[])
{
    if (n == 0 || n == 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}
int main()
{
    int term;
    cout << "Enter Fibonacci term : ";
    cin >> term;
    int dp[term + 1];
    for (int i = 0; i < term + 1; i++)
        dp[i] = -1;
    cout << fib(term - 1, dp);
}