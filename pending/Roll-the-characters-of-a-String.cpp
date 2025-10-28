#include <bits/stdc++.h>
using namespace std;

void captureRolls(const vector<int> &roll, vector<int> &charFreq, const int &SIZE)
{
    for (const auto eachRoll : roll)
    {
        charFreq[0] += 1;
        if (eachRoll < SIZE)
            charFreq[eachRoll] -= 1;
    }
}

string rollString(string str, vector<int> &roll)
{
    if (roll.empty())
        return str;

    const int SIZE = str.size();

    vector<int> charFreq(SIZE + 1, 0);

    captureRolls(roll, charFreq, SIZE);

    //---preparePrefix
    for (int i = 1; i < SIZE; ++i)
        charFreq[i] += charFreq[i - 1];

    //---propagatePrefix
    for (int i = 0; i < SIZE; ++i)
    {
        int rollCount = charFreq[i] % 26;
        str[i] = (((str[i] - 'a') + rollCount) % 26) + 'a';
    }

    return str;
}

int main()
{
    string str = "bca";
    vector<int> roll = {1, 2, 3};
    cout << rollString(str, roll) << endl; // Output: eeb
    return 0;
}
