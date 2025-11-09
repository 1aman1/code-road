#include <bits/stdc++.h>

using namespace std;

long long int solve(vector<int> &arr)
{
    int SIZE = arr.size();
    long long int prev = arr[0];
    long long int prev2 = 0;

    for (int i = 1; i < SIZE; i++)
    {
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int long long nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

long long int robStreet(int SIZE, vector<int> &arr)
{
    vector<int> arr1;
    vector<int> arr2;

    if (SIZE == 1)
        return arr[0];

    for (int i = 0; i < SIZE; i++)
    {

        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != SIZE - 1)
            arr2.push_back(arr[i]);
    }

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1, ans2);
}

int main()
{
    vector<int> arr{1, 5, 1, 2, 6};
    const int SIZE = arr.size();
    cout << robStreet(SIZE, arr);
}