#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        int writeHead = 0;
        int size = chars.size();

        for (int i = 0; i < size;)
        {
            int count_same_char = 0;

            const char curr_char = chars[i];

            while (i < size &&
                   chars[i] == curr_char)
            {
                ++i;
                ++count_same_char;
            }

            chars[writeHead++] = curr_char;

            if (count_same_char > 1)
            {
                for (const auto i : std::to_string(count_same_char))
                    chars[writeHead++] = i;
            }
        }
        return writeHead;
    }
};

int main()
{

    Solution obj;

    // std::vector<char> chars{'a', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    // std::vector<char> chars{'a', 'b', 'c', 'd'};
    // std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::vector<char> chars{'a', 'a'};

    std::cout << obj.compress(chars) << std::endl;

    for (auto &i : chars)
        std::cout << i;

    return 0;
}