class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> lookup;

        int longest = 0;
        int lhs = 0;
        int rhs = 0;

        for (; rhs < s.length(); ++rhs)
        {
            if (lookup.find(s[rhs]) != lookup.end())
            {
                lhs = std::max(lhs,
                               lookup[s[rhs]] + 1);
            }
            lookup[s[rhs]] = rhs;
            longest = std::max(longest, rhs - lhs + 1);
        }

        return longest;
    }
};