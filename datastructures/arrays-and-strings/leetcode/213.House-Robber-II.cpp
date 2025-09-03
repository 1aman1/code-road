// dynamic programming
class Solution
{
    int start(const vector<int> &nums, const int start, const int end)
    {
        int prev2Prev = 0;
        int prev = 0;

        for (int i = start; i <= end; ++i)
        {
            int curr = max(prev, nums[i] + prev2Prev);
            prev2Prev = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int robbedMoneyFirst = start(nums, 0, n - 2);
        int robbedMoneySecond = start(nums, 1, n - 1);

        return max(robbedMoneyFirst, robbedMoneySecond);
    }
};