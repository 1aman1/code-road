#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1;
        int right = x;
        int ans = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}