class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int SIZE = nums.size();
        int missingNo = SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            missingNo ^= i ^ nums[i];
        }
        return missingNo;
    }
};
