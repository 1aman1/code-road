var spiralOrder = function (matrix) {
    top = 0;
    bottom = matrix.length - 1;
    left = 0;
    right = matrix[0].length - 1;

    if (bottom + 1 == 0 || right + 1 == 0) {
        return matrix;
    }

    resultArray = [];

    while (top <= bottom && left <= right) {

        for (i = left; i <= right; ++i)
            resultArray.push(matrix[top][i])
        top += 1;

        for (i = top; i <= bottom; ++i)
            resultArray.push(matrix[i][right])
        right -= 1;

        if (bottom >= top) {
            for (i = right; i >= left; --i)
                resultArray.push(matrix[bottom][i])
            bottom -= 1;
        }

        if (left <= right) {
            for (i = bottom; i >= top; --i)
                resultArray.push(matrix[i][left])
            left++;
        }

    }
    return resultArray;
}