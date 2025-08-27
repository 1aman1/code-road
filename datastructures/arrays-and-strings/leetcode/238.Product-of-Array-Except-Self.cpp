class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &array)
    {
        size_t size = array.size();

        vector<int> prefix(size, 0);
        vector<int> suffix(size, 0);

        prefix[0] = 1;
        for (int i = 1; i < size; ++i)
            prefix[i] = array[i - 1] * prefix[i - 1];

        suffix[size - 1] = 1;
        for (int i = size - 1 - 1; i >= 0; --i)
            suffix[i] = suffix[i + 1] * array[i + 1];

        for (int i = 0; i < size; ++i)
            array[i] = prefix[i] * suffix[i];

        return array;
    }
};