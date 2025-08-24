class Solution
{
  struct Wordo
  {
    string word;
    int freq;
    Wordo(string word, int freq) : word(word), freq(freq) {}
  };

  struct customCompare
  {
    bool operator()(const Wordo &lhs, const Wordo &rhs) const
    {
      if (lhs.freq == rhs.freq)
        return lhs.word < rhs.word;
      return lhs.freq > rhs.freq;
    }
  };

  priority_queue<Wordo, vector<Wordo>, customCompare> prepareHeap(const unordered_map<string, int> &wordToFreq, const int &k)
  {
    priority_queue<Wordo, vector<Wordo>, customCompare> heap;

    for (const auto &entry : wordToFreq)
    {
      heap.emplace(entry.first, entry.second);
      if (heap.size() > k)
        heap.pop();
    }

    return heap;
  }

public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    unordered_map<string, int> wordToFreq;
    for (const auto &eachWord : words)
      ++wordToFreq[eachWord];

    auto heap = prepareHeap(wordToFreq, k);

    vector<string> result;
    while (!heap.empty())
    {
      result.insert(result.begin(), heap.top().word);
      heap.pop();
    }

    return result;
  }
};