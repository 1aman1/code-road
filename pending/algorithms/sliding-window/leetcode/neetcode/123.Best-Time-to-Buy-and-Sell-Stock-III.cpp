class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyFirst = INT_MIN;
        int sellFirst = 0;
        int buySecond = INT_MIN;
        int sellSecond = 0;

        for (const auto &price : prices)
        {
            buyFirst = max(buyFirst, -price);
            sellFirst = max(sellFirst, buyFirst + price);
            buySecond = max(buySecond, sellFirst - price);
            sellSecond = max(sellSecond, buySecond + price);
        }

        return sellSecond;
    }
};