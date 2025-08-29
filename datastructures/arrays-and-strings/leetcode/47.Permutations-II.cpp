class Solution
{
    void dfs(int depth, vector<int> &current, vector<bool> &visited, vector<vector<int>> &permutations, vector<int> &nums, const int &NUMS_SIZE)
    {
        if (depth == NUMS_SIZE)
        {
            permutations.emplace_back(current);
            return;
        }

        for (int i = 0; i < NUMS_SIZE; ++i)
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
            {
                continue;
            }

            current[depth] = nums[i];

            visited[i] = true;
            dfs(depth + 1, current, visited, permutations, nums, NUMS_SIZE);
            visited[i] = false;
        }
    };

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int NUMS_SIZE = nums.size();
        vector<int> current(NUMS_SIZE);
        vector<bool> visited(NUMS_SIZE, false);
        vector<vector<int>> permutations;

        dfs(0, current, visited, permutations, nums, NUMS_SIZE);

        return permutations;
    }
};