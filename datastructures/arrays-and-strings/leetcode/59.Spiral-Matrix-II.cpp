class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; ++i)
        {
            matrix[i].resize(n);
        }

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int number = 1;
        int nSQ = n * n;

        while (number <= nSQ)
        {
            for (int i = left; i <= right; ++i)
                matrix[top][i] = number++;
            ++top;

            for (int i = top; i <= bottom; ++i)
                matrix[i][right] = number++;
            --right;

            if (bottom >= top)
                for (int i = right; i >= left; --i)
                    matrix[bottom][i] = number++;
            --bottom;

            if (left <= right)
                for (int i = bottom; i >= top; --i)
                    matrix[i][left] = number++;
            ++left;
        }

        return matrix;
    }
};