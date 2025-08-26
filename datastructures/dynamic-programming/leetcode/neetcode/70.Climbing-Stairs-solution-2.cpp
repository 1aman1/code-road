// bottom up
// iterative

int climbStairs(int n)
{
    if (n <= 1)
        return 1;

    vector<int> cache(n + 1, 0);
    cache[0] = 1;
    cache[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    
    return cache[n];
}