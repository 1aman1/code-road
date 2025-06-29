#include <numeric>
#include <iostream>

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        std::fill(children, children + 26, nullptr);
        isWord = false;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete children[i];
        }
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
    ~Trie()
    {
        delete root;
    }

    void insert(std::string word)
    {
        TrieNode *currNode = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (currNode->children[index] == nullptr)
                currNode->children[index] = new TrieNode();

            currNode = currNode->children[index];
        }

        currNode->isWord = true;
    }

    bool search(std::string word)
    {
        TrieNode *currNode = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (currNode->children[index] == nullptr)
                return false;

            currNode = currNode->children[index];
        }
        return currNode->isWord;
    }

    bool startsWith(std::string word)
    {
        TrieNode *currNode = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (currNode->children[index] == nullptr)
                return false;

            currNode = currNode->children[index];
        }

        return true;
    }
};

int main()
{
    Trie obj;

    obj.insert("dictionary");

    std::cout << std::boolalpha << obj.search("dictionary") << std::endl;
    std::cout << std::boolalpha << obj.startsWith("d") << std::endl;

    std::cout << std::boolalpha << obj.startsWith("n") << std::endl;

    return 0;
}