class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lookupChartoIndex;
        int left = 0;
        int longestStr = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            if (lookupChartoIndex.count(s[right]))
            {
                left = max(lookupChartoIndex[s[right]] + 1,
                           left);
            }

            lookupChartoIndex[s[right]] = right;

            longestStr = max(right - left + 1,
                             longestStr);
        }

        return longestStr;
    }
};