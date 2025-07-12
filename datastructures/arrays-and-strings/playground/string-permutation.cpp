#include <iostream>
#include <map>

class Solution
{
public:
    int count = 0;

    std::map<std::string, bool> map;

    void permutation(std::string S, int left, int right);
};

void Solution::permutation(std::string S, int left, int right)
{
    if (left != right)
    {
        for (int i = left; i <= right; i++)
        {
            std::swap(S[left], S[i]);
            permutation(S, left + 1, right);
            std::swap(S[left], S[i]);
        }
    }
    else
    {
        if (!map.count(S))
        {
            ++count;
            map.insert({S, true});
        }
    }
}

int main()
{
    Solution obj;

    std::string s = "racecar";

    obj.permutation(s, 0, s.size() - 1);

    std::cout << obj.count << std::endl;

    return 0;
}