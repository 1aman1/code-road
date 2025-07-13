#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int SIZE = nums.size();
        int lastNonZeroIdx = -1;

        for (int i = 0; i < SIZE; ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[++lastNonZeroIdx], nums[i]);
            }
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution obj;
    obj.moveZeroes(nums);

    for (auto i : nums)
        cout << i << "\n";
    return 0;
}