class Solution
{
    int rows;
    int cols;
    vector<vector<bool>> visited;

private:
    void paint(vector<vector<int>> &image, int sr, int sc,
               int start_colour,
               int new_color)
    {
        bool rowCheck = 0 <= sr && sr < rows;
        bool colCheck = 0 <= sc && sc < cols;

        if (!rowCheck || !colCheck)
            return;

        if (image[sr][sc] != start_colour ||
            visited[sr][sc])
            return;

        image[sr][sc] = new_color;
        visited[sr][sc] = true;

        paint(image, sr + 1, sc, start_colour, new_color);
        paint(image, sr - 1, sc, start_colour, new_color);
        paint(image, sr, sc + 1, start_colour, new_color);
        paint(image, sr, sc - 1, start_colour, new_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int new_color)
    {
        rows = image.size();
        cols = image[0].size();

        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        paint(image, sr, sc,
              image[sr][sc],
              new_color);

        return image;
    }
};
