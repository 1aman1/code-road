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
                swap(nums[i], nums[++lastNonZeroIdx]);
            }
        }
    }
};