#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    if (a.size() > b.size())
        return findMedianSortedArrays(b, a);

    int SIZEA = a.size();
    int SIZEB = b.size();

    int left = 0;
    int right = SIZEA;

    while (left <= right)
    {
        int partitionIdxA = left + (right - left) / 2;
        int partitionIdxB = (SIZEA + SIZEB + 1) / 2 - partitionIdxA;

        int leftA = (partitionIdxA == 0) ? INT_MIN : a[partitionIdxA - 1];
        int rightA = (partitionIdxA == SIZEA) ? INT_MAX : a[partitionIdxA];

        int leftB = (partitionIdxB == 0) ? INT_MIN : b[partitionIdxB - 1];
        int rightB = (partitionIdxB == SIZEB) ? INT_MAX : b[partitionIdxB];

        if (leftA <= rightB && leftB <= rightA)
        {
            if ((SIZEA + SIZEB) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            else
                return max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            right = partitionIdxA - 1;
        }
        else
        {
            left = partitionIdxA + 1;
        }
    }

    return 0.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << fixed << setprecision(1);
    cout << "The median is " << median(a, b) << '\n';
}