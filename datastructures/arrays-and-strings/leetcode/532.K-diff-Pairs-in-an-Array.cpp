
class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    int result = 0;
    unordered_map<int, int> cache;

    for (int i = 0; i < nums.size(); ++i)
      cache[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i)
    {
      const int target = nums[i] + k;
      if (cache.count(target) && cache[target] != i)
      {
        ++result;
        cache.erase(target);
      }
    }

    return result;
  }
};
