class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> result;
    vector<int> current;

    combineUtility(1, current, result, n, k);
    return result;
  }

  void combineUtility(
      int start,
      vector<int> &current,
      vector<vector<int>> &result,
      const int &n,
      const int &k)
  {
    if (current.size() == k)
    {
      result.push_back(current);
      return;
    }

    for (int i = start; i <= n + 1 - (k - current.size()); ++i)
    {
      current.push_back(i);
      combineUtility(i + 1, current, result, n, k);
      current.pop_back();
    }
  }
};