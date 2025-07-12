#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

void generatePalindromes(std::string s)
{
    std::unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    int oddCount = 0;
    char oddChar;
    std::string half = "";

    for (auto &[c, count] : freq)
    {
        if (count % 2 != 0)
        {
            oddCount++;
            oddChar = c;
        }
        half += std::string(count / 2, c);
    }

    if (oddCount > 1)
    {
        std::cout << "No palindromic permutations possible\n";
        return;
    }

    std::sort(half.begin(), half.end());

    std::vector<std::string> results;
    do
    {
        std::string reversed = half;
        std::reverse(reversed.begin(), reversed.end());
        std::string fullPalindrome = half + (oddCount == 1 ? std::string(1, oddChar) : "") + reversed;
        results.push_back(fullPalindrome);

    } while (std::next_permutation(half.begin(), half.end()));

    for (const auto &p : results)
        std::cout << p << "\n";
}

int main()
{
    std::string s = "ababaa";
    generatePalindromes(s);
    return 0;
}
