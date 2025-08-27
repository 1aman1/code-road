class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        const int SIZE = nums.size();
        for (int i = 0; i < SIZE; ++i)
        {
            while (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        std::vector<int> duoNumbers;
        for (int i = 0; i < SIZE; ++i)
        {
            if (nums[i] != 1 + i)
            {
                duoNumbers.emplace_back(nums[i]);
            }
        }

        return duoNumbers;
    }
};