class Solution
{

    void util(string &str, int idx, vector<string> &result)
    {
        if (idx == str.size())
        {
            result.push_back(str);
            return;
        }

        if (isdigit(str[idx]))
        {
            util(str, idx + 1, result);
            return;
        }

        str[idx] = toupper(str[idx]);
        util(str, idx + 1, result);
        str[idx] = tolower(str[idx]);
        util(str, idx + 1, result);
    }

public:
    vector<string> letterCasePermutation(string str)
    {
        vector<string> result;
        util(str, 0, result);

        return result;
    }
};