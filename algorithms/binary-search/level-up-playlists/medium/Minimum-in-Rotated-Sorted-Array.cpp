#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        const int SIZE = nums.size();

        int left = 0;
        int right = SIZE - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution sol;

    int result = sol.findMin(nums);
    cout << "Minimum element is " << result << endl;

    return 0;
}