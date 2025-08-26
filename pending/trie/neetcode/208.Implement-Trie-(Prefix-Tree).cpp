#include <numeric>
#include <iostream>

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode() : isWord(false)
    {
        std::fill(children, children + 26, nullptr);
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word)
    {
        TrieNode *itr = root;

        for (const auto &e : word)
        {
            int letter = e - 'a';
            if (itr->children[letter] == nullptr)
            {
                itr->children[letter] = new TrieNode();
            }

            itr = itr->children[letter];
        }

        itr->isWord = true;
    }

    bool search(std::string word)
    {
        TrieNode *itr = root;
        for (const auto &e : word)
        {
            int letter = e - 'a';
            if (itr->children[letter] == nullptr)
            {
                return false;
            }

            itr = itr->children[letter];
        }
        return itr->isWord;
    }

    bool startsWith(std::string word)
    {
        TrieNode *itr = root;

        for (const auto &e : word)
        {
            int letter = e - 'a';
            if (itr->children[letter] == nullptr)
                return false;

            itr = itr->children[letter];
        }

        return true;
    }
};

int main()
{
    Trie obj;

    obj.insert("dictionary");

    std::cout << std::boolalpha << obj.search("dictionary") << std::endl;
    std::cout << std::boolalpha << obj.startsWith("dictio") << std::endl;

    std::cout << std::boolalpha << obj.startsWith("n") << std::endl;

    return 0;
}