class Solution
{
  string fetchSubStr(std::stack<char> &charStack)
  {
    std::string tempStr = "";
    while (!charStack.empty() && charStack.top() != '[')
    {
      tempStr = charStack.top() + tempStr;
      charStack.pop();
    }

    return tempStr;
  }

  int fetchK(std::stack<char> &charStack)
  {
    std::string k;
    while (!charStack.empty() && isdigit(charStack.top()))
    {
      k = charStack.top() + k;
      charStack.pop();
    }

    return stoi(k);
  }

  string decodeKTimes(string currSubString, int K)
  {
    std::string tempStr = "";
    while (K--)
    {
      tempStr += currSubString;
    }

    return tempStr;
  }

  void pushDecodedBackIntoStack(std::stack<char> &charStack, string str)
  {
    for (int i = 0; i < str.length(); ++i)
    {
      charStack.push(static_cast<char>(str[i]));
    }
  }

public:
  std::string decodeString(std::string s)
  {
    std::stack<char> charStack;

    string resultStr;

    for (int i = 0; i < s.length(); ++i)
    {
      if (s[i] != ']')
      {
        charStack.push(s[i]);
      }
      else
      {
        string currSubString = fetchSubStr(charStack);

        charStack.pop();

        int K = fetchK(charStack);

        string currDecodedString = decodeKTimes(currSubString, K);

        pushDecodedBackIntoStack(charStack, currDecodedString);
      }
    }

    while (!charStack.empty())
    {
      resultStr = charStack.top() + resultStr;
      charStack.pop();
    }

    return resultStr;
  }
};
