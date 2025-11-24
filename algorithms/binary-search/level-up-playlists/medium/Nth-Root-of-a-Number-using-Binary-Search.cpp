#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthRoot(int n, int m)
    {
        int left = 1;
        int right = m;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            long long numRaisedToN = 1;
            for (int times = 1; times <= n; ++times)
            {
                numRaisedToN *= mid;
                if (numRaisedToN > m)
                    break;
            }

            if (numRaisedToN == m)
                return mid;
            else if (numRaisedToN < m)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main()
{
    Solution obj;
    int result = obj.nthRoot(3, 27);
    return 0;
}