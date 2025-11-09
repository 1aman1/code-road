// dynamic programming
class Solution
{
    int start(const int start, const int end, const vector<int> &nums)
    {
        int idx_minus2 = 0;
        int idx_minus1 = 0;

        for (int idx = start; idx <= end; ++idx)
        {
            int currentIdx = max(nums[idx] + idx_minus2,
                                 idx_minus1);
            idx_minus2 = idx_minus1;
            idx_minus1 = currentIdx;
        }
        return idx_minus1;
    }

public:
    int rob(vector<int> &nums)
    {
        int SIZE = nums.size();
        if (SIZE == 1)
            return nums[0];
        if (SIZE == 2)
            return max(nums[0], nums[1]);

        int robbedMoneyFirst = start(0, SIZE - 2, nums);
        int robbedMoneySecond = start(1, SIZE - 1, nums);

        return max(robbedMoneyFirst, robbedMoneySecond);
    }
};