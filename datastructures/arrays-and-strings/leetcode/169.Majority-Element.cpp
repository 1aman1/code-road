#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int majorElement;
        int count = 0;

        for (const auto &current : nums)
        {
            if (count == 0)
            {
                majorElement = current;
                count = 1;
            }
            else
            {
                count += (current == majorElement ? 1 : -1);
            }
        }

        return majorElement;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    std::cout << obj.majorityElement(nums) << std::endl;

    return 0;
}