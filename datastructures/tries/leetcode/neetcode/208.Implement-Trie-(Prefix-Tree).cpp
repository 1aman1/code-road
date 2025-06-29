#include <iostream>
#include <memory>
#include <array>

class TrieNode
{
public:
    std::array<std::unique_ptr<TrieNode>, 26> children;
    bool isWord;

    TrieNode() : isWord(false) {}
};

class Trie
{
    std::unique_ptr<TrieNode> root;

public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string &word)
    {
        TrieNode *currNode = root.get();

        for (char ch : word)
        {
            int index = ch - 'a';
            if (!currNode->children[index])
            {
                currNode->children[index] = std::make_unique<TrieNode>();
            }
            currNode = currNode->children[index].get();
        }

        currNode->isWord = true;
    }

    bool search(const std::string &word) const
    {
        const TrieNode *currNode = root.get();

        for (char ch : word)
        {
            int index = ch - 'a';
            if (!currNode->children[index])
                return false;

            currNode = currNode->children[index].get();
        }

        return currNode->isWord;
    }

    bool startsWith(const std::string &prefix) const
    {
        const TrieNode *currNode = root.get();

        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!currNode->children[index])
                return false;

            currNode = currNode->children[index].get();
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
