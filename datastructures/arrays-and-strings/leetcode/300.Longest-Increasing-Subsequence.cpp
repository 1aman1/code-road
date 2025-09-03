class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> result;

        for (const int n : nums)
        {
            auto itr = lower_bound(result.begin(), result.end(), n);
            if (itr == result.end())
            {
                result.emplace_back(n);
            }
            else
            {
                *itr = n;
            }
        }

        return result.size();
    }
};