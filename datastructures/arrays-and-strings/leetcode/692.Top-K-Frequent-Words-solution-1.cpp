class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    const size_t noOfWords = words.size();

    vector<string> result;
    vector<vector<string>> wordToFreq(noOfWords + 1);
    unordered_map<string, int> count;

    for (const auto eachWord : words)
      ++count[eachWord];

    for (const auto &[eachWord, freq] : count)
      wordToFreq[freq].push_back(eachWord);

    for (int i = noOfWords; i >= 0; --i)
    {
      sort(begin(wordToFreq[i]), end(wordToFreq[i]));

      for (const auto &eachWord : wordToFreq[i])
      {
        result.push_back(eachWord);
        if (result.size() == k)
          return result;
      }
    }

    return {""};
  }
};
