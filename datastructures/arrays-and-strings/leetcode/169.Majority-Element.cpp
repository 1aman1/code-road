class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int majorityElement;
        int count = 0;

        for (const auto &current : nums)
        {
            if (count == 0)
            {
                majorityElement = current;
                count = 1;
            }
            else
            {
                count += (current == majorityElement ? 1 : -1);
            }
        }

        return majorityElement;
    }
};
