// dynamic programming
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int SIZE = nums.size();
        if (SIZE == 1)
            return nums[0];
        if (SIZE == 2)
            return max(nums[0], nums[1]);

        vector<int> cache(SIZE);
        cache[0] = nums[0];
        cache[1] = max(nums[0], nums[1]);

        for (int i = 2; i < SIZE; ++i)
        {
            cache[i] = max(nums[i] + cache[i - 2],
                           cache[i - 1]);
        }
        return cache[SIZE - 1];
    }
};