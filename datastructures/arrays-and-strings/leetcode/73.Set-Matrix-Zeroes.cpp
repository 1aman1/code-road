class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowHasZero = std::any_of(matrix[0].begin(), matrix[0].end(),
                                           [](int val)
                                           { return val == 0; });

        bool firstColHasZero = std::any_of(matrix.begin(), matrix.end(),
                                           [](const vector<int> &eachRow)
                                           { return eachRow[0] == 0; });

        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols; ++c)
            {
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        if (firstRowHasZero)
        {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (firstColHasZero)
        {
            std::for_each(matrix.begin(), matrix.end(), [](vector<int> &eachRow)
                          { eachRow[0] = 0; });
        }
    }
};