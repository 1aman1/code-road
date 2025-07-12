vector<int> maxSubArray(std::vector<int> &nums)
{
    int maxSum = nums[0], currSum = nums[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > currSum + nums[i])
        {
            currSum = nums[i];
            tempStart = i;
        }
        else
        {
            currSum += nums[i];
        }

        if (currSum > maxSum)
        {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    return vector<int>(nums.begin() + start,
                       nums.begin() + end + 1);
}
