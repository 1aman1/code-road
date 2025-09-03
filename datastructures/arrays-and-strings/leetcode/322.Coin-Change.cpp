class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;

        for (const int &c : coins)
        {
            for (int i = 1; i <= amount; ++i)
            {
                if (i >= c)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        return dp[amount] != INF ? dp[amount] : -1;
    }
};