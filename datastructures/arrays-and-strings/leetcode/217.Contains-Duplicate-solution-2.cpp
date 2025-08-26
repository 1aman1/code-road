class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> numCache(nums.begin(), nums.end());

        return numCache.size() < nums.size();
    }
};