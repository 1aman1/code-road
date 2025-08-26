// memoization
// recursive

class Solution
{
    int climbStairs(int n, std::vector<int> &cache)
    {
        if (n <= 1)
            return 1;

        if (cache[n] != -1)
            return cache[n];

        cache[n] = climbStairs(n - 1, cache) + climbStairs(n - 2, cache);
        return cache[n];
    }

public:
        int climbStairs(int n)
    {
        std::vector<int> cache(n + 1, -1);

        return climbStairs(n, cache);
    }
};
