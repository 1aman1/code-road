class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> frequency(26, 0);

        for (int i = 0; i < s.size(); ++i)
        {
            ++frequency[s[i] - 'a'];
            --frequency[t[i] - 'a'];
        }

        return std::all_of(frequency.begin(), frequency.end(), [](const int &e)
                           { return e == 0; });
    }
};