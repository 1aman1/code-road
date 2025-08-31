// dynamic programming

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        const int SUM = accumulate(begin(nums), end(nums), 0);

        if (((SUM + target) < 0) || ((target + SUM) % 2 != 0))
            return 0;

        int P = (target + SUM) / 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;

        for (const int &eachNum : nums)
        {
            for (int i = P; i >= eachNum; --i)
            {
                dp[i] += dp[i - eachNum];
            }
        }

        return dp[P];
    }
};
