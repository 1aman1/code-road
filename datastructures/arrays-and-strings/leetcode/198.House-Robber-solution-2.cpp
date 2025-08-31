// dynamic programming
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int moneyTillPrev2Prev = nums[0];
        int moneyTillPrev = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i)
        {
            int curr = max(moneyTillPrev, nums[i] + moneyTillPrev2Prev);
            moneyTillPrev2Prev = moneyTillPrev;
            moneyTillPrev = curr;
        }
        return moneyTillPrev;
    }
};