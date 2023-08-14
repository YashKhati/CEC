#include <iostream>
using namespace std;
int main()
{
    int term;
    cout << "Enter Fibonacci term : ";
    cin >> term;
    int dp[term + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < term + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[term - 1] << endl;
}