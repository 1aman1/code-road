class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    vector<int> cache(128);
    int pattern_size = s1.length();
    const int S1_LEN = s1.length();

    for (const auto &eachChar : s1)
      ++cache[eachChar];

    for (int eachChar = 0; eachChar < s2.length(); ++eachChar)
    {
      if (--cache[s2[eachChar]] >= 0)
        --pattern_size;

      if (eachChar >= S1_LEN)
      {
        if (++cache[s2[eachChar - S1_LEN]] > 0)
          ++pattern_size;
      }

      if (pattern_size == 0)
        return true;
    }
    return false;
  }
};
