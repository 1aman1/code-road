class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int SIZE_S = s.size();
        int SIZE_T = t.size();

        int slow = 0, fast = 0;

        while (slow < SIZE_S && fast < SIZE_T)
        {
            if (s[slow] == t[fast])
            {
                ++slow;
                ++fast;
            }
            else
            {
                ++fast;
            }
        }

        return slow == SIZE_S ? true : false;
    }
};