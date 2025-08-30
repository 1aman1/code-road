class Solution
{
    void depthFirstSearch(int index, int remaining, std::vector<int> &currentCombn, std::vector<std::vector<int>> &allCombinations, std::vector<int> &candidates)
    {
        if (remaining == 0)
        {
            allCombinations.emplace_back(currentCombn);
            return;
        }

        if (index >= candidates.size() || remaining < candidates[index])
        {
            return;
        }

        depthFirstSearch(index + 1, remaining, currentCombn, allCombinations, candidates);

        currentCombn.push_back(candidates[index]);
        depthFirstSearch(index, remaining - candidates[index], currentCombn, allCombinations, candidates);
        currentCombn.pop_back();
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> allCombinations;
        std::vector<int> currentCombn;

        depthFirstSearch(0, target, currentCombn, allCombinations, candidates);

        return allCombinations;
    }
};