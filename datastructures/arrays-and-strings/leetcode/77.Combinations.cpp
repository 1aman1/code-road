class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> result;
    vector<int> current;

    combineUtility(1, n, k, current, result);
    return result;
  }

  void combineUtility(
      int start,
      const int &n,
      const int &k,
      vector<int> &current,
      vector<vector<int>> &result)
  {
    if (current.size() == k)
    {
      result.push_back(current);
      return;
    }

    for (int i = start; i <= n - (k - current.size()) + 1; ++i)
    {
      current.push_back(i);
      combineUtility(i + 1, n, k, current, result);
      current.pop_back();
    }
  }
};