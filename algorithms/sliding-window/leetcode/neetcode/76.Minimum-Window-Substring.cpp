class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> lookupPatternFreq(128, 0);
        int patternLen = t.size();
        int minWindowSize = s.size() + 1;
        int minWindowStartLoc = -1;

        for (const auto &eachChar : t)
        {
            ++lookupPatternFreq[eachChar];
        }

        for (int left = 0, right = 0; right < s.size(); ++right)
        {
            if (--lookupPatternFreq[s[right]] >= 0)
            {
                --patternLen;
            }

            while (patternLen == 0)
            {
                if (minWindowSize > right - left + 1)
                {
                    minWindowSize = min(minWindowSize, right - left + 1);
                    minWindowStartLoc = left;
                }
                if (++lookupPatternFreq[s[left++]] > 0)
                {
                    ++patternLen;
                }
            }
        }

        return minWindowStartLoc == -1
                   ? ""
                   : s.substr(minWindowStartLoc, minWindowSize);
    }
};