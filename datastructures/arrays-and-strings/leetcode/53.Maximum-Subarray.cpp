class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int maxSoFar = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            currSum = std::max(nums[i], currSum + nums[i]);
            maxSoFar = std::max(maxSoFar, currSum);
        }

        return maxSoFar;
    }
};
