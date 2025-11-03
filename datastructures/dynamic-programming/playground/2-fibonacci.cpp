#include <iostream>
#include <vector>

using namespace std;

long long getFibonacciNum(int n)
{
    if (n < 0)
        return 0;

    vector<long long> fibonacciCache(n + 1, 0);

    fibonacciCache[0] = 1;
    fibonacciCache[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibonacciCache[i] = fibonacciCache[i - 1] + fibonacciCache[i - 2];
    }

    return fibonacciCache(n);
}

int main()
{
    cout << getFibonacciNum(10) << endl;
    return 0;
}
