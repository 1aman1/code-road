class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = nums[0], minProd = nums[0], result = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);

            result = max(result, maxProd);
        }

        return result;
    }
};