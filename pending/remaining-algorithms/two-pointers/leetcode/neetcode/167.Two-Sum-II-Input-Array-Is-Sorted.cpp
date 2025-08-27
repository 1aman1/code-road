
class Solution
{
public:
    vector<int> twoSum(vector<int> &array, int target)
    {
        int left = 0;
        int right = array.size() - 1;

        while (array[left] + array[right] != target)
        {
            if (array[left] + array[right] > target)
                --right;
            else
                ++left;
        }
        return {left + 1, right + 1};
    }
};
