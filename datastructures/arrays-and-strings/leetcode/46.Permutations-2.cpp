
class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        result.push_back(nums);
        sort(nums.begin(), nums.end());

        while (std::next_permutation(nums.begin(), nums.end()))
        {
            result.push_back(nums);
        }

        return result;
    }
};
