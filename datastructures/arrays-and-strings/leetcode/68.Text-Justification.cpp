class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    int size = words.size();
    int lenOfThisLine;
    vector<string> finalText;

    for (int i = 0; i < size;)
    {
      lenOfThisLine = 0;

      vector<string> currLine{words[i]};
      lenOfThisLine += words[i].size();
      ++i;

      while (i < size && lenOfThisLine + 1 + words[i].size() <= maxWidth)
      {
        lenOfThisLine += 1 + words[i].size();
        currLine.push_back(words[i]);
        ++i;
      }

      if (currLine.size() == 1 || i == size)
      {
        string thisLine = currLine[0];
        for (int j = 1; j < currLine.size(); ++j)
        {
          thisLine += ' ' + currLine[j];
        }

        string rhsPadding = string(maxWidth - thisLine.size(), ' ');
        finalText.push_back(thisLine + rhsPadding);

        continue;
      }

      else
      {
        int spaceAvailable = maxWidth - (lenOfThisLine - currLine.size() + 1);
        int basePaddingLen = spaceAvailable / (currLine.size() - 1);
        int extraPaddingLen = spaceAvailable % (currLine.size() - 1);

        string thisLine;
        for (int k = 0; k < currLine.size() - 1; ++k)
        {
          thisLine += currLine[k] + string(basePaddingLen + (extraPaddingLen-- > 0 ? 1 : 0), ' ');
        }
        thisLine += currLine.back();

        finalText.push_back(thisLine);
      }
    }

    return finalText;
  }
};