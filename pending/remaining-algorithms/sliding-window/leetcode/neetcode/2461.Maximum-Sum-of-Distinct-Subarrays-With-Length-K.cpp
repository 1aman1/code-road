class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;
    int currSum = 0, maxSum = 0;

    for (int i = 0; i < k; ++i)
    {
      freq[nums[i]]++;
      currSum += nums[i];
    }
    maxSum = freq.size() == k ? currSum : 0;

    for (int i = k; i < nums.size(); ++i)
    {
      currSum -= nums[i - k];
      --freq[nums[i - k]];

      if (freq[nums[i - k]] == 0)
        freq.erase(nums[i - k]);

      currSum += nums[i];
      freq[nums[i]]++;

      if (freq.size() == k)
      {
        maxSum = max(maxSum, currSum);
      }
    }

    return maxSum;
  }
};