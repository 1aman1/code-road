#include <bits/stdc++.h>
using namespace std;

class Solution
{
  vector<int> countCharacters(string s)
  {
    vector<int> tmp(26, 0);
    for (const char &c : s)
    {
      ++tmp[c - 'a'];
    }

    return tmp;
  }

  void insertMostFreqChar(vector<int> &letterFreq, int &idx, const char maxFreqChar, string &result)
  {
    while (letterFreq[maxFreqChar - 'a'] > 0)
    {
      result[idx] = maxFreqChar;
      idx += 2;
      --letterFreq[maxFreqChar - 'a'];
    }
  }

  void insertRemainingChar(vector<int> &letterFreq, int &idx, string &result, const int strSize)
  {
    for (int i = 0; i < 26; ++i)
    {
      while (letterFreq[i] > 0)
      {
        if (idx >= strSize)
          idx = 1;

        result[idx] = 'a' + i;
        idx += 2;
        --letterFreq[i];
      }
    }
  }

  string organizeString(vector<int> letterFreq, const char maxFreqChar, const int strSize)
  {
    string result(strSize, ' ');

    int idx = 0;
    insertMostFreqChar(letterFreq, idx, maxFreqChar, result);
    insertRemainingChar(letterFreq, idx, result, strSize);

    return result;
  }

public:
  string reorganizeString(string s)
  {
    const int strSize = s.length();
    if (strSize < 2)
      return s;

    auto letterFreq = countCharacters(s);

    auto maxFreqItr = max_element(letterFreq.begin(), letterFreq.end());
    int maxFreq = *maxFreqItr;

    if (maxFreq > (strSize + 1) / 2)
    {
      return "";
    }

    const char maxFreqChar = 'a' + distance(letterFreq.begin(), maxFreqItr);

    return organizeString(letterFreq, maxFreqChar, strSize);
  }
};
