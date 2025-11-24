#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    int answer;

    int i = 0;
    int j = 0;
    int idx = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            ++i;
            if (idx == k)
                answer = a[i];
        }
        else
        {
            ++j;
            if (idx == k)
                answer = b[j];
        }
        ++idx;
    }

    while (i < m)
    {
        ++i;
        ++idx;
        if (idx == k)
            answer = a[i];
    }
    while (j < n)
    {
        ++j;
        ++idx;
        if (idx == k)
            answer = b[j];
    }

    return answer;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}