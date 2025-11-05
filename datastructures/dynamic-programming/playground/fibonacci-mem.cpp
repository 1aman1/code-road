#include <iostream>
#include <vector>

using namespace std;

long long calculate(int n, std::vector<long long> &cache)
{
    if (n <= 1)
        return n;

    if (cache[n] != -1)
        return cache[n];

    cache[n] = calculate(n - 1, cache) + calculate(n - 2, cache);
    return cache[n];
}

long long getFibonacciNum(int n)
{
    if (n < 0)
        return 0;

    vector<long long> fibonacciCache(n + 1, -1);

    return calculate(n, fibonacciCache);
}

int main()
{
    cout << getFibonacciNum(10) << endl;
    return 0;
}
