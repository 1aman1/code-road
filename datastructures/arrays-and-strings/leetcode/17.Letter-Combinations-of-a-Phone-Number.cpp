class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty())
      return {};

    vector<string> digitToLetters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations{""};

    for (const char &eachDigit : digits)
    {
      string letters = digitToLetters[eachDigit - '2'];

      vector<string> tmpCombns;

      for (const char &eachLetter : letters)
      {
        for (const string &eachCombntn : combinations)
        {
          tmpCombns.push_back(eachCombntn + eachLetter);
        }
      }
      combinations.swap(tmpCombns);
    }

    return combinations;
  }
};