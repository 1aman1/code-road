class Solution
{
    void dfs(int startIdx, int target, std::vector<int> &currentCombn, std::vector<std::vector<int>> &allCombinations, std::vector<int> &candidates)
    {
        if (target == 0)
        {
            allCombinations.emplace_back(currentCombn);
            return;
        }

        if (startIdx >= candidates.size() || target < candidates[startIdx])
        {
            return;
        }

        for (int currentIndex = startIdx; currentIndex < candidates.size(); ++currentIndex)
        {
            if (currentIndex > startIdx && candidates[currentIndex] == candidates[currentIndex - 1])
            {
                continue;
            }

            currentCombn.emplace_back(candidates[currentIndex]);

            dfs(currentIndex + 1, target - candidates[currentIndex], currentCombn, allCombinations, candidates);

            currentCombn.pop_back();
        }
    };

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> allCombinations;
        vector<int> currentCombn;

        dfs(0, target, currentCombn, allCombinations, candidates);

        return allCombinations;
    }
};
