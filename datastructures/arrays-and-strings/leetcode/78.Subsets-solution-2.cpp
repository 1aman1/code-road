// backtracking

class Solution
{
    void backtrack(int index, vector<int> &currSubset, vector<int> &nums, vector<vector<int>> &result)
    {
        if (index == nums.size())
        {
            result.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[index]);
        backtrack(index + 1, currSubset, nums, result);

        currSubset.pop_back();
        backtrack(index + 1, currSubset, nums, result);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> currSubset;
        backtrack(0, currSubset, nums, result);
        return result;
    }
};
