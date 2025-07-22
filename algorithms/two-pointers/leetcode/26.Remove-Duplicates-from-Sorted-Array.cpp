class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    nums.erase(std::unique(begin(nums), end(nums)),
               end(nums));

    return nums.size();
  }
};