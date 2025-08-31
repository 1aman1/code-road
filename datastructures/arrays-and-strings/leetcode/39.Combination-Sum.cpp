class Solution
{
    void dfs(int index, int target, std::vector<int> &currentCombn, std::vector<std::vector<int>> &allCombinations, std::vector<int> &candidates)
    {
        if (target == 0)
        {
            allCombinations.emplace_back(currentCombn);
            return;
        }

        if (index >= candidates.size() || target < candidates[index])
        {
            return;
        }

        dfs(index + 1, target, currentCombn, allCombinations, candidates);

        currentCombn.push_back(candidates[index]);
        dfs(index, target - candidates[index], currentCombn, allCombinations, candidates);
        currentCombn.pop_back();
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> allCombinations;
        std::vector<int> currentCombn;

        dfs(0, target, currentCombn, allCombinations, candidates);

        return allCombinations;
    }
};