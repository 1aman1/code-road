class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow_x, fast_2x;

        slow_x = fast_2x = 0;
        do
        {
            slow_x = nums[slow_x];
            fast_2x = nums[nums[fast_2x]];
        } while (slow_x != fast_2x);

        fast_2x = 0;

        while (slow_x != fast_2x)
        {
            slow_x = nums[slow_x];
            fast_2x = nums[fast_2x];
        }

        return slow_x;
    }
};
