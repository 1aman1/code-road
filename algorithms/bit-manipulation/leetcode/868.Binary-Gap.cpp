class Solution
{
public:
    int binaryGap(int number)
    {
        if (__builtin_popcount(number) < 2)
            return 0;

        int result = -1;
        string str = std::bitset<32>(number).to_string();

        int left = __builtin_clz(number);
        int right = 1 + left;

        while (right < str.size())
        {
            if (str[right] == '1')
            {
                result = max(right - left - 1, result);
                left = right;
                right = 1 + left;
                continue;
            }
            ++right;
        }

        return result + 1;
    }
};