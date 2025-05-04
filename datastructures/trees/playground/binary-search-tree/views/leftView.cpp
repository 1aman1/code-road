#include <iostream>
#include <memory>
#include <queue>

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
    void leftView();

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

void Tree::leftView()
{
    queue<Node *> q;
    q.push(m_root.get());

    while (not q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i)
        {
            Node *currElement = q.front();
            q.pop();

            if (i == 0)
            {
                std::cout << currElement->m_data << " ";
            }

            if (currElement->m_left)
                q.push(currElement->m_left.get());
            if (currElement->m_right)
                q.push(currElement->m_right.get());
        }
        std::cout << endl;
    }
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.leftView();

    return 0;
}
