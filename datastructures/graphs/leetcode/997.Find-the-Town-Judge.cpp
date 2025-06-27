class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> trustsOther(n + 1);
    vector<int> trustedByOthers(n + 1);

    for (const auto &eachRelation : trust)
    {
      int thisPerson = eachRelation[0];
      int o = eachRelation[1];

      ++trustsOther[thisPerson];
      ++trustedByOthers[o];
    }

    for (int thisPerson = 1; thisPerson <= n; ++thisPerson)
    {
      if (trustedByOthers[thisPerson] == n - 1 &&
          trustsOther[thisPerson] == 0)
        return thisPerson;
    }
    return -1;
  }
};