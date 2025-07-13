
#include <iostream>
#include <algorithm>

class Solution
{
public:
    std::string reverseWords(std::string str)
    {
        for (int lhs = 0, len = s.size(); lhs < len; ++lhs)
        {
            if (s[lhs] == ' ')
                continue;

            int rhs = lhs;
            while (rhs < len && s[rhs] != ' ')
                ++rhs;

            std::reverse(s.begin() + lhs, s.begin() + rhs);

            lhs = rhs;
        }

        return str;
    }
};

int main()
{
    std::string str = "Let's take LeetCode contest";

    Solution obj;

    std::cout << obj.reverseWords(str);

    return 0;
}