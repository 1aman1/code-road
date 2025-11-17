class Solution
{
    int getCeil(vector<int> &nums, int n, int x)
    {
        int left = 0;
        int right = n - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x)
            {
                result = nums[mid];
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }

    int getFloor(vector<int> &nums, int n, int x)
    {
        int left = 0;
        int right = n - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= x)
            {
                result = nums[mid];
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }

public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        int n = nums.size();

        int floor = getFloor(nums, n, x);
        int ceil = getCeil(nums, n, x);

        return {floor, ceil};
    }
};