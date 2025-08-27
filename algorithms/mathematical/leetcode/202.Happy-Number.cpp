#include <iostream>
#include <map>

class Solution
{
    std::map<int, bool> lookup;

public:
    bool isHappy(int n)
    {
        int sqSum = 0, digit1 = 0;

        while (n)
        {
            digit1 = n % 10;
            sqSum += digit1 * digit1;
            n /= 10;
        }

        if (sqSum == 1)
            return true;

        if (lookup.count(sqSum))
            return false;
        else
        {
            lookup.insert({sqSum, true});
            return isHappy(sqSum);
        }
    }
};

int main()
{
    Solution obj;

    std::cout << std::boolalpha << obj.isHappy(10) << std::endl;
    std::cout << std::boolalpha << obj.isHappy(2);

    return 0;
}