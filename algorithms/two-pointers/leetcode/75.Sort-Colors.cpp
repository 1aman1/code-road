class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = -1, right = nums.size(), i = 0;

        while (i < right)
        {
            if (nums[i] == 0)
            {
                swap(nums[++left], nums[i]);
                ++i;
            }
            else if (nums[i] == 2)
            {
                swap(nums[--right], nums[i]);
            }
            else
            {
                ++i;
            }
        }
    }
};