#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int idx, vector<int> &cache, vector<int> &arr)
    {
        if (idx < 0)
            return 0;

        if (idx == 0)
            return arr[0];

        if (cache[idx] != -1)
            return cache[idx];

        int pick = arr[idx] + solve(idx - 2, cache, arr);

        int notPick = solve(idx - 1, cache, arr);

        return cache[idx] = max(pick, notPick);
    }

    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int SIZE = arr.size();

        vector<int> cache(SIZE, -1);

        return solve(SIZE - 1, cache, arr);
    }
};

int main()
{
    vector<int> arr = {9, 1, 6, 10};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}
