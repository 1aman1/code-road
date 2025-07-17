class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int highestFreqCharInWindow = 0;
    int maxLen = 0;
    vector<int> lookup(26, 0);

    int left = 0;

    for (int right = 0; right < s.size(); ++right)
    {
      ++lookup[s[right] - 'A'];

      highestFreqCharInWindow = max(highestFreqCharInWindow,
                                    lookup[s[right] - 'A']);

      int windowSize = right - left + 1;
      int charsToChange = windowSize - highestFreqCharInWindow;

      if (charsToChange > k)
      {
        --lookup[s[left] - 'A'];
        ++left;
      }

      maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
  }
};