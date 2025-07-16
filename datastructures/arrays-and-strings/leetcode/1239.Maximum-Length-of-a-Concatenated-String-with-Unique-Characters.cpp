class Solution
{
public:
  int maxLength(vector<string> &arr)
  {
    vector<int> masksAvailable{0};
    int maxLen = 0;

    for (const auto &str : arr)
    {
      int mask = 0;
      bool discard = false;

      for (const auto &eachChar : str)
      {
        int offset = eachChar - 'a';
        if (mask & (1 << offset))
        {
          discard = true;
          break;
        }

        mask = mask | 1 << offset;
      }

      if (discard)
        continue;

      for (int m = 0; m < masksAvailable.size(); ++m)
      {
        if ((masksAvailable[m] & mask) != 1)
        {
          masksAvailable.push_back(masksAvailable[m] | mask);
          maxLen = max(maxLen, __builtin_popcount(masksAvailable.back()));
        }
      }
    }
    return maxLen;
  }
};