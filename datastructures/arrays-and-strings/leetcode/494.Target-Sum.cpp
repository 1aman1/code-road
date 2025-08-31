class Solution
{
public:
    int countWays(vector<int> &nums, int i, int sum, int target)
    {
        if (i == nums.size())
        {
            return sum == target ? 1 : 0;
        }

        int plus = countWays(nums, i + 1, sum + nums[i], target);

        int minus = countWays(nums, i + 1, sum - nums[i], target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countWays(nums, 0, 0, target);
    }
};
