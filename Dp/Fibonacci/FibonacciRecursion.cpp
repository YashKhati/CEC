#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int term;
    cout << "Enter Fibonacci term : ";
    cin >> term;
    for (int i = 0; i < term; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;
}