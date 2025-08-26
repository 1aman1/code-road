// bottom-up

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> cache(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            cache[i] = cache[i >> 1] + (i & 1);
        }

        return cache;
    }
};
