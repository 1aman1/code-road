#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
{
    const int SIZE = nums.size();

    int left = 0, right = SIZE - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
            return true;

        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            ++left;
            --right;
            continue;
        }
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;

    if (searchInARotatedSortedArrayII(nums, target))
        cout << "Target is present in the array.\n";
    else
        cout << "Target is not present.\n";
    return 0;
}
