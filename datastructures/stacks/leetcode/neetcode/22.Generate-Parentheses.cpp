class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> combinations;
        generator(n, 0, 0, "", combinations);
        return combinations;
    }

private:
    void generator(int n, int open, int close, string curr, vector<string> &combinations)
    {
        if (open == n && close == n)
        {
            combinations.push_back(curr);
            return;
        }
        if (open < n)
        {
            generator(n, open + 1, close, curr + '(', combinations);
        }
        if (close < open)
        {
            generator(n, open, close + 1, curr + ')', combinations);
        }
    }
};