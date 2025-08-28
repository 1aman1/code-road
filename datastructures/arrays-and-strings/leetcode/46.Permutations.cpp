class Solution
{
    void permuteUtil(const int &left, const int &right, std::vector<std::vector<int>> &result, std::vector<int> &nums)
    {
        if (left == right)
        {
            result.push_back(nums);
            return;
        }

        for (auto i = left; i <= right; ++i)
        {
            std::swap(nums[left], nums[i]);
            permuteUtil(left + 1, right, result, nums);
            std::swap(nums[left], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        permuteUtil(0, nums.size() - 1, result, nums);

        return result;
    }
};
