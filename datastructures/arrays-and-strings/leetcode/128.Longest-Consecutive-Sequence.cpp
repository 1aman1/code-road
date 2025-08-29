
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> cache(nums.begin(), nums.end());
        int longestSequenceLength = 0;

        for (const auto &eachNum : cache)
        {
            if (cache.count(eachNum - 1) == 0)
            {
                int length = 1;
                while (cache.count(eachNum + length))
                    ++length;

                longestSequenceLength = std::max(length, longestSequenceLength);
            }
        }
        return longestSequenceLength;
    }
};
