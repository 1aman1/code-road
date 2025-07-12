#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> spiralSeq;

        if (matrix.empty() || matrix[0].empty())
        {
            return spiralSeq;
        }

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; ++i)
                spiralSeq.push_back(matrix[top][i]);
            ++top;

            for (int i = top; i <= bottom; ++i)
                spiralSeq.push_back(matrix[i][right]);
            --right;

            if (bottom >= top)
            {
                for (int i = right; i >= left; --i)
                    spiralSeq.push_back(matrix[bottom][i]);
                --bottom;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    spiralSeq.push_back(matrix[i][left]);
                ++left;
            }
        }

        return spiralSeq;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {
                                                 4,
                                                 5,
                                                 6,
                                             },
                                  {7, 8, 9}};
    Solution obj;

    for (const auto &i : obj.spiralOrder(matrix))
        std::cout << i << " ";

    return 0;
}