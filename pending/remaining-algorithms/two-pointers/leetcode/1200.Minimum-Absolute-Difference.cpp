class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());

    int size = arr.size();
    int minDiff = INT_MAX;
    vector<vector<int>> result;

    for (int i = 1; i < size; ++i)
    {
      minDiff = min(minDiff,
                    arr[i] - arr[i - 1]);
    }

    for (int i = 1; i < size; ++i)
    {
      if (arr[i] - arr[i - 1] == minDiff)
      {
        result.push_back({arr[i - 1], arr[i]});
      }
    }

    return result;
  }
};