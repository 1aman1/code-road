#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
            return arr[0];

        // vector<int> cache(n);

        int idx_minus2 = arr[0];

        int idx_minus1 = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {
            int includeCurrentIdx = arr[i] + idx_minus2;
            int excludeCurrentIdx = idx_minus1;

            int currentIdx = max(includeCurrentIdx, excludeCurrentIdx);

            idx_minus2 = idx_minus1;
            idx_minus1 = currentIdx;
        }

        return idx_minus1;
    }
};

int main()
{
    vector<int> arr = {9, 1, 6, 10};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}
