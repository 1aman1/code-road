// backtracking

class Solution
{
    void dfs(int idx, vector<int> &currSubset, vector<int> &nums, vector<vector<int>> &result)
    {
        result.push_back(currSubset);

        for (int i = idx; i < nums.size(); i++)
        {
            currSubset.push_back(nums[i]);
            dfs(i + 1, currSubset, nums, result);
            currSubset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> currSubset;
        dfs(0, currSubset, nums, result);

        return result;
    }
};