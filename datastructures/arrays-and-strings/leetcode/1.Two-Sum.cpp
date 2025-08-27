class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> cache;

        for (int idx = 0; idx < nums.size(); ++idx)
        {
            int remainder = target - nums[idx];
            if (cache.find(remainder) != cache.end())
            {
                return {cache.at(remainder), idx};
            }

            cache.insert({nums[idx], idx});
        }
        return {};
    }
};