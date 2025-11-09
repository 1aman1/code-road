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

        vector<int> cache(n);

        cache[0] = arr[0];

        cache[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {
            cache[i] = max(arr[i] + cache[i - 2], cache[i - 1]);
        }

        return cache[n - 1];
    }
};

int main()
{
    vector<int> arr = {9, 1, 6, 10};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}
