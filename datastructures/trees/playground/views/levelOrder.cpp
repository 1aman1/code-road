#include <iostream>
#include <memory>
#include <list>

using namespace std;

struct Node
{
    int m_data;
    unique_ptr<Node> m_left;
    unique_ptr<Node> m_right;

    Node(int val) : m_data(val),
                    m_left(nullptr),
                    m_right(nullptr) {}
};

using NodePtr = unique_ptr<Node>;

class Tree
{
private:
    NodePtr m_root{nullptr};

public:
    void insertNode(int aVal);
    void viewLevelOrder();

private:
    NodePtr insertNodeHelper(NodePtr aCurrNode, int aVal);
};

void Tree::insertNode(int aVal)
{
    m_root = insertNodeHelper(std::move(m_root), aVal);
}

NodePtr Tree::insertNodeHelper(NodePtr currNode, int aVal)
{
    if (!currNode)
    {
        return make_unique<Node>(aVal);
    }
    else
    {
        if (aVal < currNode->m_data)
        {
            currNode->m_left = insertNodeHelper(std::move(currNode->m_left), aVal);
        }
        else
        {
            currNode->m_right = insertNodeHelper(std::move(currNode->m_right), aVal);
        }
    }

    return currNode;
}

void Tree::viewLevelOrder()
{
    if (!m_root)
        return;

    using NodeList = list<Node *>;

    NodeList currLevel{m_root.get()};

    while (!currLevel.empty())
    {
        NodeList nextLevel;

        for (const auto &node : currLevel)
        {
            cout << node->m_data << " ";

            if (node->m_left)
                nextLevel.push_back(node->m_left.get());

            if (node->m_right)
                nextLevel.push_back(node->m_right.get());
        }
        cout << endl;

        currLevel.swap(nextLevel);
    }
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.viewLevelOrder();

    return 0;
}
